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
    printf("\n");
    printf("\n");
    printf("\t***************************************************************************************************\t\n");
    printf("\t***************************************************************************************************\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      **\t\n");
    printf("\t**      *                        BIENVENUE SUR NOTRE MENU D'ACCEUIL                       *      **\t\n");
    printf("\t**      * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *      **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**                                          LE QUORIDOR                                          **\t\n");
    printf("\t**            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~           **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**               VEUILLEZ CHOISIR UNE OPTION                                                     **\t\n");
    printf("\t**             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                                    **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**        1 - LANCER UN NOUVELLE PARTIE                                                          **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**        2 - REPRENDRE UNE PARTIE SAUVEGARDEE                                                   **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**        3 - AFFICHER LES SCORES                                                                **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**        4 - AFFICHER L'AIDE                                                                    **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**        5 - QUITTER LE JEU                                                                     **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t**                                         AMUSEZ VOUS BIEN!!                                    **\t\n");
    printf("\t**                                                                                               **\t\n");
    printf("\t***************************************************************************************************\t\n");
    printf("\t***************************************************************************************************\t\n");
    printf("\n");

    int choix;
    printf("Entrez votre choix (1-5) : ");

    if (scanf(" %d", &choix) != 1) {
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

//  Affichage de l'aide pour les joueurs
void Aide(
    ) {
    int choix2 = 0;
    printf(" 1- Afficher l'aide pour le menu\n");
    printf(" 2- Voir les regles de jeu\n");
    printf(" 3- Retourner au menu principal\n");

    scanf("%d", &choix2);

    switch (choix2) {
        case 1:
            printf("\tBravo vous avez trouver le menu d'aide donc l'option 4 est ok!!!\n");
            printf("Dans le menu d'aide : \n");
            printf("\t* Pour commencer un nouvelle partie choissisez l'option 1\n");
            printf("\t* Pour reprendre la derniere partie sauvegardee choisissez  2\n");
            printf("\t* Pour afficher les scores enregistres choisissez l'option 3\n");
            printf("\t* Pour quitter definitivement le jeu choisissez l'option 5\n");

            printf("\n");
            Aide();

        break;
        case 2:
            printf("\Voyons ensemble les regles du jeu :\n");
            printf("\t* Chaque joueur a la main a tour de role : \n");
            printf("\t* Chaque joueur est caracterise par son nom et une lettre qu'il choisit pour etre affichee sur le plateau\n");
            printf("\t* Lorsque le joueur a la main il peut effectuer deux actions :\n");
            printf("\t\t* Deplacer son pion dans une direction (Gauche, Droite, en Haut et en Bas) à sa guise \n");
            printf("\t\t* Placer une barriere pour tracer son chemin ou bloquer les autres joueurs\n");
            printf("\t* Pour quitter le jeu il faut sauvergarder la partie en cours\n");
            printf("\t* Le jeu se termine si il est sauvegarder ou si un des joueurs remporte la partie\n");
            printf("\t* La partie est remportee lorsque ?????\n");
            printf("\n");
            Aide();

        break;
        case 3:
            Menu();
        break;
    }

}
void Quitter() {
}