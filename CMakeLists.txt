cmake_minimum_required(VERSION 3.29)
project(Quoridor2024)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quoridor2024 main.cpp
        Joueur.c
        Joueur.h
        Position.h
        Action.h
        Action.h
        Barriere.h
)
