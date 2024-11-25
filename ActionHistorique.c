//
// Created by Bigeard on 11/25/2024.
//

#include "ActionHistorique.h"

//Créer nouveau noeux (Initialisation)
struct ActionNode* createNode(Action action) {
    //Allocation dynamique de memoire
    struct ActionNode* newNode = (struct ActionNode*)malloc(sizeof(struct ActionNode));
    newNode->action = &action;
    newNode->prev = NULL;
    return newNode;
}

//Ajouter une nouvelle action
void pushAction(Action action, struct ActionNode* tail) {
    struct ActionNode* newNode = createNode(action);
    if (tail == NULL) {
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail = newNode;
    }
}

Action* getLastAction(struct ActionNode* tail) {
    return tail->action;
}