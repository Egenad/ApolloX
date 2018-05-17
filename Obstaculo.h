/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Obstaculo.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:32
 */
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"

#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo {
public:
    Obstaculo();
    Obstaculo(const Obstaculo& orig);
    virtual ~Obstaculo();
private:
    m2D::Sprite sprite;
    int state;
    m2D::Vector2f position;

};

#endif /* OBSTACULO_H */

