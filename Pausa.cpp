/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pausa.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:31
 */

#include "Pausa.h"
#include "Menu.h"
#include "RenderWindow.h"
#include "Game.h"
#include "Event.h"

Pausa* Pausa::pinstance=0;
Pausa* Pausa::Instance(){
    if(pinstance==0){
        pinstance=new Pausa;
    }
    
    return pinstance;
}

Pausa::Pausa() {
    
    texture.setLoadFromFile("resources/intefaz.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(200,200,100,100);
    sprite.setPosition(0,0);
}

void Pausa::handleInput(){
    m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        /*if(event.getEvent()=="Return"){

            Game::Instance()->setState(Menu::Instance());
            
        }*/
        
    }
}

void Pausa::draw(){
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Pausa::update(){
   
}

Pausa::Pausa(const Pausa& orig) {
}

Pausa::~Pausa() {
}

