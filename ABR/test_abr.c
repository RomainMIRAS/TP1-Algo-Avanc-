#include <stdio.h>
#include <stdlib.h>

#include "abr.h"

int main (int argc, char**argv)
{
  Arbre_t a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  
  afficher_arbre (a,0) ;

  /*
     appeler les fonctions que vous
     avez implementees
  */

 // Test parcours largeur

   printf("----------------\n");

  printf("TEST PARCOURS LARGEUR\n");
  parcourir_arbre_largeur(a);
 // Test Hauteur

  printf("----------------\n");

  printf("TEST HAUTEUR\n");
  printf("La hauteur rec de l'arbre est : %d\n", hauteur_arbre_r(a));
  printf("La hauteur it de l'arbre est : %d\n", hauteur_arbre_nr(a));

    printf("----------------\n");
    
    printf("TEST NB CLEF\n");
    printf("Le nombre de clef rec de l'arbre est : %d\n", nombre_cles_arbre_r(a));
    printf("Le nombre de clef it de l'arbre est : %d\n", nombre_cles_arbre_nr(a));

    printf("----------------\n");

    printf("TEST CLEF TRIE REC\n");
    imprimer_liste_cle_triee_r(a);

    printf("----------------\n");

    printf("TEST CLEF TRIE ITE\n");
    imprimer_liste_cle_triee_nr(a);

    printf("----------------\n");

    printf("TEST NB NOEUD A UNE CERTAINE HAUTEUR\n");
    afficher_nombre_noeuds_par_niveau(a);

    printf("----------------\n");

    printf("TEST ARBRE PLEIN\n");
    printf("L'arbre est parfait ? : %s\n", (arbre_plein(a) == 1 ) ? "VRAI":"FAUX");

    printf("----------------\n");

    printf("TEST ARBRE PARFAIT\n");
    printf("L'arbre est parfait ? : %s\n", (arbre_parfait(a) == 1 ) ? "VRAI":"FAUX");

    printf("----------------\n");

    printf("TEST PERE DU MINIMUM\n");
    int min = trouver_cle_min(a);
    printf("NOEUX du noeux minimim %d: %d\n", min,getFather(a,searchABR(a,min))->cle);

    printf("----------------\n");

    printf("TEST RECH CLEF SUPP AU MIN\n");
    Arbre_t clef_supp = rechercher_cle_sup_arbre(a,min);
    printf("Clef Suppérieur à %d: %d\n", min,(clef_supp != NULL) ? clef_supp->cle:0);

    printf("----------------\n");

}
