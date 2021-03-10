#include "menu.h"
#include "biblio.h"
#include "livre.h"
#include "date.h"
#include <string.h>
#include <stdio.h>

void switchBook(T_livre *ptrA, T_livre *ptrB);

int searchBook(T_Bibliotheque *biblio) {
    int books_found = 0;

    char title[MAX_TITRE];
    lireChaine("TITRE :", title, MAX_TITRE );

    for (int i = 0; i < biblio->nbLivres; i++) {
        if (strcmp(title, biblio->etagere[i].titre) == 0) {
            books_found++;
            printf("\nLivre %d :\n", books_found);
            afficherLivre(&biblio->etagere[i]);
        }
    }
    if (books_found > 0) {
        return 1;
    } else {
        return 0;
    }
}

int searchAuthor(T_Bibliotheque *ptrB){
    int i;
    char aut[MAX];
    if(ptrB->nbLivres>0){
        lireChaine("Auteur : ", aut, MAX);
        for (i=0 ; i<ptrB->nbLivres ; i++){
            if(strcmp(ptrB->etagere[i].auteur, aut) == 0) afficherLivre(&(ptrB->etagere[i]));
        }
        return 1;
    }
    else return 0;
}

int removeBook(T_Bibliotheque *ptrB){
    int i;
    int pos = 0;
    char titre[MAX_TITRE];
    if(ptrB->nbLivres > 0){
        lireChaine("Livre : ", titre, MAX_TITRE);
        for(i=0 ; i<ptrB->nbLivres ; i++){
            if(strcmp(ptrB->etagere[i].titre, titre) == 0) {
                pos = i;
            }
        }
        while(pos<ptrB->nbLivres){
            strcpy(ptrB->etagere[pos].titre, ptrB->etagere[pos+1].titre);
            strcpy(ptrB->etagere[pos].auteur, ptrB->etagere[pos+1].auteur);
            pos++;
        }
        ptrB->nbLivres--;
        return 1;
    }
    else return 0;
}

int borrowBook(T_Bibliotheque *biblio) {
    char code[MAX_CODE];
    char emp_name[MAX];

    lireChaine(code, "CODE : ", MAX_CODE);
    lireChaine(emp_name, "EMPRUNTEUR : ", MAX);

    int i = 0;
    while (i < biblio->nbLivres && (strcmp(code, biblio->etagere[i].code) == 0)) {
        i++;
    }

    if (strcmp(biblio->etagere[i].code, code)) {
        return 0;
    }

    strcpy(biblio->etagere[i].emprunteur.nomemprunteur, emp_name);
    lireDateSysteme(&biblio->etagere[i].emprunteur);

    return 1;
}

int sortByTitle(T_Bibliotheque *ptrB){
    if(ptrB->nbLivres > 0){
        int i;
        int j;
        int ref;
        for(i=0 ; i <= ptrB->nbLivres ; i++){
            ref = i;
            for(j=i+1 ; j < ptrB->nbLivres ; j++) if(strcmp(ptrB->etagere[j].titre, ptrB->etagere[ref].titre) < 0) ref=j;
            if(ref != i) switchBook(&(ptrB->etagere[i]), &(ptrB->etagere[ref]));
        }
        return 1;
    }
    else return 0;
}

int sortByAuthor(T_Bibliotheque *ptrB){
    if(ptrB->nbLivres > 0){
        int i;
        int j;
        int ref;
        for(i=0 ; i <= ptrB->nbLivres ; i++){
            ref = i;
            for(j=i+1 ; j < ptrB->nbLivres ; j++) if(strcmp(ptrB->etagere[j].auteur, ptrB->etagere[ref].auteur) < 0) ref=j;
            if(ref != i) switchBook(&(ptrB->etagere[i]), &(ptrB->etagere[ref]));
        }
        return 1;
    }
    else return 0;
}

int sortByYear(T_Bibliotheque *ptrB){
    if(ptrB->nbLivres > 0){
        int i;
        int j;
        int ref;
        for (i=0 ; i <= ptrB->nbLivres ; i++){
            ref = i;
            for (j=i+1 ; j < ptrB->nbLivres ; j++) if (ptrB->etagere[j].annee < ptrB->etagere[ref].annee) ref=j;
            if (ref != i) switchBook(&(ptrB->etagere[i]), &(ptrB->etagere[ref]));
        }
        return 1;
    }
    else return 0;
}

void switchBook(T_livre *ptrA, T_livre *ptrB){
    int iaux;
    char caux[500];

    //On echange les codes
    strcpy(caux, ptrA->code);
    strcpy(ptrA->code, ptrB->code);
    strcpy(ptrB->code, caux);
    
    //On echange les titres
    strcpy(caux, ptrA->titre);
    strcpy(ptrA->titre, ptrB->titre);
    strcpy(ptrB->titre, caux);

    //On echange les auteurs
    strcpy(caux, ptrA->auteur);
    strcpy(ptrA->auteur, ptrB->auteur);
    strcpy(ptrB->auteur, caux);

    //On echange les editeurs
    strcpy(caux, ptrA->editeur);
    strcpy(ptrA->editeur, ptrB->editeur);
    strcpy(ptrB->editeur, caux);

    //On echange les dates
    iaux = ptrA->annee;
    ptrA->annee = ptrB->annee;
    ptrB->annee = iaux;

    //On echange les emprunteurs
    //On echange les noms des emprunteurs
    strcpy(caux, ptrA->emprunteur.nomemprunteur);
    strcpy(ptrA->emprunteur.nomemprunteur, ptrB->emprunteur.nomemprunteur);
    strcpy(ptrA->emprunteur.nomemprunteur, caux);

    //On echange le jour

    //On echange la date

    //On echange le mois

    //On echange l'annee
}