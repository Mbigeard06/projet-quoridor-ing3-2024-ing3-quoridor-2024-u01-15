//
// Created by Bigeard on 11/16/2024.
//

#include "Plateau.h"

#include <stdio.h>

#include "Joueur.h"
#include "Position.h"

//Initialise la position
void IntialiserJoueursPlateau(Joueur* joueurs, int nbJoueur, Plateau *plateau) {
    //Premier joueur
    Position p0;
    p0.x = 0;
    p0.y = 4;
    //Placer pion
    PlacerPion(plateau, p0, &joueurs[0]);
    //Modification position joueur (objet)
    SetJoueurPosition(&joueurs[0], p0 );

    //Premier joueur
    Position p1;
    p1.x = TAILLE_PLATEAU - 1;
    p1.y = 4;
    //Placer pion
    PlacerPion(plateau, p1, &joueurs[1]);
    //Modification position joueur (objet)
    SetJoueurPosition(&joueurs[1], p1);

    if(nbJoueur > 2) {
        //Placer les joueur supplémentaires
        Position p2;
        p2.x = 4;
        p2.y = 0;
        //Placer pion
        PlacerPion(plateau, p2, &joueurs[2]);
        //Modification position joueur (objet)
        SetJoueurPosition(&joueurs[2], p2);

        //Placer les joueur supplémentaires
        Position p3;
        p3.x = 4;
        p3.y = TAILLE_PLATEAU - 1;
        //Placer pion
        PlacerPion(plateau, p3, &joueurs[3]);
        //Modification position joueur (objet)
        SetJoueurPosition(&joueurs[3], p3);
    }
}


// Initialiser le plateau avec des cases vides
void InitialiserPlateau(Plateau *p, Joueur *joueurs, int nbJoueurs) {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            p->plateau[i][j] = ' '; // Case vide
        }
    }
    IntialiserJoueursPlateau(joueurs, nbJoueurs, p);
}

// Placer un pion sur le plateau
void PlacerPion(Plateau *p, Position pos, Joueur* joueur) {
    p->plateau[pos.x][pos.y] = joueur->pion;
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
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            printf(" %c |", p->plateau[i][j]);
        }
        printf("\n   +");
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            printf("---+");
        }
        printf("\n");
    }
}

