//
// Created by Bigeard on 11/18/2024.
//
#include "Menu.h"

#include <stdio.h>

//Afficher le menu
int menuIhm() {
    // Affichage du menu d'accueil
    printf("Menu d'accueil - Choisissez une option :\n");
    printf("1/ Lancer une nouvelle partie\n");
    printf("2/ Reprendre une partie sauvegardée\n");
    printf("3/ Afficher les scores\n");
    printf("4/ Afficher l'aide\n");
    printf("5/ Quitter le jeu\n");

    int choix;
    printf("Entrez votre choix (1-5) : ");
    scanf("%d", &choix);

    return choix;
}