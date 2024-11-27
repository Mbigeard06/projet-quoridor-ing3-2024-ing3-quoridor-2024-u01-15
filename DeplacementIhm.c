//
// Created by Bigeard on 11/21/2024.
//
#include "DeplacementIhm.h"

#include <stdio.h>


#include "Joueur.h"

// Fonction pour afficher les options de déplacement
Direction AfficherDeplacement() {
    Direction deplacement = Sortie; // Initialiser à Sortie
    char direction = ' '; // Initialiser à un caractère vide

    // Affichage des options de déplacement
    printf("Choisissez une direction pour deplacer votre pion :\n");
    printf("z : Haut\n");
    printf("q : Gauche\n");
    printf("s : Bas\n");
    printf("d : Droite\n");
    printf("e : Revenir en arriere\n");
    printf("Votre choix : ");

    // Lire l'entrée du joueur
    while (1) {
        if (scanf(" %c", &direction) != 1) {
            // Si l'entrée n'est pas valide, vider le tampon
            while (getchar() != '\n');
            printf("Entree invalide. Veuillez choisir l'une des options : z, q, s, d, e.\n");
        } else {
            // Vérification de la validité de l'entrée
            switch (direction) {
                case 'z':
                    deplacement = Haut;
                break;
                case 'Z':
                    deplacement = Haut;
                break;
                case 'q':
                    deplacement = Gauche;
                break;
                case 'Q':
                    deplacement = Gauche;
                break;
                case 's':
                    deplacement = Bas;
                break;
                case 'S':
                    deplacement = Bas;
                break;
                case 'd':
                    deplacement = Droit;
                break;
                case 'D':
                    deplacement = Droit;
                break;
                case 'e':
                    deplacement = Sortie;
                break;
                case 'E':
                    deplacement = Sortie;
                break;
                default:
                        printf("Choix invalide. Veuillez choisir l'une des options : z, q, s, d, e.\n");
                continue;  // Redemander l'entrée
            }
            break;  // Sortir de la boucle si une option valide est choisie
        }
    }

    return deplacement; // Retourne le déplacement choisi
}