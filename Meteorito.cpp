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
#include <iostream>
#include "Game.h"

Meteorito::Meteorito() {
    rot=1; //velocidad de rotacion
    vely=11; //velocidad de caida
    float ran1=rand()%100;  //numero aleatorio para radio del meteorito
    float ran2=rand()%2;
    if(ran2==0){
        
        rot=-1;
    }
    if(ran1>80){ //grande
        std::cout << "grande "<<std::endl;
        vely=3;
        size=1;
    }
    else if(ran1>30 && ran1<=80){ //mediano
        std::cout << "med "<<std::endl;
        vely=8;
        size=2;
    }
    else if(ran1<=30){ //pequeño
        std::cout << "peq "<<std::endl;
        size=0;
    }
    
    colisioned=false;
    //por si las moscas inicializamos position
    
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
        position.setVectorX(position.getVectorX()+20);
        position.setVectorY(position.getVectorY()+vely);
        sprite.setPosition(position.getVectorX(),position.getVectorY());
        sprite.rotate(rot);
    }
    else if(tipo==2){
        position.setVectorX(position.getVectorX());
        position.setVectorY(position.getVectorY()+vely);
        sprite.setPosition(position.getVectorX(),position.getVectorY());
        sprite.rotate(rot);
    }
    
    else if(tipo==3){
        position.setVectorX(position.getVectorX()-20);
        position.setVectorY(position.getVectorY()+vely);
        sprite.setPosition(position.getVectorX(),position.getVectorY());
        sprite.rotate(rot);
    }
}

void Meteorito::draw(){
    
    float posY;
    float posX;
    
    if(Game::Instance()->getP()<1){
        
        if(tipo==1){
            
            posY=this->getCoord().getVectorY()*(1-Game::Instance()->getP())+(this->getCoord().getVectorY()+vely)*Game::Instance()->getP();
            posX=this->getCoord().getVectorX()*(1-Game::Instance()->getP())+(this->getCoord().getVectorX()+20)*Game::Instance()->getP();
            
            sprite.setPosition(posX,posY);
            sprite.rotate(rot);
        }
        else if(tipo==2){
            
            posY=this->getCoord().getVectorY()*(1-Game::Instance()->getP())+(this->getCoord().getVectorY()+vely)*Game::Instance()->getP();
            posX=this->getCoord().getVectorX()*(1-Game::Instance()->getP())+(this->getCoord().getVectorX()+0)*Game::Instance()->getP();
            
            sprite.setPosition(posX,posY);
            sprite.rotate(rot);
        }

        else if(tipo==3){
            
            posY=this->getCoord().getVectorY()*(1-Game::Instance()->getP())+(this->getCoord().getVectorY()+vely)*Game::Instance()->getP();
            posX=this->getCoord().getVectorX()*(1-Game::Instance()->getP())+(this->getCoord().getVectorX()-20)*Game::Instance()->getP();
            
            sprite.setPosition(posX,posY);
            sprite.rotate(rot);
        }
    }
    
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Meteorito::update(){
    move();
}

m2D::Vector2f& Meteorito::getCoord(){
    return position;
}

bool Meteorito::getColisioned(){
    return colisioned;
}

void Meteorito::setColisioned(){
    colisioned=true;
}