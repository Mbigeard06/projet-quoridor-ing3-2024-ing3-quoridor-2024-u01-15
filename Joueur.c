//
// Created by Bigeard on 11/16/2024.
//
#include "Joueur.h"

#include <stdio.h>

//Modifier le nombre de barriere d'un joueur
void AttribuerBarriere(Joueur* joueurs, int nbBarriere) {
    joueurs->nbrBarriere += nbBarriere;
}

//Définir le pion du joueur
void AttribuerPion(Joueur* joueur, char pion) {
    joueur->pion = pion;
}

//Définir le pion du joueur
void SetJoueurPosition(Joueur* joueur,Position position) {
    joueur->position.x = position.x;
    joueur->position.y = position.y;
}

//Calculer la position
Position CalculerPosition(Position position, Direction deplacement) {
    Position newPosition = position;
    switch (deplacement) {
        case Haut:
            newPosition.x -= 1;
        break;
        case  Bas:
            newPosition.x += 1;
        break;
        case Gauche:
            newPosition.y -= 1;
        break;
        case Droit:
            newPosition.y += 1;
        break;
    }
    return newPosition;
}

