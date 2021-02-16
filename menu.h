#ifndef MENU_H
#define MENU_H

#include "biblio.h"

int searchBook(T_Bibliotheque *biblio);
void searchAuthor(T_Bibliotheque *ptrB);
void removeBook(T_Bibliotheque *ptrB);
int borrowBook(T_Bibliotheque *biblio);
#endif