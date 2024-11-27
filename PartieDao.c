//
// Created by Bigeard on 11/18/2024.
//

#include "PartieDao.h"

//Sauvegarder une partie :
void SauvegarderPartie(const Partie* partie) {
    FILE* fichier = fopen(FICHIER_SAUVEGARDE, "w"); // Ouvrir en mode écriture
    if (!fichier) {
        printf("Erreur : impossible d'ouvrir le fichier %s pour la sauvegarde.\n", FICHIER_SAUVEGARDE);
        return;
    }

    // Sauvegarder le nom de la partie
    fprintf(fichier, "\nNomPartie: %s\n", partie->nomPartie);

    // Sauvegarder l'indice du joueur courant et le nombre de joueurs
    fprintf(fichier, "IndiceJoueur: %d\n", partie->indiceJoueur);
    fprintf(fichier, "NbJoueur: %d\n", partie->nbJoueur);

    // Sauvegarder les informations sur le plateau
    fprintf(fichier, "Plateau:\n");
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            fprintf(fichier, "%c", partie->plateau.plateau[i][j]);
        }
        fprintf(fichier, "\n");
    }

    // Sauvegarder les barrières horizontales
    fprintf(fichier, "BarriereHorizontal:\n");
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            fprintf(fichier, "%c", partie->plateau.barriereHorizontal[i][j]);
        }
        fprintf(fichier, "\n");
    }

    // Sauvegarder les barrières verticales
    fprintf(fichier, "BarriereVerticale:\n");
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            fprintf(fichier, "%c", partie->plateau.barriereVerticale[i][j]);
        }
        fprintf(fichier, "\n");
    }

    // Sauvegarder les joueurs
    fprintf(fichier, "Joueurs:\n");
    for (int i = 0; i < partie->nbJoueur; i++) {
        Joueur* joueur = &partie->joueurs[i];
        fprintf(fichier, "Nom: %s\n", joueur->nom);
        fprintf(fichier, "Pion: %c\n", joueur->pion);
        fprintf(fichier, "Score: %d\n", joueur->score);
        fprintf(fichier, "Position: %d %d\n", joueur->position.x, joueur->position.y);
        fprintf(fichier, "NbrBarriere: %d\n", joueur->nbrBarriere);
        fprintf(fichier, "Annuler: %d\n", joueur->annuler);
    }

    fclose(fichier); // Fermer le fichier
    //Quitter la partie
    Quitter(partie);
}

bool ChargerPartie(Partie* partie) {
    bool res = true;
    printf("[DEBUG] Début de la fonction ChargerPartie.\n");

    FILE* fichier = fopen(FICHIER_SAUVEGARDE, "r"); // Ouvrir en mode lecture
    if (!fichier) {
        printf("Erreur : impossible d'ouvrir le fichier %s pour le chargement.\n", FICHIER_SAUVEGARDE);
        return false; // Retour immédiat si le fichier n'existe pas
    }

    if (!partie) {
        printf("Erreur : allocation mémoire pour la partie.\n");
        fclose(fichier);
        return false;
    }

    printf("[DEBUG] Fichier ouvert avec succès.\n");

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        printf("[DEBUG] Lecture de la ligne : %s", ligne);

        // Supprimer le '\n' à la fin de la ligne si présent
        size_t len = strlen(ligne);
        if (len > 0 && ligne[len - 1] == '\n') {
            ligne[len - 1] = '\0';
        }

        // Analyse des données sauvegardées
        if (strncmp(ligne, "NomPartie: ", 11) == 0) {
            strncpy(partie->nomPartie, ligne + 11, sizeof(partie->nomPartie));
            printf("[DEBUG] Nom de la partie : %s\n", partie->nomPartie);
        } else if (strncmp(ligne, "IndiceJoueur: ", 14) == 0) {
            partie->indiceJoueur = atoi(ligne + 14);
            printf("[DEBUG] Indice du joueur : %d\n", partie->indiceJoueur);
        } else if (strncmp(ligne, "NbJoueur: ", 10) == 0) {
            partie->nbJoueur = atoi(ligne + 10);
            printf("[DEBUG] Nombre de joueurs : %d\n", partie->nbJoueur);

            partie->joueurs = calloc(partie->nbJoueur, sizeof(Joueur));
            if (!partie->joueurs) {
                printf("Erreur : allocation mémoire pour les joueurs.\n");
                fclose(fichier);
                return false;
            }
        } else if (strcmp(ligne, "Plateau:") == 0) {
            printf("[DEBUG] Chargement du plateau...\n");
            for (int i = 0; i < TAILLE_PLATEAU; i++) {
                fgets(ligne, sizeof(ligne), fichier);
                strncpy(partie->plateau.plateau[i], ligne, TAILLE_PLATEAU);
            }
            printf("[DEBUG] Plateau chargé.\n");
        } else if (strcmp(ligne, "BarriereHorizontal:") == 0) {
            printf("[DEBUG] Chargement des barrières horizontales...\n");
            for (int i = 0; i < TAILLE_PLATEAU; i++) {
                fgets(ligne, sizeof(ligne), fichier);
                strncpy(partie->plateau.barriereHorizontal[i], ligne, TAILLE_PLATEAU);
            }
            printf("[DEBUG] Barrières horizontales chargées.\n");
        } else if (strcmp(ligne, "BarriereVerticale:") == 0) {
            printf("[DEBUG] Chargement des barrières verticales...\n");
            for (int i = 0; i < TAILLE_PLATEAU; i++) {
                fgets(ligne, sizeof(ligne), fichier);
                strncpy(partie->plateau.barriereVerticale[i], ligne, TAILLE_PLATEAU);
            }
            printf("[DEBUG] Barrières verticales chargées.\n");
        } else if (strcmp(ligne, "Joueurs:") == 0) {
    printf("[DEBUG] Chargement des joueurs...\n");
    for (int i = 0; i < partie->nbJoueur; i++) {
        Joueur* joueur = &partie->joueurs[i];

        // Lecture du nom
        if (!fgets(ligne, sizeof(ligne), fichier)) {
            printf("[ERREUR] Échec de lecture du nom pour le joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        if (sscanf(ligne, "Nom: %s", joueur->nom) != 1) {
            printf("[ERREUR] Format incorrect pour le nom du joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        printf("[DEBUG] Joueur %d : Nom : %s\n", i + 1, joueur->nom);

        // Lecture du pion
        if (!fgets(ligne, sizeof(ligne), fichier)) {
            printf("[ERREUR] Échec de lecture du pion pour le joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        if (sscanf(ligne, "Pion: %c", &joueur->pion) != 1) {
            printf("[ERREUR] Format incorrect pour le pion du joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        printf("[DEBUG] Joueur %d : Pion : %c\n", i + 1, joueur->pion);

        // Lecture du score
        if (!fgets(ligne, sizeof(ligne), fichier)) {
            printf("[ERREUR] Échec de lecture du score pour le joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        if (sscanf(ligne, "Score: %d", &joueur->score) != 1) {
            printf("[ERREUR] Format incorrect pour le score du joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        printf("[DEBUG] Joueur %d : Score : %d\n", i + 1, joueur->score);

        // Lecture de la position
        if (!fgets(ligne, sizeof(ligne), fichier)) {
            printf("[ERREUR] Échec de lecture de la position pour le joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        if (sscanf(ligne, "Position: %d %d", &joueur->position.x, &joueur->position.y) != 2) {
            printf("[ERREUR] Format incorrect pour la position du joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        printf("[DEBUG] Joueur %d : Position : (%d, %d)\n", i + 1, joueur->position.x, joueur->position.y);

        // Lecture du nombre de barrières
        if (!fgets(ligne, sizeof(ligne), fichier)) {
            printf("[ERREUR] Echec de lecture du nombre de barrières pour le joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        if (sscanf(ligne, "NbrBarriere: %d", &joueur->nbrBarriere) != 1) {
            printf("[ERREUR] Format incorrect pour le nombre de barrières du joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        printf("[DEBUG] Joueur %d : Barrières : %d\n", i + 1, joueur->nbrBarriere);

        // Lecture de la capacité d'annulation
        if (!fgets(ligne, sizeof(ligne), fichier)) {
            printf("[ERREUR] Échec de lecture de la capacité d'annulation pour le joueur %d.\n", i + 1);
            fclose(fichier);
            return false;
        }
        joueur->annuler = true;
        printf("[DEBUG] Joueur %d : Annuler : %d\n", i + 1, joueur->annuler);
    }
    printf("[DEBUG] Tous les joueurs ont été chargés.\n");
    }
    }
    fclose(fichier);

    //Pas d'action avant
    Action action;
    action.action = Inaction;
    pushAction(action, &partie->dernierAction);

    printf("[DEBUG] Fin de la fonction ChargerPartie.\n");
    return res;
}