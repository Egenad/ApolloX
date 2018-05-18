/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Meteorito.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:34
 */

#ifndef METEORITO_H
#define METEORITO_H

#include "Sprite.h"
#include "Vector2f.h"
class Meteorito {
public:
    Meteorito();
    Meteorito(const Meteorito& orig);
    virtual ~Meteorito();
private:
    //int tipo; 
    int velocity;
    int angle;
    m2D::Sprite sprite;
};

#endif /* METEORITO_H */

