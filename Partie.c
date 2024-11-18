//
// Created by Bigeard on 11/16/2024.
//

#include "Partie.h"

#include <stdio.h>

#include "Joueur.h"

#include <stdlib.h>
#include <time.h>

#include "JoueurDao.h"


//Définie les informations sur les différents joueur
void ObtenirJoueur(Partie* partie) {
    printf("Combien de joueurs participent (2 ou 4) ?\n");
    partie->nbJoueur = 0;

    // Récupérer le nombre de joueurs, tant que ce n'est pas 2 ou 4
    while (partie->nbJoueur != 2 && partie->nbJoueur != 4) {
        scanf("%d", &partie->nbJoueur);
        if (partie->nbJoueur != 2 && partie->nbJoueur != 4) {
            printf("Veuillez entrer 2 ou 4 joueurs seulement : ");
        }
    }

    //Création d'un tableau dynamique pour stocker les joueurs
    partie->joueurs = calloc(partie->nbJoueur, sizeof(Joueur));
    for (int i = 0; i < partie->nbJoueur; i++) {
        printf("Saisissez le nom du joueur %d : ", i + 1);
        scanf("%s", partie->joueurs[i].nom);
        //Récupération du score du joueur
        partie->joueurs[i].score = ScoreJoueur(partie->joueurs[i].nom);
    }
}

//Détermine aléatoirement l'ordre de passage des joueurs
void OrdreDePassage(Partie* partie) {

}

//Initialise la partie
Partie* InitialiserPartie() {
    Partie partie;
    //Récupération des informations sur les différents jouers
    ObtenirJoueur(&partie);
    //Calculer ordre de passage
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
int SauvegarderPartie(Partie partie) {};
