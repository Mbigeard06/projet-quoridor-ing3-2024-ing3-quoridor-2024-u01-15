//
// Created by Bigeard on 11/18/2024.
//

#ifndef PARTIEDAO_H
#define PARTIEDAO_H
#include "Partie.h"
#define FICHIER_SAUVEGARDE "Sauvegarde.txt" // Taille maximale du nom de la partie

//Charge une partie
bool ChargerPartie(Partie* partie);
//Sauvegarder une partie :
void SauvegarderPartie(const Partie* partie);
#endif //PARTIEDAO_H
