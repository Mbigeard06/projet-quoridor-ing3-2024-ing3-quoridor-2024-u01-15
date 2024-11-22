//
// Created by Bigeard on 11/16/2024.
//

#ifndef POSITION_H
#define POSITION_H
#include "Deplacement.h"

//Represente une position sur le plateau
typedef struct {
    int x;
    int y;
} Position;

//Calcule la nouvelle position suite à un déplacement
Position CalculerPosition(Position position, TypeDeplacement deplacement);
#endif //POSITION_H
