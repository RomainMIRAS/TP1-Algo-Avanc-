/* structure noeud presentee en cours */

typedef struct n {
  int cle;
  struct n *fgauche, *fdroite;
} noeud_t, *pnoeud_t ;

/* type Arbre, pointeur vers un noeud */

typedef pnoeud_t Arbre_t;

Arbre_t lire_arbre (char *nom_fichier) ;

int estFeuille(Arbre_t a);

Arbre_t searchABR(Arbre_t a, int clef);

/**
 * PRECONDITION : a != NULL
*/
Arbre_t getFather(Arbre_t a,Arbre_t son);

void afficher_arbre (Arbre_t a, int niveau) ;

int hauteur_arbre_r (Arbre_t a) ;

int hauteur_arbre_nr (Arbre_t a) ;

void parcourir_arbre_largeur (Arbre_t a) ;

int nbNoeudHauteur(Arbre_t a, int h) ;

void afficher_nombre_noeuds_par_niveau (Arbre_t a) ;

int nombre_cles_arbre_r (Arbre_t a) ;

int nombre_cles_arbre_nr (Arbre_t a) ;

int trouver_cle_min (Arbre_t a) ;

void imprimer_liste_cle_triee_r (Arbre_t a) ;

void imprimer_liste_cle_triee_nr (Arbre_t a) ;

int arbre_plein (Arbre_t a) ;

int arbre_parfait (Arbre_t a) ;

int containsKey(Arbre_t a, int valeur);

Arbre_t rechercher_cle_sup_arbre (Arbre_t a, int valeur) ;

Arbre_t rechercher_cle_inf_arbre (Arbre_t a, int valeur) ;

Arbre_t detruire_cle_arbre (Arbre_t a, int cle) ;

Arbre_t intersection_deux_arbres (Arbre_t a1, Arbre_t a2) ;

Arbre_t union_deux_arbres (Arbre_t a1, Arbre_t a2) ;

/////////////////////////////////////
// PARTIE AVL
/////////////////////////////////////

typedef struct noeud_AVL {
int cle ;
int bal ; /* balance comprise entre –1 et +1 */
struct n *fgauche, *fdroite ;
} noeud_AVL ;
typedef noeud_AVL *Arbre_AVL_t ;

void rotation_gauche (Arbre_AVL_t *a) ;

void rotation_droite (Arbre_AVL_t *a) ;

void double_rotation_gauche (Arbre_AVL_t *a) ;

void double_rotation_droite (Arbre_AVL_t *a) ;

void equilibrer_arbre (Arbre_AVL_t *a) ;

void ajouter_cle_arbre_AVL (Arbre_AVL_t *a, int cle) ;

void supprimer_cle_arbre_AVL (Arbre_AVL_t *a, int cle) ;