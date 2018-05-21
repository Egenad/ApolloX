/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * 
 * File:   Alien.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:34
 */



#ifndef ALIEN_H
#define ALIEN_H

#include "Bala.h"
#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"
#include "Texture.h"
#include "RenderWindow.h"
#include "NPC.h"
#include <math.h>


class Alien {
public:
    Alien();
    Alien(const Alien& orig);
    virtual ~Alien();
    
    int getX();
    int getY();
    
    void setPos(int x, int y);
    void setState();
    void draw();
    
    void dispara(m2D::Texture &textura);
    
    void dibujaBalas();
    void quitarVida(int a);
    void Update();//EL que llamamos en NIVEL
    void setTexture(m2D::Texture& texture);
    void move(float grados);
    int getVida();
    m2D::Vector2f& getPos();
    int getStateAlien();
    m2D::Sprite& getShape();
    void animation();
    int getTipo();
private:
    int type;
    int life;
    m2D::Sprite sprite;
    m2D::Texture texture;
    m2D::Vector2f position;
    std::vector<Bala*> balas;//vector balas
    float grados; //grados de movimiento
    int state; //0 vivo, 1 muerto
    int attack;
    int bullet; //tipo de bala
    m2D::Clock dis;
    m2D::Clock animationClock;
    int animationState;
};



#endif /* ALIEN_H */

