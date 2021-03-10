#include "livre.h"
#include "date.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
}

void afficherLivre(const T_livre *ptrL) {
    afficherChaine("TITRE :", (ptrL->titre));
    afficherChaine("AUTEUR :", (ptrL->auteur ));
    afficherChaine("CODE : ", ptrL->code);
    afficherChaine("EDITEUR : ", ptrL->editeur);
    printf("ANNEE EDITION : %d\n", ptrL->annee);
    if(strcmp(ptrL->emprunteur.nomemprunteur, "") != 0){
        afficherChaine("EMPRUNTEUR :", ptrL->emprunteur.nomemprunteur);
        printf("DATE D'EMPRUNT : %s %d %s %d\n", lejour(ptrL->emprunteur.lejour), ptrL->emprunteur.ledate, lemois(ptrL->emprunteur.lemois), ptrL->emprunteur.lannee);
    }
}