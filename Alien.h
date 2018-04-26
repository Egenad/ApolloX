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

#include "Bala.h"
#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"
#include "Texture.h"
#include "RenderWindow.h"
#include "Nave.h"
#include <math.h>
#include "NPC.h"

class Alien {
public:
    Alien(m2D::Texture &textura, int tipo);
    Alien(const Alien& orig);
    virtual ~Alien();
    
    int getX();
    int getY();
    
   void setPos(int x, int y);
    
    void draw(m2D::RenderWindow &window);
    
    void dispara(m2D::Texture &textura);
    
    void dibujaBalas();
    
    void Update();//EL que llamamos en NIVEL
    
    void move(float grados);
    m2D::Vector2f getPos();
    
    m2D::Sprite& getShape();
    
    int getTipo();
private:
    int type;
    
    m2D::Sprite sprite;
    m2D::Texture texture;
    m2D::Vector2f position;
    std::vector<Bala*> balas;//vector balas
    float grados; //grados de movimiento
    int state;
    int attack;
    int bullet; //tipo de bala
    m2D::Clock dis;
};



#endif /* ALIEN_H */

