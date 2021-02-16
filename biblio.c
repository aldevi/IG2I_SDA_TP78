# include "biblio.h"

void init (T_Bibliotheque *ptrB){
	ptrB->nbLivres=0;
	// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB){
	if (ptrB->nbLivres<CAPACITE_BIBLIO){
		saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
		lireChaine("Entrez un code :", ptrB->etagere[ptrB->nbLivres].code, K_MaxCode);
		lireChaine("Entrez un editeur :", ptrB->etagere[ptrB->nbLivres].editeur, K_MaxEdit);
		printf("Entrez l'annee d'edition : ");
		scanf("%d", &(ptrB->etagere[ptrB->nbLivres].annee));
		strcpy(ptrB->etagere[ptrB->nbLivres].emprunteur.nomemprunteur, "");
		ptrB->nbLivres++;
		return 1;
	}
	else return 0;
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB){
	int i;
	if(ptrB->nbLivres==0) return 0;
	else {
		printf("--------------------------------------\n");
		for(i=0;i<ptrB->nbLivres;i++) {
			printf("\tEtagere %d\n", i);
			afficherLivre(&(ptrB->etagere[i]));
			printf("--------------------------------------\n");
		}
		return 1;
		}
}





