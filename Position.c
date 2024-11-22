//
// Created by Bigeard on 11/21/2024.
//
#include <stdio.h>
#include "Position.h"

//Calculer la position
Position CalculerPosition(Position position, TypeDeplacement deplacement) {
    Position newPosition = position;
    switch (deplacement) {
        case Haut:
            newPosition.x -= 1;
        break;
        case  Bas:
            newPosition.x += 1;
        break;
        case Gauche:
            newPosition.y -= 1;
        break;
        case Droit:
            newPosition.y += 1;
        break;
    }
    return newPosition;
}