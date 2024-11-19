//
// Created by Bigeard on 11/16/2024.
//
#include "Joueur.h"

//Modifier le nombre de barriere d'un joueure
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