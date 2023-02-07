#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) ((a)>(b)?(a):(b))

#include "avl.h"

/////////////////////////////////////
// PARTIE AVL
/////////////////////////////////////

Arbre_AVL_t lire_arbre (char *nom_fichier)
{
  FILE *f ;
  int cle;
  Arbre_AVL_t a = NULL;
  
  f = fopen (nom_fichier, "r") ;

  while (fscanf (f, "%d", &cle) != EOF)
    {
      a =  ajouter_cle_arbre_AVL(a, cle) ;
      afficher_arbre(a,0) ;
      printf("--------------------\n");
    }
    
  fclose (f) ;

  return a ;
}

void afficher_arbre (Arbre_AVL_t a, int niveau)
{
  /*
    affichage de l'arbre a
    on l'affiche en le penchant sur sa gauche
    la partie droite (haute) se retrouve en l'air
  */
  
  int i ;
  
  if (a != NULL)
      {
	afficher_arbre (a->fdroite,niveau+1) ;
	
	for (i = 0; i < niveau; i++)
	  printf ("\t") ;
	printf (" %d (%d)\n\n", a->cle, niveau) ;

	afficher_arbre (a->fgauche, niveau+1) ;
      }
  return ;
}

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
  if (a->bal == 2){
    if (a->fdroite->bal >= 0)
      return rotation_gauche(a);
    else
    {
      return double_rotation_gauche(a);
    }
   }else if (a->bal == -2){
    if (a->fgauche->bal <= 0)
      return rotation_droite(a);
    else
    {
        return double_rotation_droite(a);
    }
   } else
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

Arbre_AVL_t supprimer_cle_arbre_AVL (Arbre_AVL_t a, int cle){
    return NULL;
}

Arbre_AVL_t rotation_gauche(Arbre_AVL_t a){
    return NULL;
}

Arbre_AVL_t rotation_droite(Arbre_AVL_t a) {
  Arbre_AVL_t temp;

  if (a->fgauche->fdroite == NULL) { //Cas ou B a pas de fils droit
    if (a->fdroite == NULL) { //Cas ou B n'a pas de fils droit et A en a un

    } else { //A et B n'ont pas de fils droit et de fils gauche

    }
  } else {
    if (a->fdroite == NULL) { //Cas ou A a pas de fils droit

    } else { //A et B on tout les deux un fils droit
      temp = a->fgauche;
      a->fgauche = a->fgauche->fdroite;
      temp->fdroite = a;
    }
  }

  return temp;
}

Arbre_AVL_t double_rotation_gauche(Arbre_AVL_t a) {
    a->fdroite = rotation_droite(a->fdroite);
    return rotation_gauche(a);
}

Arbre_AVL_t double_rotation_droite(Arbre_AVL_t a) {
      a->fgauche = rotation_gauche(a->fgauche);
      return rotation_droite(a);
}

Arbre_AVL_t getFather(Arbre_AVL_t a,Arbre_AVL_t son){

  if (a == son ){
    return NULL;
  } else if (a==NULL) {
    return NULL;
  } else {
    if (a->fdroite == son || a->fgauche == son) return a;

    if (son->cle < a->cle) return getFather(a->fgauche,son);
    if (son->cle > a->cle) return getFather(a->fgauche,son);

    return NULL;

  }
}

void update_balance(Arbre_AVL_t a){
    if (a != NULL){
        a->bal = hauteur_arbre_AVL(a->fdroite) - hauteur_arbre_AVL(a->fgauche);
        update_balance(a->fgauche);
        update_balance(a->fdroite);
    }
}