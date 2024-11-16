//
// Created by Bigeard on 11/16/2024.
//

#ifndef ACTION_H
#define ACTION_H
#include "Joueur.h"

// Type d'action possible que l'utilisateur peut effectuer
typedef enum {
    Deplacement,
    Annulation,
    Barriere
} TypeAction;

//Represente une action
typedef struct {
    //Type d'action effectuée
    TypeAction action;
    //Joueur ayant executé l'action
    Joueur* joueur;
    //Position avant execution de l'action
    Position prePosition;
} Action;
#endif //ACTION_H
