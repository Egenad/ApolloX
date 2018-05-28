/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Municion.cpp
 * Author: raquel
 * 
 * Created on 18 de mayo de 2018, 2:06
 */

#include "Municion.h"
#include <iostream>

Municion::Municion() {
    state = 1;
    this->setPos(0,0);
}

Municion::Municion(const Municion& orig) {
}

Municion::~Municion() {
}

void Municion::setTexture(m2D::Texture& texture){
    
    sprite.setTexture(texture);
    if(type==1){ //normal (verde)
        sprite.setTextureRect(239, 0, 33, 44);
    }else if(type==2){ //rafaga (rosa)
        sprite.setTextureRect(271, 0, 33, 44);
    }else if(type==3){ //canyon(rojo)
        sprite.setTextureRect(302, 0, 33, 44);
    }else{ //Bomba(azul)
        sprite.setTextureRect(335, 0, 33, 44);
    }
    
    sprite.setOrigin(33/2,44/2);
    sprite.setPosition(position.getVectorX(),position.getVectorY());
    
}

void Municion::setPos(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
    
    sprite.setPosition(position.getVectorX(), position.getVectorY());
}
void Municion::setState(int x){
    state = x;
}
void Municion::setType(int x){
    type=x;
}
m2D::Sprite& Municion::returnSprite(){
    return sprite;
}

void Municion::move(){

    sprite.move(0,5);

}

void Municion::draw(){
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Municion::update(){
    move();
}

m2D::Vector2f& Municion::getCoord(){
    return position;
}

int Municion::getType(){
    return type;
}
int Municion::getState(){
    return state;
}
