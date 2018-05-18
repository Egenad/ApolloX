/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:31
 */
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Partida.h"
#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"

Partida::Partida(m2D::Vector2f coord_ship) {
    ship.setVectorX(coord_ship.getVectorX());
    ship.setVectorY(coord_ship.getVectorY());
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

void Partida::setCoordShip(int x, int y){
    ship.setVectorX(x);
    ship.setVectorY(y);
}
m2D::Vector2f Partida::getCoordShip(){
    return ship;
}

