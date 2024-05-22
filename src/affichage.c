/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : PROJET 3                                                     *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : KOH Virgil Shaun                                             *
*                                                                             *
*  Nom-prénom2 : LFARH Mouataz                                                *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : affichage.c                                               *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "affichage.h"
#include "chiffrement.h"
#include "verif.h"
#include "global-var.h"

// affiche une erreur lors de la détéction de caractère spécial
void erreur(){
	printf("[ %s%sErreur%s ] Caractere spécial détecté\n", GRAS, RED, NOCOLOR);
}

// vide les char entré par l'utilisateur
void clear_input(){
	while ( (getchar()) != '\n' );  
}

// une ligne entrez par l'utilisateur
char * lireLigne(){
	char* msg = NULL;
	size_t taille = 0;

	clear_input();
	getline(&msg, &taille, stdin);

	return msg;
}

// menu de la partie chiffrer
void m_chiffrer();

// menu de la partie dechiffrer
void m_dechiffrer();

// menu de naviguation pour chiffrer ou dechiffrer
int main(){
	printf("[%s1%s] chiffrer un message\n", GREEN, NOCOLOR);
	printf("[%s2%s] dechiffrer un message\n", GREEN, NOCOLOR);
	printf("[%sq%s] quitter\n", RED, NOCOLOR);
	printf("[ %sEntrez votre choix%s ] ", GRAS, NOCOLOR);

	char rep = getchar();
	printf("\n");

	switch (rep){
		case '1':
			m_chiffrer();
			break;
		case '2':
			m_dechiffrer();
			break;
		case 'q':
			printf("vous avez quittez le programme\n");
			break;
		default:
			printf("\n[ %s%sErreur%s ] option inconnu\n\n", GRAS, RED, NOCOLOR);
			main();
	}
	return 0;
}

// menu de la partie chiffrer
void m_chiffrer(){
	printf("Ecrivez votre %smessage%s à chiffrer : \n", GRAS, NOCOLOR);
	char* msg = lireLigne();

	printf("Entrez la %sclée%s :\n", GRAS, NOCOLOR);
	int clee = 0;
	scanf("%d", &clee);
	printf("\n");

	if (verif(msg)){
		erreur();
	}else{
		msg[strlen(msg)-1] = '\0';
		printf("Message chiffrer : %s%s%s%s\n\n", GRAS, BLUE, chiffrer(clee, msg), NOCOLOR);
		getchar();
	}

	main();
}

// menu de la partie dechiffrer
void m_dechiffrer(){
	printf("Ecrivez votre %smessage%s à dechiffrer : \n", GRAS, NOCOLOR);
	char* msg = lireLigne();

	printf("Entrez la %sclée%s :\n", GRAS, NOCOLOR);
	int clee = 0;
	scanf("%d", &clee);
	printf("\n");

	if (verif(msg)){
		erreur();
	}else{
		msg[strlen(msg)-1] = '\0';
		printf("Message dechiffrer : %s%s%s%s\n\n", GRAS, BLUE, dechiffrer(clee, msg), NOCOLOR);
		getchar();
	}

	main();
}
