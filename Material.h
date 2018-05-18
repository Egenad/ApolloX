/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   Material.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:35
 */
#include <iostream>

#include "Vector2f.h"
#include "Sprite.h"
#include "Texture.h"
#include "RenderWindow.h"

#ifndef MATERIAL_H
#define MATERIAL_H

class Material {
public:
    Material();
    Material(const Material& orig);
    virtual ~Material();
    m2D::Sprite& returnSprite();
    void setTexture(m2D::Texture& texture);
    void setPos(int x, int y);
    void setState(int);
    void setType(int);
    m2D::Vector2f& getCoord();
    int getType();
    int getState();
    void move();
    void draw();
    void update();
private:
    int type; //0 titanio, 1 magnesio, 2 hiero, 3 carbon
    m2D::Sprite sprite;
    m2D::Vector2f position;
    int state;
};

#endif /* MATERIAL_H */


