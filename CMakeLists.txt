cmake_minimum_required(VERSION 3.29)
project(Quoridor2024)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quoridor2024
        Joueur.c
        Joueur.h
        Position.h
        Action.h
        Action.h
        Barriere.h
        Plateau.c
        Plateau.h
        Menu.h
        Partie.c
        Partie.h
        Deplacement.h
        Menu.c
        main.c
        JoueurDao.c
        JoueurDao.h
        PartieDao.c
        PartieDao.h
        ActionIhm.c
        ActionIhm.h
        Action.c
        Barriere.c
        Deplacement.c
        Tour.c
        Tour.h
        DeplacementIhm.h
        DeplacementIhm.c
        Position.c
)
