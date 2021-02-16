#include "menu.h"
#include "biblio.h"
#include "livre.h"
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