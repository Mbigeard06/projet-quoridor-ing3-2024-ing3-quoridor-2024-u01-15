//
// Created by Bigeard on 11/16/2024.
//

#include "Partie.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Définie les informations sur les différents joueur
void ObtenirJoueur(Partie* partie) {
    printf("Combien de joueurs participent (2 ou 4) ?\n");
    partie->nbJoueur = 0;

    // Récupérer le nombre de joueurs, tant que ce n'est pas 2 ou 4
    while (partie->nbJoueur != 2 && partie->nbJoueur != 4) {
        if (scanf("%d", &partie->nbJoueur) != 1) {
            // Si la saisie échoue (par exemple, une lettre est entrée)
            while (getchar() != '\n');  // Vider le tampon pour éliminer la saisie invalide
            partie->nbJoueur = 0;  // Forcer la boucle à redemander un choix
        }
        if (partie->nbJoueur != 2 && partie->nbJoueur != 4) {
            printf("Veuillez entrer 2 ou 4 joueurs seulement : ");
        }
    }

    //Création d'un tableau dynamique pour stocker les joueurs
    partie->joueurs = calloc(partie->nbJoueur, sizeof(Joueur));
    char pion;
    for (int i = 0; i < partie->nbJoueur; i++) {
        printf("Saisissez le nom du joueur %d : ", i + 1);
        scanf("%s", partie->joueurs[i].nom);
        //Vider tampon
        while (getchar() != '\n');
        //Récupération du score du joueur
        partie->joueurs[i].score = ScoreJoueur(partie->joueurs[i].nom);
        //Choix du pion
        printf("\nQuel symbol veuillez vous prendre pour votre pion ?");
        scanf("%c", &pion);
        AttribuerPion(&partie->joueurs[i], pion);
        //Vider tampon
        while (getchar() != '\n');
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
    printf("Ordre de passage des joueurs (aleatoire) :\n");
    for (int i = 0; i < partie->nbJoueur; i++) {
        printf("Joueur %d : %s. Symbol : %c Score : %d\n", i + 1, partie->joueurs[i].nom, partie->joueurs[i].pion, partie->joueurs[i].score);
    }
}

//Attribuer les barrières
void AttribuerBarrieres(Joueur* joueurs, int nbJoueur) {
    for (int i = 0; i < nbJoueur; i++) {
        AttribuerBarriere(&joueurs[i], 20 / nbJoueur);
    }
}

//Initialise les joueurs
void InitialiserJoueurs(Partie* partie) {
    //Récupération des informations sur les différents joueurs
    ObtenirJoueur(partie);
    //Determiner ordre de passage aléatoire
    OrdreDePassage(partie);
    //Afficher l'ordre de passage
    OrdreDePassageIhm(partie);
    //Donnes les barrieres aux joueurs
    AttribuerBarrieres(partie->joueurs, partie->nbJoueur);
    printf("%d",partie->joueurs[0].nbrBarriere);
}

//Passer au tour suivant. Fonction récursive
void TourSuivant(Partie* partie){
    //On passe au joueur suivant
    if(partie->indiceJoueur < partie->nbJoueur - 1)partie->indiceJoueur++;
    else {
        partie->indiceJoueur = 0;
    }
    if(Tour(partie)) {
        TourSuivant(partie);
    }
};

//Initialise la partie
Partie* InitialiserPartie() {
    Partie partie;
    //Pas de joueur
    partie.indiceJoueur = -1;
    InitialiserJoueurs(&partie);
    InitialiserPlateau(&partie.plateau,partie.joueurs, partie.nbJoueur);
    AfficherPlateau(&partie.plateau);
    //Pas d'action avant
    partie.dernierAction =NULL;
    //Lancement du premier tour
    TourSuivant(&partie);
    return NULL;
}

//Calculer ordre de passage
void CalculerPassage(Joueur* joueur[]){};
//Annuler l'action précédente
void AnnulerAction(Joueur* joueur[], int indiceJoueur, int nbJoueur, Action dernierAction){};
//Sauvegarder Partie
int SauvegarderPartie(Partie partie) {};
