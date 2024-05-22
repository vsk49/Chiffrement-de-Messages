# MINI PROJET C

## Sujet 3 : Chiffrement de messages en César

### Equipe

Groupe : A


KOH Virgil Shaun

LFARH Mouataz

### Code source

Lien gitlab :

https://gitlab.info.iut-tlse3.fr/nnh4810a/mini-projet-c

### Fonctionnement

Le fonctionnement du code est assez simple. Il prend en entrée une chaîne de caractères et une clé. Ensuite, une boucle va traverser cette chaîne et remplacer chaque caractère par la valeur de la variable qui contient toutes les valeurs disponibles (0-9, a-z, A-Z) à l'index clé modulo le nombre de caractères que possède cette variable.

On fait passer la clé au modulo du nombre de caractères valables, car si la clé est plus grande, le décalage va sortir de la plage des valeurs possibles. Si l'index dépasse la taille du tableau, on calcule sa différence avec l'index du dernier élément, et cette différence devient le nouvel index, ce qui a pour effet de revenir au début du tableau.

Mais bien sûr, avant cela, on vérifie que le message à chiffrer ne contient pas de caractères interdits. Pour cela, on traverse le message en vérifiant chaque caractère pour s'assurer qu'il existe bien dans le tableau avec toutes les possibilités. S'il y a un caractère qui n'est pas dans ce tableau, une erreur se produit.

De plus, nous avons codé une interface avec l'utilisateur pour qu'il puisse choisir de chiffrer ou déchiffrer un message, entrer la clé et afficher le résultat.
Nous avons également ajouté quelques tests pour nous assurer que notre programme fonctionne comme nous le souhaitons. Ces fonctions de test sont présentes dans test/test.c

### Structure

Notre code est structuré par catégories, chaque catégorie possede son dossier :

- src :
    + contenant les fichiers source finissant par .c
- build :
    + contenant les fichiers intermediaire a la compilation (fichier objet) et les executables
- include :
    + contenant les fichiers d'entete au fichier source, finissent par .h
- test :
    + contenant un fichier de test qui verifie le bon fonctionnement des fonctions

### Makefile

Notre Makefile comporte quelques commandes utiles en plus de la compilation du code, les voici :

##### make all, make main, make

Il y a plusieurs façons de compiler notre code :
- make all
- make main
- make

Ces 3 commandes executent exactement la meme chose

##### make run

La commande make run est tèés pratique car elle permet de compiler le code et de le lancer, cela fait d'économiser du temps. En effet, sans la commande on devrait faire :
- make
- ./build/main

##### make clean-build

Supprime les fichiers objets dans le dossier build, ne laisse que les exécutables

##### make clean

Supprime les fichiers objets et les executables dans le dossier build

##### make compile-test

Compile les codes de test, pour les lancer : ./build/test ou commande suivante

##### make test

Compile les codes de test et les executent

##### make archive

Crée l'archive .zip à envoyer sur moodle du projet en ayant pris soin de nettoyer le dossier build pour eviter d'allourdir l'archive sans raison