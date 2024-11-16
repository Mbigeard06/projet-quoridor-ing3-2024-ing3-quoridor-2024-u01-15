//
// Created by Bigeard on 11/16/2024.
//


#ifndef JOUEUR_H
#define JOUEUR_H

#include "Position.h";

//Représente une joueur
typedef struct {
    char nom[30];
    int* nbrBarriere;
    Position* position;
} Joueur;

//Deplace le joueur (change ces coordonnées)
void deplacerJoueur(Joueur* joueur);


#endif //JOUEUR_H
