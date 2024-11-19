//
// Created by Bigeard on 11/16/2024.
//


#ifndef JOUEUR_H
#define JOUEUR_H

#include "Position.h"

//Représente une joueur
typedef struct {
    char nom[30];
    int nbrBarriere;
    Position position;
    int score;
    char pion;
} Joueur;

//Deplacer le joueur (change ces coordonnées)
void SetJoueurPosition(Joueur* joueur,Position position);
//Attribuer les barrieres à un joueur
void AttribuerBarriere(Joueur* joueurs, int nbBarriere);
//Définir le pion du joueur
void AttribuerPion(Joueur* joueur, char pion);



#endif //JOUEUR_H
