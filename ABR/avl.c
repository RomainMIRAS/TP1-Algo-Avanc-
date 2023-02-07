#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) ((a)>(b)?(a):(b))

#include "avl.h"

/////////////////////////////////////
// PARTIE AVL
/////////////////////////////////////

Arbre_AVL_t creer_arbre_AVL_vide (){
    Arbre_AVL_t a = malloc(sizeof(noeud_AVL));
    a->bal = 0;
    a->cle = 0;
    a->fdroite = NULL;
    a->fgauche = NULL;
    return a;
}


int hauteur_arbre_AVL (Arbre_AVL_t a){
    if (a == NULL)
        return -1;
    else
        return 1 + max(hauteur_arbre_AVL(a->fgauche),hauteur_arbre_AVL(a->fdroite));
}

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
  a->bal = hauteur_arbre_AVL(a->fdroite) - hauteur_arbre_AVL(a->fgauche);
  return equilibrer_arbre(a);
}