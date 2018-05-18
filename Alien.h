/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alien.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:34
 */


#ifndef ALIEN_H
#define ALIEN_H

#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"

class Alien {
public:
    Alien();
    Alien(const Alien& orig);
    virtual ~Alien();
private:
    int type;
    m2D::Sprite sprite;
    m2D::Vector2f position;
    int state;
    int attack;
    int bullet; //tipo de bala
    m2D::Clock clock;
};

#endif /* ALIEN_H */

