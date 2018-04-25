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

#ifndef PARTIDA_H
#define PARTIDA_H

class Partida : public Estado {
public:
    static Partida* Instance();
    void handleInput();
    void update();
    void draw();
    void moveBackground();
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
    int cont;
    m2D::View view;
    //jefe
    
    //enemigos
    
    //obstaculos
    
    //nave
    Nave* ship;
    //vista
    
    //objetos
    
    //puntuacion
    int score;
    //longitud partida
    int length;
    
};

#endif /* PARTIDA_H */

