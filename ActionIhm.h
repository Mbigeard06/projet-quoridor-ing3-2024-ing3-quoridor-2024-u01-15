//
// Created by Bigeard on 11/20/2024.
//

#ifndef ACTIONIHM_H
#define ACTIONIHM_H
#include <stdio.h>

#include "Action.h"
#include "Joueur.h"

//Afficher les différentes actions faisable
int ActionIhm(Joueur joueur);
//Afficher que l'action est impossible
void ActionImpossible(TypeAction actionType);

#endif //ACTIONIHM_H
