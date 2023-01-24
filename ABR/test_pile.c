#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

int main (int argc, char**argv)
{

    // Empiler
    ppile_t p = creer_pile();
    pnoeud_t pn = (pnoeud_t) malloc (sizeof (noeud_t));
    pn->cle = 1;
    printf("Empiler: %d\n", pn->cle);
    empiler(p, pn);
    pn = (pnoeud_t) malloc (sizeof (noeud_t));
    pn->cle = 2;
    printf("Empiler: %d\n", pn->cle);
    empiler(p, pn);
    pn = (pnoeud_t) malloc (sizeof (noeud_t));
    pn->cle = 3;
    printf("Empiler: %d\n", pn->cle);
    empiler(p, pn);

    // Depiler
    pn = depiler(p);
    printf("Depiler: %d\n", pn->cle);
    pn = depiler(p);
    printf("Depiler: %d\n", pn->cle);
    pn = depiler(p);
    printf("Depiler: %d\n", pn->cle);

    // Detruire pile
    detruire_pile(p);
    return 0;


}