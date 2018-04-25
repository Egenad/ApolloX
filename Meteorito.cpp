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

Meteorito::Meteorito(m2D::Texture &textura) {
    srand(time(NULL));
    radiomax=80;
    radiomin=15;
    sprite.setTexture(textura);
    sprite.setTextureRect(190,70,90,100);
    vely=6; //velocidad de caida
    float ran1=rand()%(radiomax-radiomin);  //numero aleatorio para radio del meteorito
    if(ran1>50){
        vely=3;
        sprite.scale(1.5,1.5);
    }
    else if(ran1<50 && ran1>30){
        vely=5;
    }
    else if(ran1<30){
        sprite.scale(0.4,0.4);
    }
    float ranx=rand()%700-60; //numero aleatorio para respawn en eje x
    sprite.setOrigin(ran1, ran1);
    sprite.setPosition(ranx,-radiomax);
            
            //LO Clasificamos en tipos para determinar la trayectoria del meteorito
    if(sprite.getPositionX()<=200){
        tipo=1;
    }
    else if(200<sprite.getPositionX() && sprite.getPositionX()<=400){
        tipo=2;
    }
            
    else if(sprite.getPositionX()>400){
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

void Meteorito::Update(){ //PUEDE PETAR
    move();
    //Nave::Instance().checkColl();
    draw();

}

