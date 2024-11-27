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
        printf("\n5/ Sauvegarder et quitter la partie");
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
bool BarriereIhm(Joueur* joueur, Barriere* barriere) {
    int valide = 0;
    int choixType = 0;
    bool abandon = false;

    // Demander le type de la barrière
    while (!valide) {
        printf("\n| Nombre de barrieres disponibles : %d", joueur->nbrBarriere);
        printf("\n1/ Poser une barriere horizontale");
        printf("\n2/ Poser une barrière verticale");
        printf("\n3/ Effectuer une autre action");
        printf("\nVotre choix : ");

        if (scanf("%d", &choixType) != 1) {
            // Vider le tampon en cas d'entrée invalide
            while (getchar() != '\n');
            printf("Entree invalide. Veuillez saisir 1 ou 2.\n");
        }
        else if (choixType == 3) {
            // Annulation de la pose de la barrière
            abandon = true;
            valide = 1;
        }
        else if (choixType < 1 || choixType > 3) {
            // Vérification que l'entrée est dans la plage
            printf("Choix invalide. Veuillez saisir 1 pour horizontal ou 2 pour vertical.\n");
        }
        else {
            // Si l'entrée est valide, on sort de la boucle
            valide = 1;
        }
    }

    // Affecter le type de la barrière
    if (choixType == 1) {
        barriere->type = 'h';  // Horizontale
    } else if (choixType == 2) {
        barriere->type = 'v';  // Verticale
    }

    // Demander la direction de la barrière en fonction de son type
    if(choixType != 3) {
        valide = 0;
        char direction;
        while (!valide) {
            if (barriere->type == 'h') {
                printf("\nChoisissez la direction de la barrière horizontale :\n");
                printf("g : Gauche\n");
                printf("d : Droite\n");
                printf("Votre choix : ");
                if (scanf(" %c", &direction) != 1 || (direction != 'g' && direction != 'd')) {
                    while (getchar() != '\n');  // Vider le tampon
                    printf("Entrée invalide. Veuillez saisir 'g' pour gauche ou 'd' pour droite.\n");
                } else {
                    if(direction == 'g') {
                        barriere->direction = Gauche;
                    }
                    else {
                        barriere->direction = Droit;
                    }
                    valide = 1;
                }
            } else if (barriere->type == 'v') {
                printf("\nChoisissez la direction de la barrière verticale :\n");
                printf("h : Haut\n");
                printf("b : Bas\n");
                printf("Votre choix : ");
                if (scanf(" %c", &direction) != 1 || (direction != 'h' && direction != 'b')) {
                    while (getchar() != '\n');  // Vider le tampon
                    printf("Entree invalide. Veuillez saisir 'h' pour haut ou 'b' pour bas.\n");
                } else {
                    if (direction == 'h') {
                        barriere->direction = Haut;
                    } else {
                        barriere->direction = Bas;
                    }
                    valide = 1;
                }
            }
        }
        // Récupérer position barrière
        valide = 0;
        while (!valide) {
            printf("\nVeuillez entrer la position de la barriere (x, y) : ");
            if (scanf("%d %d", &barriere->position.x, &barriere->position.y) != 2) {
                while (getchar() != '\n');
                printf("Entree invalide. Veuillez saisir des coordonnees x et y valides.\n");
            } else {
                valide = 1;
            }
        }
    }
    return abandon;
}