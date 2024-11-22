//
// Created by Bigeard on 11/16/2024.
//

#ifndef ACTION_H
#define ACTION_H
#include <stdbool.h>

#include "Joueur.h"
#include "Plateau.h"

// Type d'action possible que l'utilisateur peut effectuer
typedef enum {
    Deplacement,
    Annulation,
    PoserBarriere
} TypeAction;

//Represente une action
typedef struct {
    //Type d'action effectuée
    TypeAction action;
    //Joueur ayant executé l'action
    Joueur* joueur;
    //Position de l'objet conerné par l'action
    Position position;
    //Type de postion (h ou v) important pour barriere
    char typePostion;

} Action;

//Effectuer une action
bool EstGagne(Joueur joueur, int indiceJoueur);
bool Actionner(int numAction, Plateau* plateau, Action* lastAction, Joueur* joueur);
#endif //ACTION_H
