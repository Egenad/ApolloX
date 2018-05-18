/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Municion.h
 * Author: raquel
 *
 * Created on 18 de mayo de 2018, 2:06
 */
#include <iostream>

#include "Vector2f.h"
#include "Sprite.h"
#include "Texture.h"
#include "RenderWindow.h"

#ifndef MUNICION_H
#define MUNICION_H

class Municion {
public:
    Municion();
    Municion(const Municion& orig);
    virtual ~Municion();
    m2D::Sprite& returnSprite();
    void setTexture(m2D::Texture& texture);
    void setPos(int x, int y);
    void setState(int);
    void setType(int);
    m2D::Vector2f& getCoord();
    int getType();
    int getState();
    void move();
    void draw();
    void update();
private:
    int type; //0 normal, 1 rafaga, 2 canyon, 3 bomba
    m2D::Sprite sprite;
    m2D::Vector2f position;
    int state;

};

#endif /* MUNICION_H */

