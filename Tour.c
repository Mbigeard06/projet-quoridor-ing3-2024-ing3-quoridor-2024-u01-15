//
// Created by Bigeard on 11/21/2024.
//

#include "Tour.h"

//Lance le tour d'un joueur
bool Tour(Partie* partie) {
    bool finTour = false;
    //Récupération de l'action
    while(!finTour) {
        //Recuperation de l'action
        int action = ActionIhm(partie->joueurs[partie->indiceJoueur]);

        //Traitement de l'input utilisateurs
        switch (action) {
            case 1:
                if(DeplacerJoueur(partie->joueurs, &partie->plateau, partie->dernierAction)) {
                    //Déplacement réalisé
                    finTour = true;
                    //Tour suivant
                }
                //Deplacement non réussi
                else {
                    return false;
                }
            break;
            case 2:
                // Code pour poser une barrière
                    break;
            case 3:
                // Code pour passer le tour
                    break;
            case 4:
                // Code pour annuler la dernière action
                    break;
            case 5:
                // Code pour sauvegarder et quitter la partie
                    break;
            default:
                // Ce cas ne devrait jamais arriver grâce à la validation de l'entrée
                    printf("Choix invalide.\n");
            break;
        }
    }
}
