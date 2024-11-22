//
// Created by Bigeard on 11/16/2024.
//

#include "Plateau.h"
#include <stdio.h>




// Fonction principale pour initialiser les joueurs sur le plateur
void InitialiserJoueursPlateau(Joueur* joueurs, int nbJoueur, Plateau *plateau) {
    // Définir les positions de base des joueurs (en fonction du nombre de joueurs)
    Position positions[] = {
        {0, 4},  // Joueur 1 (haut du plateau)171

        {TAILLE_PLATEAU - 1, 4},  // Joueur 2 (bas du plateau)
        {4, 0},  // Joueur 3 (gauche du plateau)
        {4, TAILLE_PLATEAU - 1}  // Joueur 4 (droite du plateau)
    };

    // Initialiser les joueurs sur le plateau en utilisant une boucle
    for (int i = 0; i < nbJoueur; i++) {
        PlacerPion(plateau, positions[i], &joueurs[i]);  // Placer le pion sur le plateau
        SetJoueurPosition(&joueurs[i], positions[i]);    // Mettre à jour la position du joueur
    }
}

// Initialiser le plateau avec des cases vides
void InitialiserPlateau(Plateau *p, Joueur *joueurs, int nbJoueurs) {
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            p->plateau[i][j] = ' '; // Case vide
            p->barriereHorizontal[i][j] = ' ';
            p->barriereVerticale[i][j] = ' ';
        }
    }
    InitialiserJoueursPlateau(joueurs, nbJoueurs, p);
}

// Placer un pion sur le plateau
void PlacerPion(Plateau *p, Position pos, Joueur* joueur) {
    p->plateau[pos.x][pos.y] = joueur->pion;
}


//Placer une barriere
void PlacerBarriere(Plateau *p, Barriere barriere) {
    if(barriere.type == 'h') {
        for(int i = 0; i < 2; i++) {
            p->barriereHorizontal[barriere.position.x][barriere.position.y + i] = 'b';
        }
    }
    else {
        for(int i = 0; i < 2; i++) {
            p->barriereVerticale[barriere.position.x + i][barriere.position.y] = 'b';
        }
    }
}


// Afficher le plateau de jeu avec des bordures et séparations
void AfficherPlateau(Plateau *p) {

    printf("\n    ");
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        printf(" %d  ", i);  // Affiche les numéros de colonne en haut
    }
    printf("\n   +");
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        printf("---+");
    }
    printf("\n");

    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        printf(" %d |", i);  // Affiche les numéros de ligne à gauche
        //Vertical
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            if(p->barriereVerticale[i][j] == 'b') {
                printf(" %c b", p->plateau[i][j]);
            }
            else {
                printf(" %c |", p->plateau[i][j]);
            }
        }
        printf("\n   +");
        //Horizontal
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            if(p->barriereHorizontal[i][j] == 'b') {
                printf(" b +");
            }
            else {
                printf("---+");
            }

        }
        printf("\n");
    }
}

//Determine si la partie est gagnée par le joueur
bool AGagne(Joueur joueur, int indiceJoueur) {
    if (indiceJoueur == 1) {
        if(joueur.position.x == TAILLE_PLATEAU - 1) {
            return true;
        }
    }
    else if (indiceJoueur == 2) {
        if(joueur.position.x == 0) {
            return true;
        }
    }
    else if (indiceJoueur == 3) {
        if(joueur.position.y == TAILLE_PLATEAU - 1) {
            return true;
        }
    }
    else {
        if(joueur.position.y == 0) {
            return true;
        }
    }
}

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


