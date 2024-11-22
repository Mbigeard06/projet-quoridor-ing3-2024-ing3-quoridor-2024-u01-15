//
// Created by Bigeard on 11/21/2024.
//
#include <stdio.h>
#include "Deplacement.h"


// Renvoie true si le joueur ne sort pas des limites du plateau
bool LimitePlateau(Position position, Plateau* plateau, TypeDeplacement deplacement) {
    bool res = false;

    switch(deplacement) {
        case Haut:
            // Le joueur ne peut pas dépasser la première ligne
                if(position.x > 0) {
                    res = true;
                }
        break;
        case Bas:
            // Le joueur ne peut pas dépasser la dernière ligne
                if(position.x < TAILLE_PLATEAU - 1) {
                    res = true;
                }
        break;
        case Gauche:
            // Le joueur ne peut pas dépasser la première colonne
                if(position.y > 0) {
                    res = true;
                }
        break;
        case Droit:
            // Le joueur ne peut pas dépasser la dernière colonne
                if(position.y < TAILLE_PLATEAU - 1) {
                    res = true;
                }
        break;
        default:
            res = false;
        break;
    }
    return res; // Renvoie true si le déplacement est valide, sinon false
}

// Vérifie si une barrière est présente devant le joueur dans la direction du déplacement
bool VerifierBarriere(Position position, Plateau* plateau, TypeDeplacement deplacement) {
    bool barriereDevant = false;

    switch(deplacement) {
        case Haut:
            // Vérifier si une barrière existe juste au-dessus du joueur
                if (plateau->barriereHorizontal[position.x - 1][position.y] == 'b') {
                    barriereDevant = true;
                }
        break;
        case Bas:
            // Vérifier si une barrière existe juste en-dessous du joueur
                if (plateau->barriereHorizontal[position.x][position.y] == 'b') {
                    barriereDevant = true;
                }
        break;
        case Gauche:
            // Vérifier si une barrière existe à gauche du joueur
                if (plateau->barriereVerticale[position.x][position.y - 1] == 'b') {
                    barriereDevant = true;
                }
        break;
        case Droit:
            // Vérifier si une barrière existe à droite du joueur
                if (plateau->barriereVerticale[position.x][position.y] == 'b') {
                    barriereDevant = true;
                }
        break;
        default:
            barriereDevant = false;
        break;
    }
    return barriereDevant;
}

// Vérifie si une barrière est présente devant le joueur dans la direction du déplacement
bool VerifierJoueur(Position position, Plateau* plateau, TypeDeplacement deplacement) {
    bool JoueurDevant = false;

    switch(deplacement) {
        case Haut:
                if (plateau->plateau[position.x - 1][position.y] != ' ') {
                    JoueurDevant = true;
                }
        break;
        case Bas:
                if (plateau->plateau[position.x + 1][position.y] != 'b') {
                    JoueurDevant = true;
                }
        break;
        case Gauche:
                if (plateau->barriereVerticale[position.x][position.y - 1] != ' ') {
                    JoueurDevant = true;
                }
        break;
        case Droit:
            // Vérifier si il y a un joueur à droite
                if (plateau->plateau[position.x][position.y + 1] != ' ') {
                    JoueurDevant = true;
                }
        break;
        default:
            JoueurDevant = false;
        break;
    }
    return JoueurDevant;
}


bool VerifierDeplacement(Joueur* joueur, Plateau* plateau, TypeDeplacement deplacement) {
    bool res = false;
    //Le joueur reste dans les limites du plateau
    if(LimitePlateau(joueur->position, plateau, deplacement)) {
        //Pas de barriere devant
        if(!VerifierBarriere(joueur->position, plateau, deplacement)) {
            //Pas de joueur dans la case
            if(!VerifierJoueur(joueur->position, plateau, deplacement)) {
                res = true;
            }
            else {
                //Implémenter logique
            }
        }
        else {
            printf("\nDéplacement impossible, vous ne pouvez pas passer par dessus une barriere");
        }
    }
    else {
        printf("\nDéplacement impossible, vous debez rester dans les limites du tableau");
    }
}

//Renvoi true si le déplacement à abouti et false sinon
bool DeplacerJoueur(Joueur* joueur, Plateau* plateau, Action* lastAction) {
    bool res = false;
    //Recupérer le type de déplacement
    TypeDeplacement choixDeplacement =  AfficherDeplacement();
    //Le joueur à choisi un déplacement
    if(choixDeplacement != Sortie) {
        if(VerifierDeplacement(joueur, plateau, choixDeplacement)) {
            //On enregistre dans la last action la postion du joueur
            lastAction->position = joueur->position;
            //Mettre à jour nouvelle position joueur
            joueur->position = CalculerPosition(joueur->position, choixDeplacement);
            //Mettre à jour le plateau
            PlacerPion(plateau, joueur->position, joueur);
        }
    }
    return res;
}

