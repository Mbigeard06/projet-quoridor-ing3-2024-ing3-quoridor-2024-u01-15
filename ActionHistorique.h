//
// Created by Bigeard on 11/25/2024.
//

#ifndef ACTIONHISTORIQUE_H
#define ACTIONHISTORIQUE_H
#include <stdio.h>
#include <stdlib.h>

#include "Joueur.h"

struct ActionNode{
    Action* action;
    struct ActionNode* next;
    struct ActionNode* prev;

};

//Créer nouveau noeux (Initialisation)
struct ActionNode* createNode(Action action);

//Ajouter une nouvelle action
void pushAction(Action action, struct ActionNode* tail);

Action* getLastAction();



#endif //ACTIONHISTORIQUE_H
