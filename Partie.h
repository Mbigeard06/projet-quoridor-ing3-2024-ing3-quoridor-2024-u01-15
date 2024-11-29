//
// Created by Bigeard on 11/16/2024.
//

#ifndef PARTIE_H
#define PARTIE_H
#include "ActionHistorique.h"
#include "Joueur.h"
#include "Plateau.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "JoueurDao.h";
#define MAX_NOM_PARTIE 100  // Taille maximale du nom de la partie


typedef struct {
    char nomPartie[30];
    //Joueur en cours de tour
    int indiceJoueur;
    //Nombre de Joueur
    int nbJoueur;
    //Plateau de la partie
    Plateau plateau;
    //Dernier Action
    struct ActionNode* dernierAction;
    //Joueur de la partie (Allocation dynamique) (tableau de pointeur de joueur)
    Joueur* joueurs;
} Partie;


//----------------------------- FONCTIONS -------------------------------------
//Initialise une partie
Partie* InitialiserPartie();
//Calculer ordre de passage
void CalculerPassage(Joueur* joueur[]);
//Placer une barrière
bool PlacerBarriere(Joueur* joueur, Plateau* plateau, Action* lastAction);
//Passer au tour suivant
void TourSuivant(Partie* partie);
//Annuler l'action précédente
void AnnulerAction(Joueur* joueur[], int indiceJoueur, int nbJoueur, Action dernierAction);
//Tour suivant
void TourSuivant(Partie* partie);
#endif //PARTIE_H
