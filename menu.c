#include "biblio.h"
#include "livre.h"
#include <string.h>

void searchAuthor(T_Bibliotheque *ptrB){
    int i;
    char aut[MAX];
    lireChaine("Auteur : ", aut, MAX);
    for (i=0 ; i<ptrB->nbLivres ; i++){
        if(strcmp(ptrB->etagere[i].auteur, aut) == 0) afficherLivre(&(ptrB->etagere[i]));
    }
}

void removeBook(T_Bibliotheque *ptrB){
    int i;
    int pos = 0;
    char titre[MAX_TITRE];
    lireChaine("Livre : ", titre, MAX_TITRE);
    for(i=0 ; i<ptrB->nbLivres ; i++){
        if(strcmp(ptrB->etagere[i].titre, titre) == 0) {
            pos = i;
        }
    }
    if(pos == 0) printf("Votre livre n'existe pas !\n");
    else {
        while(pos<ptrB->nbLivres){
            strcpy(ptrB->etagere[pos].titre, ptrB->etagere[pos+1].titre);
            strcpy(ptrB->etagere[pos].auteur, ptrB->etagere[pos+1].auteur);
            pos++;
        }
        ptrB->nbLivres--;
    }
}