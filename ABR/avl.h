/////////////////////////////////////
// PARTIE AVL
/////////////////////////////////////

typedef struct noeud_AVL {
int cle ;
int bal ; /* balance comprise entre –1 et +1 */
struct noeud_AVL *fgauche, *fdroite ;
} noeud_AVL ;
typedef noeud_AVL *Arbre_AVL_t ;

Arbre_AVL_t creer_arbre_AVL_vide ();

int hauteur_arbre_AVL(Arbre_AVL_t a) ;

Arbre_AVL_t equilibrer_arbre(Arbre_AVL_t a) ;

Arbre_AVL_t ajouter_cle_arbre_AVL(Arbre_AVL_t a, int cle);

Arbre_AVL_t supprimer_cle_arbre_AVL (Arbre_AVL_t a, int cle);

Arbre_AVL_t rotation_gauche(Arbre_AVL_t a) ;

Arbre_AVL_t rotation_droite(Arbre_AVL_t a) ;

Arbre_AVL_t double_rotation_gauche(Arbre_AVL_t a) ;

Arbre_AVL_t double_rotation_droite(Arbre_AVL_t a) ;

