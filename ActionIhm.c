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
        printf("\nVotre choix : ");

        // Vérification de la validité de l'entrée
        if(scanf("%d", &choix) != 1) {
            // Si l'entrée n'est pas un entier, vider le tampon et afficher un message d'erreur
            while (getchar() != '\n'); // Vider le tampon
            printf("Entree invalide. Veuillez saisir un nombre entier entre 1 et 4.\n");
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