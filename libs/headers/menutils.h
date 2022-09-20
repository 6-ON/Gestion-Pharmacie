#ifndef MENU_UTILS_H
#define MENU_UTILS_H

#ifdef __unix__
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif

#define N_CHOICES 8

#define CH_AJOUTER 1
#define CH_LISTER_PRD 2
#define CH_ACHETER 3
#define CH_SEARCH 4
#define CH_ESTOCK 5
#define CH_SUPP_PROD 6
#define CH_ST_VNT 7
#define CH_QUITTER 8

// menu options
#define AJOUTER "1. Ajouter nouveau produits"
#define LISTER_PRD "2. Lister tous les produit" // Par prix et Nom
#define ACHETER "3. Acheter produit"
#define SEARCH "4. Rechercher les produits"  // par code et quantite
#define ESTOCK "5. Afficher l'etat du stock" // low quantity
#define SUPP_PROD "6. Supprimer Produit"
#define ST_VNT "7. Statistique de vente" // min max avg total
#define QUITTER "8.Quitter"              // min max avg total

//ERRNOS
#define WRONG_INPUT 0

//prompts
#define PROMPT_NPRODUCTS "enter le nombre des produit a ajouter : "

#define PROMPT_PRODUCT_NAME "Entrer le Nom de produit : "

#define PROMPT_PRODUCT_PRICE "Entrer le Prix de produit : "
#define PROMPT_QTTY "Entrer la quantite de produit : "


// errors messages
#define ERR_WRONG_INPUT "Entree incorrect"
#define ERR_NEGATIVE_PRICE "eurreur prix negative ! "
#define ERR_NEGATIVE_QTTY "eurreur quantite negative ! "

//info messages
#define PRODUCT_ADDED "PRODUIT BIEN AJOUTEE"
#define QUIT_MESSAGE "en cours de quiter..."
#endif