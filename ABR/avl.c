#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pile.h"
#include "file.h"
#include "avl.h"

/////////////////////////////////////
// PARTIE AVL
/////////////////////////////////////

Arbre_AVL_t equilibrer_arbre(Arbre_AVL_t a)
{
  if (a->bal == 2)
    if (a->fdroite->bal >= 0)
      return rotation_gauche(a);
    else
    {
      a->fdroite = rotation_droite(a->fdroite);
      return rotation_gauche(a);
    }
  else if (a->bal == -2)
    if (a->fgauche->bal <= 0)
      return rotation_droite(a);
    else
    {
      a->fgauche = rotation_gauche(a->fgauche);
      return rotation_droite(a);
    }
  else
    return a;
}

Arbre_AVL_t ajouter_cle_arbre_AVL (Arbre_AVL_t a, int cle){
  if (a == NULL){
    a = (Arbre_AVL_t) malloc (sizeof(noeud_AVL)) ;
      a->cle = cle;
      a->fgauche = NULL ;
      a->fdroite = NULL ;
      a->bal = 0;
  } else {
    if (cle < a->cle){
      a->fgauche = ajouter_cle_arbre_AVL(a->fgauche,cle);
    } else {
      a->fdroite = ajouter_cle_arbre_AVL(a->fdroite,cle);
    }
  }
  a->bal = hauteur(a->fdroite) - hauteur(a->fgauche);
  return equilibrer_arbre(a);
}