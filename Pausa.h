/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pausa.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:31
 */

/*** SINGLETON */

#ifndef PAUSA_H
#define PAUSA_H

#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"

class Pausa : public Estado{
public:
    static Pausa* Instance();
    void handleInput();
    void update();
    void draw();
protected:
    Pausa();
    Pausa(const Pausa& orig);
    virtual ~Pausa();
private:
    m2D::Sprite sprite;
    m2D::Texture texture;
    static Pausa* pinstance;

};

#endif /* PAUSA_H */

