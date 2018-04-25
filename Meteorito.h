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

#include "Vector2f.h"
#include "Sprite.h"
#include "Texture.h"
#include "RenderWindow.h"
class Meteorito {
public:
    Meteorito(m2D::Texture &textura);
    Meteorito(const Meteorito& orig);
    virtual ~Meteorito();  
    m2D::Sprite& returnShape();
    void move();
    void draw();
    void Update();//PUEDE PETAR
private:
    //int tipo; 
    int vely; //velocidad de caida
    int tipo; //tipo para indicar el tipo de trayectoria
    int radiomax; //radio maximo del meteorito
    int radiomin; //radio minimo del meteorito
    m2D::Sprite sprite;
};

#endif /* METEORITO_H */

