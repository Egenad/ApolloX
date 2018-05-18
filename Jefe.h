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

#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"

class Jefe {
public:
    Jefe();
    Jefe(const Jefe& orig);
    virtual ~Jefe();
private:
    int type;
    int fase;
    int life;
    int maxLife;
    m2D::Sprite Sprite;
    
};

#endif /* JEFE_H */

