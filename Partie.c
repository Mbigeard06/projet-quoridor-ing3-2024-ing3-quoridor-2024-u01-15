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
    srand(time(NULL));  // Initialiser le générateur de nombres aléatoires
    for (int i = partie->nbJoueur - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // Choisir un index aléatoire entre 0 et i
        // Échanger partie->joueurs[i] et partie->joueurs[j]
        Joueur temp = partie->joueurs[i];
        partie->joueurs[i] = partie->joueurs[j];
        partie->joueurs[j] = temp;
    }
}

// Fonction pour afficher l'ordre de passage des joueurs
void OrdreDePassageIhm(Partie* partie) {
    printf("Ordre de passage des joueurs (aléatoire) :\n");
    for (int i = 0; i < partie->nbJoueur; i++) {
        printf("Joueur %d : %s. Score : %d\n", i + 1, partie->joueurs[i].nom, partie->joueurs[i].score);
    }
}

//Initialise la partie
Partie* InitialiserPartie() {
    //Initilisation des jouers
    Partie partie;
    //Récupération des informations sur les différents joueurs
    ObtenirJoueur(&partie);
    //Determiner ordre de passage aléatoire
    OrdreDePassage(&partie);
    //Afficher l'ordre de passage
    OrdreDePassageIhm(&partie);
    //Donnes les barrieres aux joueurs
    return NULL;
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
