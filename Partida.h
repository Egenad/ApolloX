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

#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"
#include "Nave.h"
#include "Meteorito.h"
#include "Alien.h"

#ifndef PARTIDA_H
#define PARTIDA_H

class Partida : public Estado {
public:
    static Partida* Instance();
    void handleInput();
    void update();
    void draw();
    void moveBackground();
    void Init(int i);
    float getCoordViewX();
    float getCoordViewY();
    void setViewtoOrigin();
    
protected:
    Partida();
    Partida(const Partida& orig);
    virtual ~Partida();
    
private:
    static Partida* pinstance;
    m2D::Texture texture;
    m2D::Texture bossTexture;
    m2D::Sprite* background;
    int lastBgMoved;
    m2D::View view;
    //jefe
    
    //enemigos
    int t2;
    int t1;
    Alien* aliens;
    //obstaculos
    int t3;
    Meteorito* meteor;
    //nave
    Nave* ship;
    //vista
    
    //objetos
    
    //puntuacion
    int score;
    //longitud partida
    int length;
    //modo
    int state; //0 travesia, 1 jefe
    
};

#endif /* PARTIDA_H */

