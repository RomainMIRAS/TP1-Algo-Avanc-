#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main (int argc, char**argv)
{
Arbre_AVL_t a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  
  afficher_arbre (a,0) ;

  printf(" DESTRUCTION DU FILS GAUCHE DE LA RACINE");
  a->fgauche = detruire_cle_arbre_avl(a->fgauche, 2);
  afficher_arbre (a,0) ;
}
