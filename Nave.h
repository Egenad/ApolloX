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

#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"
#include "Texture.h"
#include "RenderWindow.h"

#ifndef NAVE_H
#define NAVE_H

class Nave {
    
public:
    
    static Nave* Instance();
    m2D::Vector2f& getPosition();
    void setPosition(int, int);
    int getState();
    void setTexture(m2D::Texture& texture);
    void update();
    void draw();
    void setState(int);
    
protected:
    Nave ();
    Nave(const Nave& orig);
    virtual ~Nave();
private:
    static Nave* pinstance;
    m2D::Vector2f position;
    m2D::Sprite sprite;
    int velocity;
    m2D::Clock animation;
    int animationType;
    
    int state;
    int life;
    int maxLife;
    int munition;
    int* materials;
    m2D::Vector2f lastMove;
    bool moving;   
};

#endif /* NAVE_H */
