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
#include "Jefe.h"
#include "Meteorito.h"
#include "Alien.h"
#include "Alien2.h"
#include "Material.h"
#include "Municion.h"
#include "Music.h"

#ifndef PARTIDA_H
#define PARTIDA_H

class Partida : public Estado {
public:
    static Partida* Instance();
    void inicializar();
    void handleInput();
    void update();
    void draw();
    void moveBackground();
    void Init(int i);
    void Infinite();
    float getCoordViewX();
    float getCoordViewY();
    void setViewtoOrigin();
    void setViewtoShip();
    void updateText();
    void reduceLifeBar(int);
    void reduceLifeBarBoss(int);
    void aumentScore(int s);
    void pausarMusica();
    void stopMusica();
    void saveLife();
    int getMode();
    int getScore();
    int getLength();
    void setStartI();
    void Thanos();
    void setMunicion(int);
    int getState();
    void sacarAliensPantalla();
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
    Alien2* aliens2;
    //obstaculos
    int t3;
    Meteorito* meteor;
    //nave
    Nave* ship;
    //vista
    
    //objetos
    int ts;
    Escudo* shell;
    
    //jefe
    int t4;
    Jefe* jefe;
    //puntuacion
    int score;
    //longitud partida
    int length;
    //modo
    int state; //0 travesia, 1 jefe
    int mode;//0 normal, 1 infinite
    //materiales
    int m1;
    Material* carbon;
    int m2;
    Material* hierro;
    int m3;
    Material* titanio;
    int m4;
    Material* magnesio;
    //municion
    int tm;
    Municion* municion;
    //contador infinito
    int startI;
    //longitud actual infinito
    int path;
    
    //variables para dibujar el score
    m2D::Font font;
    m2D::Text* text;
    m2D::Sprite* lifeS;
    m2D::Clock wait;
    //musica
    m2D::Music music;
    bool waitEnd;
    
};

#endif /* PARTIDA_H */

