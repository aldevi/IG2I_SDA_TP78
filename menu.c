#include "menu.h"
#include "biblio.h"
#include "livre.h"
#include "date.h"
#include <string.h>
#include <stdio.h>

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