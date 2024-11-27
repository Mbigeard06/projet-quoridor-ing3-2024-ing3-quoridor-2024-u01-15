//
// Created by Bigeard on 11/16/2024.
//

#include "Partie.h"

#include "PartieDao.h"


//Determine si la partie est gagnée par le joueur Fausse pour le moment
bool AGagne(Joueur joueur, int indiceJoueur) {
    bool gagne = false;
    if (indiceJoueur == 0) {
        if(joueur.position.x == TAILLE_PLATEAU - 1) {
            gagne = true;
        }
    }
    else if (indiceJoueur == 1) {
        if(joueur.position.x == 0) {
            gagne = true;
        }
    }
    else if (indiceJoueur == 2) {
        if(joueur.position.y == TAILLE_PLATEAU - 1) {
            gagne = true;
        }
    }
    else {
        if(joueur.position.y == 0) {
            gagne = true;
        }
    }
    return gagne;
}

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
void AttribuerBarrieresEtAnnulation(Joueur* joueurs, int nbJoueur) {
    for (int i = 0; i < nbJoueur; i++) {
        joueurs[i].nbrBarriere = 20 / nbJoueur;
        joueurs[i].annuler = true;
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
    AttribuerBarrieresEtAnnulation(partie->joueurs, partie->nbJoueur);
    printf("%d",partie->joueurs[0].nbrBarriere);
}

//Annule le déplacement d'un joueur
void AnnulerDeplacement(Action lastAction, Joueur* joueur, Action* actionTour, Plateau* plateau) {
    //Recuperation ancienne position
    Position anciennePosition =  lastAction.position;
    //Enregistrement de la position actuelle
    actionTour->position = joueur->position;
    //Modifier la postion du joueur
    SetPostionJoueur(joueur, plateau, actionTour, joueur->position, anciennePosition);
    //Enregistrer l'action
    actionTour->action = Annulation;
}

//Annuler la dernire posde de barriere
void AnnulerBarriere(Action lastAction, Joueur* joueur, Action* actionTour, Plateau* plateau) {
    //Recuperer la barriere
    joueur->nbrBarriere++;
    //Definition de la barriere
    Barriere barriere;
    barriere.position = lastAction.position;
    barriere.direction = lastAction.direction;
    barriere.type = lastAction.typePostion;
    //Annulation barriere
    SetBarriere(plateau, barriere, ' ');
    //Enregistrer l'action
    EnregistrerBarriere(barriere, joueur, actionTour);
    //Enregistrer l'action
    actionTour->action = Annulation;
}

//Annuler la derniere action
bool AnnulerDerniereAction(Joueur* joueur, Plateau* plateau, struct ActionNode*  dernierElement, Action* actionTour) {
    bool res = false;
    if(joueur->annuler) {
        //Le joueur peut annuler une action
        Action lastAction = getLastAction(dernierElement);
        printf("\n last action x : %d , y: %d", lastAction.position.x, lastAction.position.y);
        if(dernierElement != NULL) {
            //Existe une dernire action
            switch (lastAction.action) {
                case Deplacement :
                    printf("case Deplacement");
                    AnnulerDeplacement(lastAction, joueur, actionTour, plateau);
                    res = true;
                break;
                case PoserBarriere:
                    AnnulerBarriere(lastAction, joueur, actionTour, plateau);
                    res = true;
                break;
                case Annulation :
                    printf("Impossible d annuler une annulation");
                    break;
                case Initialisation :
                    printf("Personne n a joue avant vous !");
                    break;
                default:
                    printf("\nLe joueur d'avant à passer son tour, il n y a aucune action a annuler !");
                break;
            }
        }
        else {
            printf("\nAucune action à annuler !");
        }
    }
    else {
        printf("\n Le joueur ne peut plus annuler d'action !");
    }
    return res;
}

//Fonction déclenche quand un joueur gagne2

void FinPartie(Partie partie) {
    printf("\nFelicitation a %s !", partie.joueurs[partie.indiceJoueur].nom);
    printf("\nA bientot pour une prochaine partie !");
    //METTRE à jour le score

}

//Lance le tour d'un joueur =>Renvoi true si tour suivant
bool Tour(Partie* partie) {
    bool tourSuivant = true;
    bool finTour = false;
    while(!finTour) {
        //Récupération de l'action
        Action tourAction;
        //Recuperation de l'action
        int action = ActionIhm(partie->joueurs[partie->indiceJoueur]);

        //Traitement de l'input utilisateurs
        switch (action) {
            case 1:
                if(DeplacerJoueur(&partie->joueurs[partie->indiceJoueur], &partie->plateau, &tourAction)) {
                    //Déplacement réalisé
                    finTour = true;
                    //Enregistrer l'action
                    //Position dans tour action valide !
                    pushAction(tourAction, &partie->dernierAction);
                    if(AGagne(partie->joueurs[partie->indiceJoueur],partie->indiceJoueur)) {
                        //Fin de la partie
                        tourSuivant = false;
                        FinPartie(*partie);
                    }
                }
            break;
            case 2:
                if (PlacerBarriere(&partie->joueurs[partie->indiceJoueur], &partie->plateau, &tourAction)) {
                    //Déplacement réalisé
                    finTour = true;
                    //Enregistrement action
                    pushAction(tourAction, &partie->dernierAction);
                }
                break;
            case 3:
                printf("Le joueur passe son tour");
                //Inaction
                tourAction.action = Inaction;
                //Enregistrement action
                pushAction(tourAction, &partie->dernierAction);
                finTour = true;
                break;
            case 4:
                //Indice du joueur precedent
                int indiceJoueurConcerne = partie->indiceJoueur - 1;
                if(partie->indiceJoueur < 0) {
                    //Annulation demandé par le joueur d'indice 0.
                    indiceJoueurConcerne = partie->nbJoueur - 1;
                }
                if(AnnulerDerniereAction(&partie->joueurs[indiceJoueurConcerne], &partie->plateau, partie->dernierAction, &tourAction)) {
                    pushAction(tourAction, &partie->dernierAction);
                    finTour = true;
                    printf("\nTour suivant");
                }
                break;
            case 5:
                //Sauvegarde la partie
                SauvegarderPartie(partie);
                //Fin du tour
                finTour = true;
                //Pas de tour suivant
                tourSuivant = false;
                break;
            default:
                // Ce cas ne devrait jamais arriver grâce à la validation de l'entrée
                    printf("Choix invalide.\n");
            break;
        }
    }
    return tourSuivant;
}

//Passer au tour suivant. Fonction récursive
void TourSuivant(Partie* partie){
    //On passe au joueur suivant
    if(partie->indiceJoueur < partie->nbJoueur - 1) {
        partie->indiceJoueur++;
    }
    else {
        partie->indiceJoueur = 0;
    }
    AfficherPlateau(&partie->plateau);
    printf("Indice joueur : %d", partie->indiceJoueur);
    if(Tour(partie)) {
        TourSuivant(partie);
    }
};

//Recupere le nom de la partie
void DemanderNomPartie(char* nomPartie) {
    bool end = false;
    while (!end) {
        printf("\nVeuillez entrer le nom de la partie : ");
        if (scanf("%s", nomPartie) != 1) {
            // Si la saisie échoue
            while (getchar() != '\n');  // Vider le tampon pour éliminer la saisie invalide
        }
        else {
            //La saisie réussit
            end = true;
        }
    }
}



//Initialise la partie
Partie* InitialiserPartie() {
    Partie partie;
    //Premier tour, personne n'a joué avant
    partie.indiceJoueur = -1;
    //Initialiser le nom de la partie
    DemanderNomPartie(partie.nomPartie);
    //Initialisation joueur
    InitialiserJoueurs(&partie);
    //Initialisation plateau
    InitialiserPlateau(&partie.plateau,partie.joueurs, partie.nbJoueur);
    //Afficher Plateau
    AfficherPlateau(&partie.plateau);
    //Pas d'action avant
    Action action;
    action.action = Inaction;
    pushAction(action, &partie.dernierAction);
    //Lancement du premier tour
    TourSuivant(&partie);
    return NULL;
}
