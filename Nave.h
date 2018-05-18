/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nave.h
 * Author: raquel
 *
 * Created on 27 de febrero de 2018, 18:18
 */

/*** SINGLETON */


#include <iostream>
#include <SFML/Graphics.hpp>

#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"

#ifndef NAVE_H
#define NAVE_H

class Nave {
    
public:
    Nave (int, int, m2D::Sprite);
    Nave(const Nave& orig);
    virtual ~Nave();
    
    m2D::Vector2f getPosition();
    void setPosition(int, int);
    int getState();
    
    void setSprite(m2D::Sprite);
    void setState(int);
    m2D::Sprite& getSprite();
   
private:
    int state;
    m2D::Vector2f position;
    m2D::Sprite sprite;
    int velocity;
    int life;
    int maxLife;
    int munition;
    int* materials;
    
    m2D::Vector2f lastMove;
    bool moving;   
};

#endif /* NAVE_H */

