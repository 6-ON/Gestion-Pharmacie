#ifndef MENU_UTILS_H
#define MENU_UTILS_H

#ifdef __unix__
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif

#define PROMPT_MARK ">> "

//MAIN MENU CHOIICES
#define CH_RTEOUR_MENU 0
#define CH_AJOUTER 1
#define CH_LISTER_PRD 2
#define CH_ACHETER 3
#define CH_SEARCH 4
#define CH_ESTOCK 5
#define CH_AL_STOCK 6
#define CH_SUPP_PROD 7
#define CH_ST_VNT 8
#define CH_QUITTER 9

//MENU LIST PRODUCTS
#define CH_ORDER_BY_NAME_ASC 1
#define CH_ORDER_BY_PRICE_DESC 2

//MENU LIST PRODUCTS
#define CH_SRCH_CODE 1
#define CH_SRCH_QTTY 2

// main menu options STRS
#define AJOUTER "1. Ajouter nouveau produits"
#define LISTER_PRD "2. Lister tous les produit" // Par prix et Nom
#define ACHETER "3. Acheter produit"
#define SEARCH "4. Rechercher les produits"  // par code et quantite
#define ESTOCK "5. Afficher l'etat du stock" // low quantity
#define ALSTOCK "6. ALimenter le stock" // low quantity
#define SUPP_PROD "7. Supprimer Produit"
#define ST_VNT "8. Statistique de vente" // min max avg total
#define QUITTER "9.Quitter"
#define RETOUR_MENU "<-- 0"

//MENU LIST PRODUCTS
#define NOM_ASC "1.Lister Par Nom Croissant"
#define PRIX_DESC "2.Lister Par prix Decroissant"              

//menu search Products
#define SRCH_CD "1. Rechercher par code"
#define SRCH_QTTY "2.Rechercher Par Quantite"              

//ERRNOS
#define WRONG_INPUT 0

//prompts
#define PROMPT_NPRODUCTS "enter le nombre des produit a ajouter : "

#define PROMPT_PRODUCT_NAME "Entrer le Nom de produit : "
#define PROMPT_PRODUCT_CODE "Entrer le code de produit : "

#define PROMPT_PRODUCT_PRICE "Entrer le Prix de produit : "
#define PROMPT_QTTY "Entrer la quantite de produit : "
#define PROMPT_QTTY_CNSM "Entrer la quantite a acheter : "
#define PROMPT_QTTY_ADD "Entrer la quantite a ajouter : "


// errors messages
#define ERR_WRONG_INPUT "erreur l\'entree incorrect"
#define ERR_NEGATIVE_PRICE "eurreur prix negative ! "
#define ERR_NEGATIVE_QTTY "eurreur quantite negative ! "
#define ERR_OUT_OF_RANGE "error out of range !!"
#define ERR_PRD_NOT_FOUND "PRODUIT INTROUVABLE!!"
#define ERR_STOCK "Le stock est insuffisant!!"
#define WA_LOW_QTTY "Avertissement:La QUANTITÉ FAIBLE !!"

//info messages
#define PRODUCT_ADDED "PRODUIT BIEN AJOUTEE"
#define PRODUCT_PRCD "PRODUIT BIEN ACHETER"
#define PRODUCT_DEL "PRODUIT BIEN SUPPRIMEE"
#define QUANTITY_ADDED "QUANTITE BIEN AJOUTEE"
#define QUIT_MESSAGE "en cours de quiter..."
#endif