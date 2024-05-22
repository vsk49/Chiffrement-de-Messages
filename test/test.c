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
*  Nom du fichier : test.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "./../include/chiffrement.h"
#include "./../include/global-var.h"
#include "./../include/verif.h"
#include "./../include/affichage.h"

// variable pour les catégorie et sous catégorie
int cat = 0;
int scat = 0;

// fonctione pour faciliter l'affichage et le teste des regle
void test(char nom[]){
	cat++;
	scat = 0;
	printf("[ %s%sTEST%s ] %s\n", BLUE, GRAS, NOCOLOR, nom);
}
void regle(int res){
	scat++;
	if (res){
		printf("\t- P%d.%d\t[%sOK%s]\n", cat, scat, GREEN, NOCOLOR);
	}else{
		printf("\t- P%d.%d\t[%sKO%s]\n", cat, scat, RED, NOCOLOR);
	}
}

int main(){

	test("verif");

	// verifie si la fonction verif detecte bien les majuscules, minuscules et nombre et rien d'autre
	regle(verif("a"));
	regle(verif("Z"));
	regle(verif("7"));
	regle(!verif("§"));
	regle(!verif("\n"));

	test("convertion");

	// verifie si décalage normalle ce fait bien
	regle(strcmp(chiffrer(1, "A"), "B") == 0);
	// verifie si le décalage des chiffre vers maj vers min ce fait bien
	regle(strcmp(chiffrer(1, "9"), "A") == 0);
	regle(strcmp(chiffrer(1, "Z"), "a") == 0);
	// verifie si le décalage jusqu'au debut ce fait bien
	regle(strcmp(chiffrer(1, "z"), " ") == 0);
	regle(strcmp(chiffrer(1, " "), "0") == 0);
	// verifie si le cas de la clé supérieur au nombre de possibilié est bien pris en compte
	regle(strcmp(chiffrer(l_ros + 1, "6"), "7") == 0);

	test("chiffrer");

	// verifie certain exemple
	regle(strcmp(chiffrer(5, "Message"), "Rjxxflj") == 0);
	regle(strcmp(chiffrer(7, "JE SUIS UN HOMME EN COLERE"), "QL6ZbPZ6bU6OVTTL6LU6JVSLYL") == 0);

	test("dechiffrer");

	// verifie certain exemple
	regle(strcmp(dechiffrer(5, "Rjxxflj"), "Message") == 0);
	regle(strcmp(dechiffrer(7, "QL6ZbPZ6bU6OVTTL6LU6JVSLYL"), "JE SUIS UN HOMME EN COLERE") == 0);
	
	return 0;
}
