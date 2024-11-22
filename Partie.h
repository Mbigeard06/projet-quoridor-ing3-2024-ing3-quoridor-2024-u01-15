//
// Created by Bigeard on 11/16/2024.
//

#ifndef PARTIE_H
#define PARTIE_H
#include "Joueur.h"
#include "Plateau.h"
#include "Action.h"


typedef struct {
    //Joueur en cours de tour
    int indiceJoueur;
    //Nombre de Joueur
    int nbJoueur;
    //Plateau de la partie
    Plateau plateau;
    //Dernier Action
    Action* dernierAction;
    //Joueur de la partie (Allocation dynamique) (tableau de pointeur de joueur)
    Joueur* joueurs;
} Partie;


//----------------------------- FONCTIONS -------------------------------------
//Initialise une partie
Partie* InitialiserPartie();
//Calculer ordre de passage
void CalculerPassage(Joueur* joueur[]);
//Placer une barrière
void PlacerBarriere(Joueur* joueur, Position position);
//Passer au tour suivant
void TourSuivant(Partie* partie);
//Annuler l'action précédente
void AnnulerAction(Joueur* joueur[], int indiceJoueur, int nbJoueur, Action dernierAction);
//Sauvegarder Partie
int SauvegarderPartie(Partie partie);
#endif //PARTIE_H
