/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nave.cpp
 * Author: raquel
 * 
 * Created on 27 de febrero de 2018, 18:18
 */
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"

Nave::Nave (int x, int y, m2D::Sprite s ){
    position.setVectorX(x);
    position.setVectorY(y);
    state=2;
        
    sprite = s;
    sprite.setPosition(x, y);
}
Nave::Nave(const Nave& orig) {
}

Nave::~Nave() {
}
void Nave::setSprite(m2D::Sprite s){
    sprite = s;
    sprite.setPosition(position.getVectorX(), position.getVectorY());
}
void Nave::setState(int d){
    state=d;
}
m2D::Vector2f Nave::getPosition(){
    return position;
}
m2D::Sprite& Nave::getSprite(){
    return sprite;
}
int Nave::getState(){
    return state;
}
void Nave::setPosition(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
    
    sprite.setPosition(position.getVectorX(),position.getVectorY());
}