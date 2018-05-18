/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   Alien2.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:34
 */




#ifndef ALIEN2_H
#define ALIEN2_H

#include "Bala.h"
#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"
#include "Texture.h"
#include "RenderWindow.h"
#include "NPC.h"
#include <math.h>


class Alien2 {
public:
    Alien2();
    Alien2(const Alien2& orig);
    virtual ~Alien2();
    
    int getX();
    int getY();
    
    void setPos(int x, int y);
    void setState();
    void draw();
    
    void dispara(m2D::Texture &textura);
    
    void dibujaBalas();
    void quitarVida();
    void Update();//EL que llamamos en NIVEL
    void setTexture(m2D::Texture& texture);
    int getVida();
    int getStateAlien();
    m2D::Vector2f& getPos();
    void animation();
    m2D::Sprite& getShape();
    
    int getTipo();
private:
    int type;
    int life;
    m2D::Sprite sprite;
    m2D::Texture texture;
    m2D::Vector2f position;
    std::vector<Bala*> balas;//vector balas
    bool stop;
    int state; //0 vivo, 1 muerto
    int attack;
    int bullet; //tipo de bala
    m2D::Clock dis;
    m2D::Clock animationClock;
    int animationState;
};



#endif /* ALIEN2_H */

