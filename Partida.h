/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:31
 */

/*** SINGLETON */

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"

#ifndef PARTIDA_H
#define PARTIDA_H

class Partida {
public:
    Partida(m2D::Vector2f);
    Partida(const Partida& orig);
    virtual ~Partida();
    void setCoordShip(int, int);
    m2D::Vector2f getCoordShip();
    
private:
    m2D::Vector2f ship;
    //Nave* ship;
};

#endif /* PARTIDA_H */

