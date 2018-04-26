/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Meteorito.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:34
 */

#include "Meteorito.h"

Meteorito::Meteorito() {
    srand(time(NULL));
    //radiomax=80;
    //radiomin=15;
    
    vely=6; //velocidad de caida
    float ran1=rand()%100;  //numero aleatorio para radio del meteorito
    if(ran1>80){ //grande
        vely=3;
        size=1;
    }
    else if(ran1>30 && ran1<=80){ //mediano
        vely=5;
        size=2;
    }
    else if(ran1<=30){ //pequeño
        size=0;
    }
    
    //por si las moscas inicializamos position
    this->setCoord(0,0);
    
}

void Meteorito::setTexture(m2D::Texture& texture){
    sprite.setTexture(texture);
    sprite.setTextureRect(190,70,90,100);
    sprite.setOrigin(90/2,100/2);
    sprite.setPosition(position.getVectorX(),position.getVectorY());
    if(size==0){
        sprite.scale(0.4,0.4);
    }else if (size==1){
        sprite.scale(1.2,1.2);
    }
    
}

void Meteorito::setCoord(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
    
    if(position.getVectorX()<=621){
        tipo=1;
    }
    else if(621<position.getVectorX() && position.getVectorX()<=913){
        tipo=2;
    }
            
    else if(position.getVectorX()>913){
        tipo=3;
    }
}

Meteorito::Meteorito(const Meteorito& orig) {
}

Meteorito::~Meteorito() {
}

m2D::Sprite& Meteorito::returnShape(){
    return sprite;
}

void Meteorito::move(){
    if(tipo==1){
        sprite.move(1,vely);
    }
    else if(tipo==2){
        sprite.move(0,vely);
    }
    
    else if(tipo==3){
        sprite.move(-1,vely);
    }
}

void Meteorito::draw(){
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Meteorito::update(){ //PUEDE PETAR
    move();
}

