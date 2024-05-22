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
*  Nom du fichier : verif.c                                                   *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "global-var.h"

//Renvoie un FALSE si contient des caracteres non alphanumeriques, sinon TRUE
int verif(char message[]){
	int res = 0;
	int taille = strlen(message);
    for (int i=0; i<taille; i++){
        if (strchr(rosette,message[i])) {
			res++;
        }
    }
    return res == taille;
}
