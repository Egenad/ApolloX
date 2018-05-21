/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resultado.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:31
 */

/*** SINGLETON */
#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"
#include "Music.h"

#ifndef RESULTADO_H
#define RESULTADO_H

#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"
#include "Font.h"
#include "Text.h"
#include "Clock.h"
#include "Music.h"

class Resultado : public Estado{
public:
    static Resultado* Instance();
    void setScore(int);
    void handleInput();
    void update();
    void draw();
    void right();
    void left();
    void resetSelected();
    void Thanos();
protected:
    Resultado();
    Resultado(const Resultado& orig);
    virtual ~Resultado();
private:
    int seleccionado;
    m2D::Sprite* sprites;
    m2D::Texture texture;
    m2D::Font font;
    m2D::Text* text;
    static Resultado* pinstance;
    int hierro,magnesio,titanio,carbon;
    bool animation;
    int stateSprite;
    m2D::Clock animationClock;
    m2D::Music intro;
    m2D::Music button;
};

#endif /* RESULTADO_H */
