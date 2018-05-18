/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tienda.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:31
 */

/*** SINGLETON */

#ifndef LOGO_H
#define LOGO_H

#include "Estado.h"
#include "Texture.h"
#include "Sprite.h"
#include "Clock.h"

class Logo : public Estado{
public:
    static Logo* Instance();
    void handleInput();
    void draw();
    void update();
    
protected:
    Logo();
    Logo(const Logo& orig);
    virtual ~Logo();
private:
    static Logo* pinstance;
    m2D::Clock time;
    int alpha;
    m2D::Sprite* sprites;
    m2D::Texture texture;
    m2D::Texture texture2;
};

#endif /* TIENDA_H */

