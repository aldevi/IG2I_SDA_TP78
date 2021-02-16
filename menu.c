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

void remove()