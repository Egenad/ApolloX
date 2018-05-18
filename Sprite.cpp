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
    void Sprite::setTexture(m2D::Texture& text){
        sprite.setTexture(text.getTexture());
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
    
    float Sprite::getPositionX(){
        return sprite.getPosition().x;
    }
    
    float Sprite::getPositionY(){
        return sprite.getPosition().y;
    }
    
    sf::FloatRect Sprite::getGlobalBounds(){
        return sprite.getGlobalBounds();
    }
    
    void Sprite::move(float velx, float vely){
        sprite.move(velx,vely);
    }
    
    void Sprite::rotate(int rot){
        sprite.rotate(rot);
    }
    
    void Sprite::setColor(int r,int g,int b){
        sprite.setColor(sf::Color(r,g,b));
    }
    
    void Sprite::setColorWithA(int r,int g,int b, int a){
        sprite.setColor(sf::Color(r,g,b,a));
    }
}
