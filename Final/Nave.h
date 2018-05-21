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
#include "Bala.h"
#include "Meteorito.h"
#include "Alien.h"
#include "Alien2.h"
#include "Escudo.h"
#include "Municion.h"
#include "Material.h"

#ifndef NAVE_H
#define NAVE_H

class Nave {
    
public:
    
    static Nave* Instance();
    m2D::Vector2f& getPosition();
    m2D::Sprite& returnShape();
    m2D::Sprite& returnShape2();
    void setPosition(int, int);
    int getState();
    void setTexture(m2D::Texture& texture);
    void update();
    void update2();
    int comprobarChoqueJefe(m2D::Sprite&);
    void danyo(int);
    void draw();
    void setState(int);
    void disparar(m2D::Texture& texture);
    int getMunition();
    int getLife();
    void setLife(int);
    int* getMaterials();
    void setMunition(int);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void golpea(Alien& alien);
    void golpea2(Alien2& alien);
    bool checkCollMete(Meteorito& meteorito);
    bool checkCollEsc(Escudo& escudo);
    bool checkCollMaterial(Material& material);
    bool checkCollMunition(Municion& municion);
    bool checkColl(Bala& bullet);
    int getShipLife();
    void saveLife(int);
    void borrarBalas();
    void ismovingRight(bool b);
    void ismovingLeft(bool b);
    void ismovingUp(bool b);
    void ismovingDown(bool b);
    void setCanyonBool();
    bool compChoqueMeteorito(m2D::Sprite&);
protected:
    Nave ();
    Nave(const Nave& orig);
    virtual ~Nave();
private:
    static Nave* pinstance;
    m2D::Vector2f position;
    m2D::Sprite sprite;
    m2D::Sprite sprite2;
    int velocity;
    m2D::Clock animation;
    int animationType;
    std::vector<Bala*> vectorBalas;
    
    int state;
    m2D::Clock shell;
    int life;
    int shiplife;
    int maxLife;
    int munition;
    int* materials;
    m2D::Vector2f lastMove;
    
    int contador_canyon;
    bool moving;
    bool canyon;
    bool explosion;
    bool bomb_alive;
    m2D::Clock cb_time;
    m2D::Clock tiempo_entre_balas; 
    
    //CONTROLES
    bool right;
    bool left;
    bool up;
    bool down;
};

#endif /* NAVE_H */

