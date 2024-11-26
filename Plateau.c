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

// Placer/Enlever une barrière
void SetBarriere(Plateau *p, Barriere barriere, char visuel) {
    switch (barriere.direction) {
        case Haut:
            // Placer une barrière dans la direction "Haut"
                for (int i = 0; i > -2; i--) {
                    p->barriereVerticale[barriere.position.x + i][barriere.position.y] = visuel;
                }
        break;

        case Bas:
            // Placer une barrière dans la direction "Bas"
                for (int i = 0; i < 2; i++) {
                    p->barriereVerticale[barriere.position.x + i][barriere.position.y] = visuel;
                }
        break;

        case Gauche:
            // Placer une barrière dans la direction "Gauche"
                for (int i = 0; i > -2; i--) {
                    p->barriereHorizontal[barriere.position.x][barriere.position.y + i] = visuel;
                }
        break;

        case Droit:
            // Placer une barrière dans la direction "Droit"
                for (int i = 0; i < 2; i++) {
                    p->barriereHorizontal[barriere.position.x][barriere.position.y + i] = visuel;
                }
        break;

        default:
            printf("Direction invalide pour la barrière.\n");
        break;
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

// Renvoie true si le joueur ne sort pas des limites du plateau
bool LimitePlateau(Position position, Plateau* plateau, Direction deplacement) {
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
bool VerifierBarriere(Position position, Plateau* plateau, Direction deplacement) {
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
bool VerifierJoueur(Position position, Plateau* plateau, Direction deplacement) {
    bool JoueurDevant = false;

    switch(deplacement) {
        case Haut:
                if (plateau->plateau[position.x - 1][position.y] != ' ') {
                    JoueurDevant = true;
                }
        break;
        case Bas:
                if (plateau->plateau[position.x + 1][position.y] != ' ') {
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

void EnregistrerDeplacement(Joueur* joueur, Position oldPosition,Action* lastAction) {
    //On enregistre l'action
    lastAction->position = oldPosition;
    lastAction->joueur = joueur;
    lastAction->typePostion =' ';
    lastAction->action = Deplacement;
}

//Enregistre la barriere dans la dernier action
void EnregistrerBarriere(Barriere barriere,Joueur* joueur, Action* lastAction) {
    //On enregistre l'action
    lastAction->position = barriere.position;
    lastAction->joueur = joueur;
    lastAction->typePostion = barriere.type;
    lastAction->action = Deplacement;
    lastAction->direction = barriere.direction;
}

//Attribuer une nouvelle position au joueur
void SetPostionJoueur(Joueur* joueur, Plateau* plateau, Action* lastAction, Position oldPosition, Position newPosition) {
    //Enregistrement de l'action
    EnregistrerDeplacement(joueur, oldPosition, lastAction);
    //Changer la position du joueur
    plateau->plateau[oldPosition.x][oldPosition.y] = ' ';

    //Calculer nouvelle position
    joueur->position = newPosition;

    //Placer le joueur sur le plateau
    PlacerPion(plateau, joueur->position, joueur);
}

//Sautuer un joueur. => true si le joueur à pu être sauté correctement
bool SauterJoueur(Joueur* joueur, Plateau* plateau, Direction deplacement, Action* lastAction) {
    bool res = false;
    //Prendre la place du joueur sauter pour calculer les déplacements possible
    Position newPosition = CalculerPosition(joueur->position, deplacement);
    //Enregistrement de l'ancienne position
    Position oldPosition = joueur->position;
    //Attribution nouvelle position
    joueur->position = newPosition;
    //Si le déplacement est valide
    if(LimitePlateau(joueur->position, plateau, deplacement) && !VerifierBarriere(joueur->position, plateau, deplacement) && !VerifierJoueur(joueur->position, plateau, deplacement))  {
        printf("Deplacement valide !");

        //Attribuer nouveau déplacement
        SetPostionJoueur(joueur, plateau, lastAction, oldPosition, CalculerPosition(joueur->position, deplacement));

        //Action validé
        res = true;
    }
    else {
        printf("La case qui suit le joueur est inaccessible, veuillez bifurquer !");
        //Recupérer le type de déplacement
        bool sortir = false;
        while(!sortir) {
            Direction choixDeplacement =  AfficherDeplacement();
            //Le joueur à choisi un déplacement
            if(choixDeplacement != Sortie) {
                printf("Dans le if");
                if(LimitePlateau(joueur->position, plateau, choixDeplacement) && !VerifierBarriere(joueur->position, plateau, choixDeplacement) && !VerifierJoueur(joueur->position, plateau, choixDeplacement)) {
                    //Deplacement validé
                    printf("\nDeplacement valide");

                    //Attribuer nouveau déplacement
                    SetPostionJoueur(joueur, plateau, lastAction, oldPosition, CalculerPosition(joueur->position, choixDeplacement));

                    //Action validé
                    res = true;
                    sortir = true;
                }
            }
            //L'utilisateur ne veut plus se déplacer
            else {
                printf("\nIl veut sortir");
                joueur->position = oldPosition;
                sortir = true;
            }
        }
    }
    return res;
}

//0 si erreur 1 si reussi 2 si sauté
int VerifierDeplacement(Joueur* joueur, Plateau* plateau, Direction deplacement) {
    int res = 0;
    //Le joueur reste dans les limites du plateau
    if(LimitePlateau(joueur->position, plateau, deplacement)) {
        //Pas de barriere devant
        if(!VerifierBarriere(joueur->position, plateau, deplacement)) {
            //Pas de joueur dans la case
            if(!VerifierJoueur(joueur->position, plateau, deplacement)) {
                res = 1;
            }
            //Joeur à sauter
            else {
                res = 2;
            }
        }
        else {
            printf("\nDéplacement impossible, vous ne pouvez pas passer par dessus une barriere");
        }
    }
    else {
        printf("\nDéplacement impossible, vous debez rester dans les limites du tableau");
    }
    return res;
}

//Renvoi true si le déplacement à abouti et false sinon
bool DeplacerJoueur(Joueur* joueur, Plateau* plateau, Action* lastAction) {

    printf("Deplacer Joueur | Position actuelle x : %d  y : %d\n", joueur->position.x, joueur->position.y);
    bool res = false;
    bool sortir = false;

    while(!sortir) {

        //Recupérer le type de déplacement
        Direction choixDeplacement =  AfficherDeplacement();

        if(choixDeplacement != Sortie) {
            //Deplacement selectionné
            int verifierDeplacement = VerifierDeplacement(joueur, plateau, choixDeplacement);
            if(verifierDeplacement == 1) {
                printf("\nDeplacement valide");

                //Attribution nouvelle position
                SetPostionJoueur(joueur, plateau, lastAction, joueur->position, CalculerPosition(joueur->position, choixDeplacement));

                printf("\nNouvelle position x : %d, y : %d", joueur->position.x, joueur->position.y);

                //Action validé
                res = true;
                sortir = true;
            }
            else if(verifierDeplacement == 2) {
                bool sauterJoueur = SauterJoueur(joueur, plateau, choixDeplacement, lastAction);
                if(sauterJoueur) {
                    res = true;
                    sortir = true;
                }
                else {
                    //Saut annulé
                    printf("L utilisateur n a pas pu sauter");
                    sortir = true;
                }
            }
        }
        //Retour au menu d'action
        else {
            printf("L utilisateur ne veut plus se déplacer");
            sortir = true;
        }
        AfficherPlateau(plateau);
    }
    return res;
}

//Verifie qu'une barriere est dans les limites
bool VerifierBarriereLimites(Plateau* plateau, Barriere barriere) {
    bool res = false;
    if(barriere.type == 'v') {
        //Barriere verticale
        if((0 <= barriere.position.x && 8 >= barriere.position.x) && (0 <= barriere.position.y && 7 >= barriere.position.y) ) {
            //X[0,8] et Y[0,7]
            if(barriere.direction == Haut) {
                if(barriere.position.x - 1 >= 0) {
                    res = true;
                }
            }
            else {
                if(barriere.position.x + 1 <= 8) {
                    res = true;
                }
            }
        }
    }
    if(barriere.type == 'h') {
        //Barriere verticale
        if((0 <= barriere.position.x && 7 >= barriere.position.x) && (0 <= barriere.position.y && 8 >= barriere.position.y) ) {
            //X[0,8] et Y[0,7]
            if(barriere.direction == Gauche) {
                if(barriere.position.y - 1 >= 0) {
                    res = true;
                }
            }
            else {
                if(barriere.position.y + 1 <= 8) {
                    res = true;
                }
            }
        }
    }
    return res;
}


//=>True si le joueur à la portée
bool PeutPlacerBarriere(Joueur* joueur, Barriere barriere) {
    bool res = false;
    if(barriere.type == 'h') {
        if((barriere.position.y == joueur->position.y) && ( (barriere.position.x == joueur->position.x) || (barriere.position.x == joueur->position.x -1) ) ) {
            res = true;
        }
    }
    else {
        if((barriere.position.x == joueur->position.x) && ( (barriere.position.y == joueur->position.y) || (barriere.position.y == joueur->position.y -1))) {
            res = true;
        }
    }
    return res;
}



//=>true si la barriere peut être placée
bool VerifierPlacementBarriere(Joueur* joueur, Plateau* plateau, Barriere barriere) {
    bool res = false;
    if(VerifierBarriereLimites(plateau, barriere)) {
        //Barriere dans les limites
        if(PeutPlacerBarriere(joueur, barriere)) {
            res = true;
            printf("\nBarriere pose avec succes !");
        }
        else {
            printf("\nCase hors de portee, rapprochez vous pour mettre une barriere");
        }
    }
    else {
        printf("\nVous ne pouvez pas mettre une barriere ici, la barriere doit rester dans les limites de la map !");
    }
    return res;
}



//=>true si la barriere à été placée
bool PlacerBarriere(Joueur* joueur, Plateau* plateau, Action* lastAction) {
    bool res = false;
    bool sortir = false;
    if(joueur->nbrBarriere < 1) {
        printf("\n Vous ne possedez plus de barriere !");
        sortir = true;
    }
    while (!sortir) {
        Barriere barriere;
        if(BarriereIhm(joueur, &barriere)) {
            //Annulation de la pose de barriere
            printf("\n Retour au menu d'action");
            sortir = true;
        }
        else {
            if(VerifierPlacementBarriere(joueur, plateau, barriere)) {
                printf("\n Barriere mise avec succes !");
                SetBarriere(plateau, barriere, 'b');

                //Une barriere en moins
                joueur->nbrBarriere--;
                //Enregistrement de l'action barriere
                EnregistrerBarriere(barriere, joueur, lastAction);
                res = true;
                sortir = true;
            }
            else {
                printf("\nPlacer une autre barriere !");
            }
        }
    }
    AfficherPlateau(plateau);
    return res;
}


