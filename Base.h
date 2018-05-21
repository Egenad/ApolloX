/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Base.h
 * Author: shiro
 *
 * Created on 16 de mayo de 2018, 16:11
 */

#ifndef BASE_H
#define BASE_H

#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"
#include "Font.h"
#include "Text.h"
#include "Clock.h"
#include "Music.h"

class Base : public Estado{
public:
    static Base* Instance();
    void handleInput();
    void update();
    void draw();
    void right();
    void left();
    void resetSelected();
    void reduceLifeBar();
    void checkMaterialsNedeed();
    void reparar();
    void Thanos();
protected:
    Base();
    Base(const Base& orig);
    virtual ~Base();
private:
    int seleccionado;
    m2D::Sprite* sprites;
    m2D::Texture texture;
    m2D::Font font;
    m2D::Text* text;
    static Base* pinstance;
    int hierro,magnesio,titanio,carbon;
    bool animation;
    int stateSprite;
    m2D::Clock animationClock;
    m2D::Music intro;
    m2D::Music button;
};

#endif /* BASE_H */

