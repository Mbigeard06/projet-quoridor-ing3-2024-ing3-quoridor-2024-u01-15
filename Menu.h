//
// Created by Bigeard on 11/16/2024.
//

#ifndef MENU_H
#define MENU_H


//Afficher le menu
int menuIhm();
//Lancer le menu
void menu();
//Lancer une nouvelle partie
void NouvellePartie();
//Charger une ancienne partie
void ChargerPartie(char nomPartie[40]);
//Afficher les scores des joueurs
void AfficherScoreJoueur(char nomPartie[40]);
#endif //MENU_H
