//
// Created by Bigeard on 11/16/2024.
//

#ifndef BARRIERE_H
#define BARRIERE_H
#include "Position.h"

//Represente une barriere
typedef struct {
    //Position de la barriere
    Position position;
    //Type v ou h
    char type;
} Barriere;

#endif //BARRIERE_H
