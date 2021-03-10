#ifndef MENU_H
#define MENU_H

#include "biblio.h"

int searchBook(T_Bibliotheque *biblio);
int searchAuthor(T_Bibliotheque *ptrB);
int removeBook(T_Bibliotheque *ptrB);
int borrowBook(T_Bibliotheque *biblio);
int returnBook(T_Bibliotheque *biblio);
int sortByAuthor(T_Bibliotheque *ptrB);
int sortByTitle(T_Bibliotheque *ptrB);
int sortByYear(T_Bibliotheque *ptrB);

#endif