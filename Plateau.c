//
// Created by Bigeard on 11/16/2024.
//

#include "Plateau.h"
#include <stdio.h>


// Fonction principale pour initialiser les joueurs sur le plateur
void InitialiserJoueursPlateau(Joueur* joueurs, int nbJoueur, Plateau *plateau) {
    // Définir les positions de base des joueurs (en fonction du nombre de joueurs)
    Position positions[] = {
        {0, 4},  // Joueur 1 (haut du plateau)171

        {TAILLE_PLATEAU - 1, 4},  // Joueur 2 (bas du plateau)
        {4, 0},  // Joueur 3 (gauche du plateau)
        {4, TAILLE_PLATEAU - 1}  // Joueur 4 (droite du plateau)
    };

    // Initialiser les joueurs sur le plateau en utilisant une boucle
    for (int i = 0; i < nbJoueur; i++) {
        PlacerPion(plateau, positions[i], &joueurs[i]);  // Placer le pion sur le plateau
        SetJoueurPosition(&joueurs[i], positions[i]);    // Mettre à jour la position du joueur
    }
}

// Initialiser le plateau avec des cases vides
void InitialiserPlateau(Plateau *p, Joueur *joueurs, int nbJoueurs) {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            p->plateau[i][j] = ' '; // Case vide
            p->barriereHorizontal[i][j] = ' ';
            p->barriereVerticale[i][j] = ' ';
        }
    }
    InitialiserJoueursPlateau(joueurs, nbJoueurs, p);
}

// Placer un pion sur le plateau
void PlacerPion(Plateau *p, Position pos, Joueur* joueur) {
    p->plateau[pos.x][pos.y] = joueur->pion;
}


//Placer une barriere
void PlacerBarriere(Plateau *p, Barriere barriere) {
    if(barriere.type == 'h') {
        for(int i = 0; i < 2; i++) {
            p->barriereHorizontal[barriere.position.x][barriere.position.y + i] = 'b';
        }
    }
    else {
        for(int i = 0; i < 2; i++) {
            p->barriereVerticale[barriere.position.x + i][barriere.position.y] = 'b';
        }
    }
}


// Afficher le plateau de jeu avec des bordures et séparations
void AfficherPlateau(Plateau *p) {

    printf("\n    ");
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        printf(" %d  ", i);  // Affiche les numéros de colonne en haut
    }
    printf("\n   +");
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        printf("---+");
    }
    printf("\n");

    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        printf(" %d |", i);  // Affiche les numéros de ligne à gauche
        //Vertical
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            if(p->barriereVerticale[i][j] == 'b') {
                printf(" %c b", p->plateau[i][j]);
            }
            else {
                printf(" %c |", p->plateau[i][j]);
            }
        }
        printf("\n   +");
        //Horizontal
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            if(p->barriereHorizontal[i][j] == 'b') {
                printf(" b +");
            }
            else {
                printf("---+");
            }

        }
        printf("\n");
    }
}


