/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bala.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:32
 */

#ifndef BALA_H
#define BALA_H

#include "Texture.h"
#include "Vector2f.h"
#include "RenderWindow.h"
#include "Sprite.h"


class Bala {
public:
    Bala(m2D::Texture &textura); //constru
    Bala(m2D::Texture&, int, float);
    Bala(m2D::Texture&, int, float, float);
    Bala(const Bala& orig); 
    virtual ~Bala();
    int getTipo();
    void disparar();
    void disparar_bomba(int);
    void disparar_angulo(int);
    void moverbala(int);
    void setAngulo(float);
    void escalarCanyon();
    void disparar_canyon(m2D::Vector2f);
    void fire(int speed);   
    void setPos(m2D::Vector2f pos);  
    void draw(m2D::RenderWindow &window);//renderiza el alien
    m2D::Sprite& returnShape();//devuelve el shape
private:

protected:    
    m2D::Sprite bala;
    int type;
    float velocidad;
    float angulo;
};

#endif /* BALA_H */

