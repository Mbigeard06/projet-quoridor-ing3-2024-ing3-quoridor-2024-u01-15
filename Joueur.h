//
// Created by Bigeard on 11/16/2024.
//

//8.0
//0.8
//
#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdbool.h>

//Represente une position sur le plateau
typedef struct {
    int x;
    int y;
} Position;

//Représente une joueur
typedef struct {
    char nom[30];
    int nbrBarriere;
    Position position;
    int score;
    char pion;
    //True si le joueur peut encore annuler une action
    bool annuler;
} Joueur;

// Type d'action possible que l'utilisateur peut effectuer
typedef enum {
    Deplacement,
    Annulation,
    PoserBarriere,
    Inaction,
    Initialisation
} TypeAction;

typedef enum {
    Haut,
    Bas,
    Gauche,
    Droit,
    Sortie//Affiche à l'écran les différents types de déplacement
} Direction;

//Represente une action
typedef struct {
    //Type d'action effectuée
    TypeAction action;
    //Joueur ayant executé l'action
    Joueur* joueur;
    //Position (si déplacement, c'est la position avant le déplacement)
    Position position;
    //Type de postion (h ou v) seulement utile pour barriere
    char typePostion;
    //Direction
    Direction direction;
} Action;

//Deplacer le joueur (change ces coordonnées)
void SetJoueurPosition(Joueur* joueur,Position position);
//Attribuer les barrieres à un joueur
void AttribuerBarriere(Joueur* joueurs, int nbBarriere);
//Définir le pion du joueur
void AttribuerPion(Joueur* joueur, char pion);
//Effectuer une action
bool AGagne(Joueur joueur, int indiceJoueur);
//Calcule la nouvelle position suite à un déplacement
Position CalculerPosition(Position position, Direction direction);



#endif //JOUEUR_H
