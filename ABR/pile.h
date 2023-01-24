
#define MAX_PILE_SIZE       32
#ifndef __ABR_H__
  #define __ABR_H__
  #include "abr.h"
#endif



typedef struct {
  int sommet ;
  pnoeud_t Tab [MAX_PILE_SIZE] ;
} pile_t, *ppile_t ;

ppile_t creer_pile () ;

int detruire_pile (ppile_t p) ;

int pile_vide (ppile_t p) ;

int pile_pleine (ppile_t p) ;

pnoeud_t depiler (ppile_t p)  ;

int empiler (ppile_t p, pnoeud_t pn) ;
