//
// Created by Bigeard on 11/16/2024.
//

#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU 9
#include "Joueur.h"
#include "Position.h"

//Represente un plateau
typedef struct {
    char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
    char barriereHorizontal[TAILLE_PLATEAU][TAILLE_PLATEAU ];
    char barriereVerticale[TAILLE_PLATEAU][TAILLE_PLATEAU];
} Plateau;


//Initiliaser le plateau
void InitialiserPlateau(Plateau *p, Joueur *joueurs, int nbJoueurs);
//Placer un pion
void PlacerPion(Plateau *p, Position pos, Joueur* joueur);
//Afficher le plateau
void AfficherPlateau(Plateau *p);

#endif //PLATEAU_H

