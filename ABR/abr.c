#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pile.h"
#include "file.h"

#define max(a,b) ((a)>(b)?(a):(b))


int feuille (Arbre_t a)
{
  if (a == NULL)
    return 0 ;
  else
    {
      if ((a->fgauche == NULL) && (a->fdroite == NULL))
	return 1 ;
      else
	return 0 ;
    }
}

Arbre_t ajouter_noeud (Arbre_t a, Arbre_t n)
{
  /* ajouter le noeud n dans l'arbre a */
  
  if (a == NULL)
    return n ;
  else if (n->cle < a->cle)
	a->fgauche = ajouter_noeud (a->fgauche, n) ;
  else
	a->fdroite = ajouter_noeud (a->fdroite, n) ;
  return a ;
  
}  

Arbre_t rechercher_cle_arbre (Arbre_t a, int valeur)
{
  if (a == NULL)
    return NULL ;
  else
    {
      if (a->cle == valeur)
	return a ;
      else
	{
	  if (a->cle < valeur)
	    return rechercher_cle_arbre (a->fdroite, valeur) ;
	  else
	    return rechercher_cle_arbre (a->fgauche, valeur) ;
	}
    }
}

Arbre_t ajouter_cle (Arbre_t a, int cle)
{
  Arbre_t n ;
  Arbre_t ptrouve ;
  
  /* 
     ajout de la clé. Creation du noeud n qu'on insere 
    dans l'arbre a
  */

  ptrouve = rechercher_cle_arbre (a, cle) ;

  if (ptrouve == NULL)
    {
      n = (Arbre_t) malloc (sizeof(noeud_t)) ;
      n->cle = cle;
      n->fgauche = NULL ;
      n->fdroite = NULL ;

      a = ajouter_noeud (a, n) ;
      return a ;
    }
  else
    return a ;
}


Arbre_t lire_arbre (char *nom_fichier)
{
  FILE *f ;
  int cle;
  Arbre_t a = NULL;
  
  f = fopen (nom_fichier, "r") ;

  while (fscanf (f, "%d", &cle) != EOF)
    {
      a = ajouter_cle (a, cle) ;
    }
    
  fclose (f) ;

  return a ;
}

void afficher_arbre (Arbre_t a, int niveau)
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

int hauteur_arbre_r (Arbre_t a)
{
  if (a == NULL)
    return -1 ;
  else
    return 1 + max (hauteur_arbre_r (a->fgauche), hauteur_arbre_r (a->fdroite)) ;
}

int hauteur_arbre_nr (Arbre_t a)
{
  pfile_t file = creer_file();

  enfiler(file,a);

int hauteur = -1;
int nextLargeur = 0;
int largeur = 1;

  while(!file_vide(file)){
    pnoeud_t noeud = defiler(file);

    if(noeud->fgauche != NULL){
      enfiler(file,noeud->fgauche);
      nextLargeur++;
    }

    if(noeud->fdroite != NULL){
      enfiler(file,noeud->fdroite);
      nextLargeur++;
    }
    largeur--;
    if (largeur == 0) {
      largeur = nextLargeur;
      hauteur++;
      nextLargeur = 0;
    }
  }

  return hauteur;
}

int nbNoeudHauteur(Arbre_t a, int h) {
    if (a == NULL)
      return 0;
    else if (h == 0)
      return 1 ;
    else
      return nbNoeudHauteur (a->fgauche, h-1) + nbNoeudHauteur (a->fdroite, h-1) ;
}

void parcourir_arbre_largeur (Arbre_t a)
{
  // Création de la file
  pfile_t file = creer_file();

  enfiler(file,a);
  while(!file_vide(file)){
    pnoeud_t noeud = defiler(file);
    printf("Noeud %d \n",noeud->cle);

    if(noeud->fgauche != NULL){
      enfiler(file,noeud->fgauche);
    }

    if(noeud->fdroite != NULL){
      enfiler(file,noeud->fdroite);
    }    
  }

  return ;
}

void afficher_nombre_noeuds_par_niveau (Arbre_t a)
{
  /*
    a completer
  */

  return ;
}


int nombre_cles_arbre_r (Arbre_t a)
{
  if (a == NULL)
    return 0 ;
  else
    return 1 + nombre_cles_arbre_r (a->fgauche) + nombre_cles_arbre_r (a->fdroite) ;
}

int nombre_cles_arbre_nr (Arbre_t a)
{

  int nb = 0;
 // Création de la file
  pfile_t file = creer_file();

  enfiler(file,a);
  while(!file_vide(file)){
    pnoeud_t noeud = defiler(file);
    nb++;
    if(noeud->fgauche != NULL){
      enfiler(file,noeud->fgauche);
    }

    if(noeud->fdroite != NULL){
      enfiler(file,noeud->fdroite);
    }    
  }

  return nb;
}

int trouver_cle_min (Arbre_t a)
{
  Arbre_t current = a;
  while(current->fgauche != NULL){
    current = current->fgauche;
  }
  return current->cle;
}

 

void imprimer_liste_cle_triee_r (Arbre_t a)
{
  if (a == NULL) return;
  if (a->fdroite == NULL && a->fgauche == NULL){
    printf("Clef %d \n",a->cle);
  } else {
    imprimer_liste_cle_triee_r(a->fgauche);
    printf("Clef %d \n",a->cle);
    imprimer_liste_cle_triee_r(a->fdroite);
  }
}

void imprimer_liste_cle_triee_nr (Arbre_t a)
{
  /*
    a completer
  */

  return ;
}


int arbre_plein (Arbre_t a)
{
  // IMPLEMENTATION 1
  // if (a == NULL) return 1;

  // if (hauteur_arbre_r(a->fgauche) == hauteur_arbre_r(a->fdroite)){
  //   return arbre_plein(a->fdroite) && arbre_plein(a->fgauche);
  // } else {
  //   return -1;
  // }

  // IMPLEMENTATION 2
  int hauteur = hauteur_arbre_r(a);
  int nombre_noeuds = nombre_cles_arbre_r(a);
  return (nombre_noeuds == (pow(2,hauteur+1)-1));
}

int arbre_parfait (Arbre_t a)
{
  int hauteur = hauteur_arbre_r(a);
  for (int i = 0; i < hauteur; i++) {
    if (pow(2, i) != nbNoeudHauteur(a, i)) {
      return -1;
    }
  }
  return 1;

}



//TODO
Arbre_t rechercher_cle_sup_arbre (Arbre_t a, int valeur)
{
   Arbre_t current = a;
  //  if(current->cle > valeur) return current;

   while(current != NULL){
    if(current->cle <= valeur){
        current = current->fdroite;
    } else {
      return getFather(a,current);
    }
   }
   return current;
}

//TODO
Arbre_t rechercher_cle_inf_arbre (Arbre_t a, int valeur)
{
      Arbre_t current = a;
  //  if(current->cle < valeur) return current;

   while(!estFeuille(current)){
    if(current->cle >= valeur){
      if(current->fgauche != NULL){
        current = current->fgauche;
      } else {
        break;
      }
    } else {
      return getFather(a,current);
    }
   }
   return (current->cle<valeur) ? current:NULL;

}

int estFeuille(Arbre_t a){
  return a->fdroite== NULL && a->fgauche == NULL;
}

Arbre_t searchABR(Arbre_t a, int clef){
  if (estFeuille(a)){
    if (a->cle == clef) return a;
    return NULL;
  } else {
    if (a->cle == clef){
      return a;
    } else {
      Arbre_t fg = searchABR(a->fgauche,clef);
      if (fg == NULL) return searchABR(a->fdroite,clef);
      return fg;
    }
  }
}


Arbre_t detruire_cle_arbre (Arbre_t a, int cle)
{
  //TODO
  return NULL;
}


Arbre_t getFather(Arbre_t a,Arbre_t son){

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

/**
 * INTERSECTION DES CLEFS DES DEUX ARBRES
*/
Arbre_t intersection_deux_arbres (Arbre_t a1, Arbre_t a2)
{
  /*
    a completer
  */

  return NULL ;
}

/**
 * UNION DES CLEFS DES DEUX ARBRES
*/
Arbre_t union_deux_arbres (Arbre_t a1, Arbre_t a2)
{
  /*
    a completer
  */

  return NULL ;
}

