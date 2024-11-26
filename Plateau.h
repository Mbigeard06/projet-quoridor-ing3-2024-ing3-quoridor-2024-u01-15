//
// Created by Bigeard on 11/16/2024.
//

#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU 9
#include "Joueur.h"
#include "DeplacementIhm.h"
#include "Barriere.h"
#include "JoueurDao.h"
#include "ActionIhm.h"


//Represente un plateau
typedef struct {
    char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
    char barriereHorizontal[TAILLE_PLATEAU][TAILLE_PLATEAU ];
    char barriereVerticale[TAILLE_PLATEAU][TAILLE_PLATEAU];
} Plateau;


//Initiliaser le plateau
void InitialiserPlateau(Plateau *p, Joueur *joueurs, int nbJoueurs);
//Placer un pion
void PlacerPion(Plateau *p, Position pos, Joueur* joueur);
//Afficher le plateau
void AfficherPlateau(Plateau *p);
//Renvoi true si le déplacement à abouti et false sinon
bool DeplacerJoueur(Joueur* joueur, Plateau* plateau, Action* lastAction);
//Modifie la position du joueur
void SetPostionJoueur(Joueur* joueur, Plateau* plateau, Action* lastAction, Position oldPosition, Position newPosition);
//Placer une barriere
bool PlacerBarriere(Joueur* joueur, Plateau* plateau, Action* lastAction);
//Enregistre le placement de la barriere
void EnregistrerBarriere(Barriere barriere,Joueur* joueur, Action* lastAction);
//Modifier les barrierres
void SetBarriere(Plateau *p, Barriere barriere, char visuel);
#endif //PLATEAU_H

