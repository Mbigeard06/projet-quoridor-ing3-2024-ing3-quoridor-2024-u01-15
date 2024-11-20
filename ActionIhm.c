//
// Created by Bigeard on 11/20/2024.
//

#include "ActionIhm.h"

// Renvoie le choix du joueur avec gestion des erreurs d'entrée
int ActionIhm(Joueur joueur) {
    int choix = 0;
    int valide = 0; // Variable pour vérifier si l'entrée est valide
    while(!valide) {
        printf("\nTour du joueur : %s | Nombre de barrières disponibles : %d", joueur.nom, joueur.nbrBarriere);
        printf("\n1/ Déplacer son pion");
        printf("\n2/ Poser une barrière");
        printf("\n3/ Passer son tour");
        printf("\n4/ Annuler la dernière action");
        printf("\nVotre choix : ");

        // Vérification de la validité de l'entrée
        if(scanf("%d", &choix) != 1) {
            // Si l'entrée n'est pas un entier, vider le tampon et afficher un message d'erreur
            while (getchar() != '\n'); // Vider le tampon
            printf("Entrée invalide. Veuillez saisir un nombre entier entre 1 et 4.\n");
        } else if (choix < 1 || choix > 4) {
            // Si l'entrée n'est pas dans la plage valide
            printf("Choix invalide. Veuillez saisir un nombre entre 1 et 4.\n");
        } else {
            // Si l'entrée est valide, on sort de la boucle
            valide = 1;
        }
    }
    return choix;
}