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
*  Nom du fichier : chiffrement.c                                             *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "chiffrement.h"
#include "global-var.h"

// encode/decode le message a partir d'une table ascii personnalisée
// en parametre sont passés la clée d'encodage, le message sous forme de pointeur
// et la taille du message.
// char * convertion(int clee, char message[]){
char * chiffrer(int clee, char message[]){
	// on module la clee par le nombre de caractere possible car on peut pas decaller au dessus de caractere qui n'existe pas
	//if (clee < 0){
	//	clee %= -l_ros;
	//}else{
		clee %= l_ros;
	//}

	char* code = malloc(strlen(message));
	int index;
	char* ptr;

	// boucle de décallage caractere par caractere
	// influencé par le signe de la clée (positif chiffrement, négatif dechiffrement)
	for (int i=0; i<strlen(message); i++){
		ptr = strchr(rosette, message[i]);
		if(ptr) {
		   index = ptr - rosette;
		}

		code[i] = rosette[ (index + clee) % l_ros ];
	}
	return code;
}

// la fonction chiffrer et déchiffrer son appelée mais redirige vers
// convertion. Le but est de changer le signe de la clée pour signifier
// le chiffrement ou le déchiffrement. (positif chiffrement, négatif dechiffrement)
// char * chiffrer(int clee, char message[]){
// 	return convertion(clee, message);
// };

char * dechiffrer(int clee, char message[]){
	return chiffrer(-clee, message);
};
