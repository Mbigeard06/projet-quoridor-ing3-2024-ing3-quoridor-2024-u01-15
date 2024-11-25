cmake_minimum_required(VERSION 3.29)
project(Quoridor2024)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quoridor2024
        Joueur.c
        Joueur.h
        Barriere.h
        Plateau.c
        Plateau.h
        Menu.h
        Partie.c
        Partie.h
        Menu.c
        main.c
        JoueurDao.c
        JoueurDao.h
        PartieDao.c
        PartieDao.h
        ActionIhm.c
        ActionIhm.h
        Barriere.c
        DeplacementIhm.h
        DeplacementIhm.c
        ActionHistorique.c
        ActionHistorique.h
)
