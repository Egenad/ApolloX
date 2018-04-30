/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.h
 * Author: angel
 *
 * Created on 18 de abril de 2018, 19:26
 */

#ifndef SPRITE_H
#define SPRITE_H
#include "Motor2D.h"
#include "Texture.h"
#include <iostream>

namespace m2D{
    class Sprite : public Motor2D{
    public:
        Sprite();
        Sprite(m2D::Texture&);
        Sprite(const Sprite& orig);
        virtual ~Sprite();
        void setOrigin(float, float);
        void setTexture(m2D::Texture&);
        void setTextureRect(int, int, int, int);
        void scale(float, float);
        void setPosition(float, float);
        void move(float velx, float vely);
        void rotate(int rot);
        float getPositionX();
        float getPositionY();
        sf::Sprite& getSprite();
        sf::FloatRect getGlobalBounds();
        void setColor(int,int,int);
    private:
        sf::Sprite sprite;
    };
}
#endif /* SPRITE_H */

