//
// Created by Bigeard on 11/18/2024.
//
#include "Menu.h"
#include <stdio.h>

#include "PartieDao.h"

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
    printf("\t**        1 - DEMARRER UN NOUVELLE PARTIE                                                        **\t\n");
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
            printf("ICI");
            Partie partie;
            //ChargerPartie
            ChargerPartie(&partie);
            //Mettre à jour l'indice joueur (auto incrementé dans lancer tour)
            partie.indiceJoueur--;
            if (partie.indiceJoueur < 0) {
                partie.indiceJoueur = 0;
            }
            //Lancer tour
            TourSuivant(&partie);
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

// Afficher les scores des joueurs
void ScoreJoueurs() {
    // Implémentation à faire
}

void Aide() {}
//Libere la memoire allouee
void Quitter(Partie* partie) {
    printf("Au revoir :) !");
    free(partie->joueurs);
}