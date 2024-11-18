//
// Created by Bigeard on 11/16/2024.
//

#include "Partie.h"

#include <stdlib.h>
#include <time.h>



//Initialise la partie
void InitialiserPartie(Partie* partie, int nbJoueurs) {
    //Premier tour -> aucun joueur n'as joué
    partie->indiceJoueur =  -1;
}

//Calculer ordre de passage
void CalculerPassage(Joueur* joueur[]){};
//Deplacer un joueur
void DeplacerJoueur(Joueur* joueur, Plateau* plateau, TypeDeplacement deplacement){};
//Placer une barrière
void PlacerBarriere(Joueur* joueur, Position position){};
//Passer au tour suivant
void TourSuivant(Joueur* joueur[], int* indiceJoueur, int nbJoueur, Action* dernierAction){};
//Annuler l'action précédente
void AnnulerAction(Joueur* joueur[], int indiceJoueur, int nbJoueur, Action dernierAction){};
//Sauvegarder Partie
int SauvegarderPartie(Partie partie) {
    return 1;
}
