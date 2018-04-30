/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escudo.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:32
 */
#include "Escudo.h"
#include <iostream>
#include "Vector2f.h"
#include "Sprite.h"
#include "Texture.h"
#include "RenderWindow.h"

Escudo::Escudo() {
    state=1;
}

Escudo::Escudo(const Escudo& orig) {
}

Escudo::~Escudo() {
}
void Escudo::setTexture(m2D::Texture& texture){
    sprite.setTexture(texture);
    sprite.setTextureRect(200, 0, 39, 40);
    sprite.setOrigin(39/2,40/2);
    sprite.setPosition(position.getVectorX(),position.getVectorY());
    
}
void Escudo::setState(int x){
    state=0;
}
void Escudo::setCoord(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
}

m2D::Sprite& Escudo::returnSprite(){
    return sprite;
}

void Escudo::move(){

}

void Escudo::draw(){
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Escudo::update(){
}

m2D::Vector2f& Escudo::getCoord(){
    return position;
}

