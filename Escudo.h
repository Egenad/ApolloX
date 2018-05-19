/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   Escudo.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:32
 */
#include <iostream>

#ifndef ESCUDO_H
#define ESCUDO_H

#include "Clock.h"
#include "Sprite.h"
#include "Texture.h"
#include "Vector2f.h"

class Escudo {
public:
    Escudo();
    Escudo(const Escudo& orig);
    virtual ~Escudo();
    m2D::Sprite& returnSprite();
    void setTexture(m2D::Texture& texture);
    void setCoord(int x, int y);
    m2D::Vector2f& getCoord();
    void setState(int);
    int getState();
    void move();
    void draw();
    void update();
private:
    m2D::Sprite sprite;
    m2D::Vector2f position;
    int state;
    float time;
    int type;
};

#endif /* ESCUDO_H */

