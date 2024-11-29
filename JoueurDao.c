
#include "JoueurDao.h"

// Met à jour ou ajoute le score d'un joueur
void EnregistrerOuAjouterScore(const char* pseudo, int nouveauScore) {
    FILE* fichier = fopen(FICHIER_SCORES, "r+"); // Ouvre en lecture/écriture
    if (!fichier) {
        // Si le fichier n'existe pas encore, créer un nouveau fichier
        fichier = fopen(FICHIER_SCORES, "w");
        if (!fichier) {
            fprintf(stderr, "Erreur : impossible d'ouvrir ou de créer le fichier %s.\n", FICHIER_SCORES);
            return;
        }
    }

    char ligne[256];
    char joueurPseudo[50];
    int joueurScore = 0;
    int joueurExiste = 0;

    // Créer un fichier temporaire pour stocker les données mises à jour
    FILE* fichierTemp = fopen("temp.txt", "w");
    if (!fichierTemp) {
        fprintf(stderr, "Erreur : impossible de créer le fichier temporaire.\n");
        fclose(fichier);
        return;
    }

    // Parcourt le fichier existant
    while (fgets(ligne, sizeof(ligne), fichier)) {
        sscanf(ligne, "%s %d", joueurPseudo, &joueurScore);
        if (strcmp(joueurPseudo, pseudo) == 0) {
            // Si le joueur existe, on met à jour son score
            joueurScore += nouveauScore;
            joueurExiste = 1;
            printf("[DEBUG] Mise à jour : %s - Nouveau score : %d\n", joueurPseudo, joueurScore);
        }
        // Écrit la ligne (mise à jour ou non) dans le fichier temporaire
        fprintf(fichierTemp, "%s %d\n", joueurPseudo, joueurScore);
    }

    // Si le joueur n'existe pas encore, l'ajouter à la fin
    if (!joueurExiste) {
        fprintf(fichierTemp, "%s %d\n", pseudo, nouveauScore);
        printf("[DEBUG] Ajout du joueur : %s - Score : %d\n", pseudo, nouveauScore);
    }

    // Fermer les fichiers
    fclose(fichier);
    fclose(fichierTemp);

    // Remplacer le fichier original par le fichier temporaire
    remove(FICHIER_SCORES);
    rename("temp.txt", FICHIER_SCORES);
}

// Récupère le score d'un joueur à partir de son pseudo
int RecupererScore(const char* pseudo) {
    FILE* fichier = fopen(FICHIER_SCORES, "r");
    if (!fichier) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s pour la récupération des scores.\n", FICHIER_SCORES);
        return 0;
    }

    char ligne[256];
    char joueurPseudo[50];
    int joueurScore = 0;

    while (fgets(ligne, sizeof(ligne), fichier)) {
        sscanf(ligne, "%s %d", joueurPseudo, &joueurScore);
        if (strcmp(joueurPseudo, pseudo) == 0) {
            fclose(fichier);
            return joueurScore;
        }
    }

    fclose(fichier);
    return 0;
}

// Fonction pour afficher les scores de tous les joueurs
void AfficherTousLesScores() {
    FILE* fichier = fopen(FICHIER_SCORES, "r");
    if (!fichier) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s pour afficher les scores.\n", FICHIER_SCORES);
        return;
    }

    char ligne[256];
    char joueurPseudo[50];
    int joueurScore;

    printf("=== Scores des Joueurs ===\n");
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (sscanf(ligne, "%s %d", joueurPseudo, &joueurScore) == 2) {
            printf("Pseudo : %s | Score : %d\n", joueurPseudo, joueurScore);
        } else {
            fprintf(stderr, "[AVERTISSEMENT] Ligne mal formatée ignorée : %s", ligne);
        }
    }

    fclose(fichier);
}
