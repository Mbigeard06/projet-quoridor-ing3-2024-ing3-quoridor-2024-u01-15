//
// Created by Bigeard on 11/16/2024.
//

#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H
#include <stdbool.h>
#include "Joueur.h"
#include "Action.h"
#include "Plateau.h"
#include "DeplacementIhm.h"

typedef enum {
    Haut,
    Bas,
    Gauche,
    Droit,
    Sortie//Affiche à l'écran les différents types de déplacement
} TypeDeplacement;

bool DeplacerJoueur(Joueur* joueur, Plateau* plateau, Action lastAction);
#endif //DEPLACEMENT_H
