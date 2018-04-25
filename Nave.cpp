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
#include "Nave.h"
#include "RenderWindow.h"
#include "Texture.h"
#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"
#include "Bala.h"

Nave* Nave::pinstance=0;
Nave* Nave::Instance(){
    if(pinstance==0){
        pinstance=new Nave;
    }
    
    return pinstance;
}


Nave::Nave (){
    position.setVectorX(1535/2);
    position.setVectorY(0);
    state=2;
    velocity=5;
    animationType=0;
    munition = 1; // cambiar en un futuro
}
Nave::Nave(const Nave& orig) {
}

Nave::~Nave() {
}

void Nave::disparar(m2D::Texture& texture){
    switch(munition){
        case 1:
            Bala * bullet = new Bala(texture, 1, 20.0f);
            bullet->setPos(m2D::Vector2f(position.getVectorX(), position.getVectorY()));
            vectorBalas.push_back(bullet);
        break;
    }
}

void Nave::setMunition(int n){
    munition = n;
}

int Nave::getMunition(){
    return munition;
}

void Nave::setState(int d){
    state=d;
}
m2D::Vector2f& Nave::getPosition(){
    return position;
}
int Nave::getState(){
    return state;
}
void Nave::setPosition(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
    
    sprite.setPosition(position.getVectorX(),position.getVectorY());
}

void Nave::setTexture(m2D::Texture& texture){
    sprite.setTexture(texture);
    sprite.setOrigin(110/2,139/2);
    sprite.setTextureRect(0,212,110,139);
    sprite.setPosition(1535/2,0);
    sprite.scale(0.8,0.8);
}

void Nave::draw(){
    for(int i=0; i<vectorBalas.size(); i++){
        vectorBalas[i]->draw();
    }
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Nave::update(){
    //cambiamos animacion
    if(animation.getElapsedTimeAsSeconds()>=0.5f){
        if(animationType==0){
            animationType=1;
            sprite.setTextureRect(110,212,110,142);
        }else{
            animationType=0;
            sprite.setTextureRect(0,212,110,139);
        }
        animation.restart();
    }
    //cambiamos posicion
    this->setPosition(position.getVectorX(),position.getVectorY()-velocity);
    
    //updateamos balas
    if(!vectorBalas.empty()){
        for(int i=0; i<vectorBalas.size(); i++){
            vectorBalas[i]->disparar();
        }
    }
}