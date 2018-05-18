/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.cpp
 * Author: angel
 * 
 * Created on 18 de abril de 2018, 19:26
 */

#include "Sprite.h"
namespace m2D{
    
    Sprite::Sprite(){
        
    }
    
    Sprite::Sprite(m2D::Texture& text) {
       
        sprite.setTexture(text.getTexture());
    }

    Sprite::Sprite(const Sprite& orig) {
    }

    Sprite::~Sprite() {
    }
    
    void Sprite::setOrigin(float x, float y){
        sprite.setOrigin(x, y);
    }
    void Sprite::setTexture(std::string n){
        sf::Texture text;
        if (!text.loadFromFile(n))
        {
            std::cerr << "Error cargando la imagen " << n << std::endl;
            exit(0);
        }
        sprite.setTexture(text);
    }
    void Sprite::setTextureRect(int a1, int a2, int a3, int a4){   
        sprite.setTextureRect(sf::IntRect(a1, a2, a3, a4));
    }
    void Sprite::scale(float x, float y){
        sprite.scale(x, y);
    }
    void Sprite::setPosition(float x, float y){
        sprite.setPosition(x, y);
    }
    sf::Sprite& Sprite::getSprite(){
        return sprite;
    }
}
