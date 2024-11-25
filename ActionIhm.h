//
// Created by Bigeard on 11/20/2024.
//

#ifndef ACTIONIHM_H
#define ACTIONIHM_H
#include <stdio.h>
#include "Joueur.h"
#include "Barriere.h"


//Afficher les différentes actions faisable
int ActionIhm(Joueur joueur);
//Afficher que l'action est impossible
void ActionImpossible(TypeAction actionType);
//Renvoi la barriere choisi par l'utilisateur
void BarriereIhm(Joueur* joueur, Barriere* barriere);

#endif //ACTIONIHM_H
