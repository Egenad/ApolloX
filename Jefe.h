/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jefe.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:34
 */

#ifndef JEFE_H
#define JEFE_H
#pragma once
#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"
#include "Strategy.h"
#include "StrategyA.h"
#include "StrategyB.h"
#include "StrategyA2.h"
#include "StrategyC.h"
class Jefe {
public:
    Jefe();
    Jefe(const Jefe& orig);
    virtual ~Jefe();
    void setTexture(m2D::Texture&);
    void draw();
    void danyo(int);
    void update(m2D::Texture&);
    int getvida();
    void setStrategy(Strategy *obj);
    void setType(int);
    int getType();
    int getFase();
    void setFase(int);
    void atacar(m2D::Texture&);
    void setPos(float, float);
    void changeSprite();
    void updateVida(m2D::Texture&);
private:
    bool deathAnimation;
    bool deathStart;
    int type;
    int fase;
    int life;
    int maxLife;
    m2D::Sprite sprite;
    m2D::Clock change_sprite;
    Strategy *strategy;
    std::vector<Bala*> balas_jefe;
    int nsprite;
    m2D::Sprite expp;
    bool exppCreado;
    m2D::Clock explosion;
    m2D::Clock explosion2;
    int alpha;
    m2D::Vector2f position;
};

#endif /* JEFE_H */

