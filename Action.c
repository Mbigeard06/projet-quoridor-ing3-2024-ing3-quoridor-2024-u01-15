//
// Created by Bigeard on 11/20/2024.
//

#include "Action.h"

#include <stdbool.h>


//Determine si la partie est gagnée par le joueur
bool EstGagne(Joueur joueur, int indiceJoueur) {
    if (indiceJoueur == 1) {
        if(joueur.position.x == TAILLE_PLATEAU - 1) {
            return true;
        }
    }
    else if (indiceJoueur == 2) {
        if(joueur.position.x == 0) {
            return true;
        }
    }
    else if (indiceJoueur == 3) {
        if(joueur.position.y == TAILLE_PLATEAU - 1) {
            return true;
        }
    }
    else {
        if(joueur.position.y == 0) {
            return true;
        }
    }
}

bool Actionner(int numAction, Plateau* plateau, Action* lastAction, Joueur* joueur) {
}