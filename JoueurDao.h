//
// Created by Bigeard on 11/18/2024.
//

#ifndef JOUEURDAO_H
#define JOUEURDAO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FICHIER_SCORES "scores.txt"

//Initialise/Modifie le score d'un joueur
void EnregistrerOuAjouterScore(const char* pseudo, int nouveauScore);
//Recupere le score d'un joueur
int RecupererScore(const char* pseudo);
//Affiche les scores
void AfficherTousLesScores();
#endif //JOUEURDAO_H
