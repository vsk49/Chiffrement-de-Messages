/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : PROJET 3                                                     *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Variable globale                                                *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : BOUDIN Raphael                                               *
*                                                                             *
*  Nom-prénom2 : LFARH Mouataz                                                *
*                                                                             *
*  Nom-prénom3 : LONGUET Cédric                                               *
*                                                                             *
*  Nom-prénom4 : NANAHA Hamza                                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : global-var.h                                              *
*                                                                             *
******************************************************************************/

#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

// On pourrait techniquement prendre les caracteres spéciaux de la table ASCII et les inclure dedans
// Pierre de rosette, tout ce qui est contenu dedans (en ASCII) est encodable/decodable
static const char rosette[] = " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const int l_ros = 63;

// Ajoute de la couleur au terminal, fonctionne nativement sur linux mais pas sur windows
#ifndef _WIN32
static const char GRAS[] = "\033[1m";
static const char RED[] = "\033[31m";
static const char GREEN[] = "\033[32m";
static const char BLUE[] = "\033[34m";
static const char NOCOLOR[] = "\033[0m";
#else
static const char GRAS[] = "";
static const char RED[] = "";
static const char GREEN[] = "";
static const char BLUE[] = "";
static const char NOCOLOR[] = "";
#endif

#endif //GLOBAL_VAR_H
