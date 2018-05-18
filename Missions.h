/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Missions.h
 * Author: shiro
 *
 * Created on 23 de abril de 2018, 19:57
 */

#ifndef MISSIONS_H
#define MISSIONS_H

#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"
#include "Music.h"


class Missions : public Estado{
public:
    static Missions* Instance();
    void handleInput();
    void update();
    void draw();
    void up();
    void down();
    void right();
    void left();
    void setDesbloq();
    void resetSelected();
    
protected:
    Missions();
    Missions(const Missions& orig);
    virtual ~Missions();
private:
    static Missions* pinstance;
    int seleccionado;
    m2D::Sprite* sprites;
    m2D::Texture texture;
    int* desbloq; //1 desbloq, 0 bloq
    m2D::Music intro;
    m2D::Music button;
};

#endif /* MISSIONS_H */

