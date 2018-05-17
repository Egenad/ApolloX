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
#include "Font.h"
#include "Text.h"

class Pausa : public Estado{
public:
    static Pausa* Instance();
    void handleInput();
    void update();
    void draw();
    void setCenter();
    void up();
    void down();
    void resetSelected();
    
protected:
    Pausa();
    Pausa(const Pausa& orig);
    virtual ~Pausa();
private:
    int seleccionado;
    m2D::Font font;
    m2D::Text text;
    m2D::Sprite* sprites;
    m2D::Texture texture;
    static Pausa* pinstance;

};

#endif /* PAUSA_H */

