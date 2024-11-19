//
// Created by Bigeard on 11/18/2024.
//
#include "Menu.h"
#include <stdio.h>

#include "Partie.h"

//Vide le tampon
void ViderTampon() {
    while (getchar() != '\n');  // Lire et ignorer tous les caractères jusqu'au saut de ligne
}
//Afficher le menu
int MenuIhm() {
    // Affichage du menu d'accueil
    printf("Menu d'accueil - Choisissez une option :\n");
    printf("1/ Lancer une nouvelle partie\n");
    printf("2/ Reprendre une partie sauvegardée\n");
    printf("3/ Afficher les scores\n");
    printf("4/ Afficher l'aide\n");
    printf("5/ Quitter le jeu\n");

    int choix;
    printf("Entrez votre choix (1-5) : ");

    if (scanf("%d", &choix) != 1) {
        // Si la saisie échoue (par exemple, une lettre est entrée)
        ViderTampon();  // Vider le tampon pour éliminer la saisie invalide
        choix = 0;  // Forcer la boucle à redemander un choix
    }

    return choix;
}

// Lancer le menu
void Menu() {
    int choix = MenuIhm();
    //Tant que le choix est invalides
    while (!(choix >= 1 && choix <= 5)) {
        printf("Choix non valide, veuillez selectionner un chiffre entre 1 et 5 !");
        //Recuperer le choix de l'utilisateur
        choix = MenuIhm();
    }
    switch (choix) {
        case 1:
            NouvellePartie();
        break;
        case 2:
            ChargerPartie();
        break;
        case 3:
            ScoreJoueurs();
        break;
        case 4:
            Aide();
        break;
        case 5:
            Quitter();
        break;
        default:
            Menu();
        break;
    }

}

// Lancer une nouvelle partie
void NouvellePartie() {
    Partie* partie = InitialiserPartie();
}

// Charger une ancienne partie
void ChargerPartie() {
    // Implémentation à faire
}

// Afficher les scores des joueurs
void ScoreJoueurs() {
    // Implémentation à faire
}

void Aide() {}
void Quitter(){}