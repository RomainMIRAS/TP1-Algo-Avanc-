#include <stdio.h>
#include <stdlib.h>

#include "file.h"

int main (int argc, char**argv)
{

    // Enfiler
    pfile_t p = creer_file();

    for (int i = 0; i < 33; i++)
    {
        pnoeud_t pn = (pnoeud_t) malloc (sizeof (noeud_t));
        pn->cle = i;
        int res = enfiler(p, pn);
        if (res == 0) {
            printf("enfiler: %d\n", pn->cle);
        } else if (res == -1){
            printf("enfiler: %d, file pleine\n", pn->cle);
        }
    }


    // defiler

    for (int i = 0; i < 32; i++)
    {
        pnoeud_t pn = defiler(p);
        printf("defiler: %d\n", pn->cle);
    }

    // Detruire pile
    detruire_file(p);
    return 0;


}