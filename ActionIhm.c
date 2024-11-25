//
// Created by Bigeard on 11/20/2024.
//

#include "ActionIhm.h"

// Renvoie le choix du joueur avec gestion des erreurs d'entrée
int ActionIhm(Joueur joueur) {
    int choix = 0;
    int valide = 0;
    while(!valide) {
        printf("\nTour du joueur : %s | Nombre de barrieres disponibles : %d", joueur.nom, joueur.nbrBarriere);
        printf("\n1/ Deplacer son pion");
        printf("\n2/ Poser une barriere");
        printf("\n3/ Passer son tour");
        printf("\n4/ Annuler la derniere action");
        printf("\n4/ Sauvegarder et quitter la partie");
        printf("\nVotre choix : ");

        // Vérification de la validité de l'entrée
        if(scanf("%d", &choix) != 1) {
            // Si l'entrée n'est pas un entier, vider le tampon et afficher un message d'erreur
            while (getchar() != '\n'); // Vider le tampon
            printf("Entree invalide. Veuillez saisir un nombre entier entre 1 et 4.\n");
        } else if (choix < 1 || choix > 5) {
            // Si l'entrée n'est pas dans la plage valide
            printf("Choix invalide. Veuillez saisir un nombre entre 1 et 4.\n");
        } else {
            // Si l'entrée est valide, on sort de la boucle
            valide = 1;
        }
    }
    return choix;
}

// Renvoi la barrière choisie par l'utilisateur
void BarriereIhm(Joueur* joueur, Barriere* barriere) {
    int valide = 0;
    int choixType = 0;

    // Demander le type de la barrière
    while (!valide) {
        printf("\n| Nombre de barrières disponibles : %d", joueur->nbrBarriere);
        printf("\n1/ Poser une barrière horizontale");
        printf("\n2/ Poser une barrière verticale");
        printf("\n3/ Effectuer une autre action");
        printf("\nVotre choix : ");

        if (scanf("%d", &choixType) != 1) {
            // Vider le tampon en cas d'entrée invalide
            while (getchar() != '\n');
            printf("Entree invalide. Veuillez saisir 1 ou 2.\n");
        } else if (choixType < 1 || choixType > 2) {
            // Vérification que l'entrée est dans la plage
            printf("Choix invalide. Veuillez saisir 1 pour horizontal ou 2 pour vertical.\n");
        }
        else if (choixType == 3) {
            // Annulation de la pose de la barrière
            barriere = NULL;
            return NULL; // Retourner NULL si l'utilisateur a choisi de ne pas poser la barrière
        }
        else {
            // Si l'entrée est valide, on sort de la boucle
            valide = 1;
        }
    }

    // Affecter le type de la barrière
    if (choixType == 1) {
        barriere->type = 'h';  // Horizontale
    } else {
        barriere->type = 'v';  // Verticale
    }

    // Demander la direction de la barrière en fonction de son type
    valide = 0;
    while (!valide) {
        if (barriere->type == 'h') {
            printf("\nChoisissez la direction de la barrière horizontale :\n");
            printf("g : Gauche\n");
            printf("d : Droite\n");
            printf("Votre choix : ");
            if (scanf(" %c", &barriere->direction) != 1 || (barriere->direction != 'g' && barriere->direction != 'd')) {
                while (getchar() != '\n');  // Vider le tampon
                printf("Entrée invalide. Veuillez saisir 'g' pour gauche ou 'd' pour droite.\n");
            } else {
                valide = 1;
            }
        } else if (barriere->type == 'v') {
            printf("\nChoisissez la direction de la barrière verticale :\n");
            printf("h : Haut\n");
            printf("b : Bas\n");
            printf("Votre choix : ");
            if (scanf(" %c", &barriere->direction) != 1 || (barriere->direction != 'h' && barriere->direction != 'b')) {
                while (getchar() != '\n');  // Vider le tampon
                printf("Entrée invalide. Veuillez saisir 'h' pour haut ou 'b' pour bas.\n");
            } else {
                valide = 1;
            }
        }
    }

    // Récupérer position barrière
    valide = 0;
    while (!valide) {
        printf("\nVeuillez entrer la position de la barrière (x, y) : ");
        if (scanf("%d %d", &barriere->position.x, &barriere->position.y) != 2) {
            while (getchar() != '\n');
            printf("Entrée invalide. Veuillez saisir des coordonnées x et y valides.\n");
        } else {
            valide = 1;
        }
    }
}