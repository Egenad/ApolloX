/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:31
 */
#include <iostream>

#include "Partida.h"
#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"
#include "RenderWindow.h"

Partida* Partida::pinstance=0;
Partida* Partida::Instance(){
    if(pinstance==0){
        pinstance=new Partida;
    }
    
    return pinstance;
}

Partida::Partida() {
   //inicializamos todo
    score=0;
    length=1000;
    
    texture.setLoadFromFile("resources/nivel.png");
    
    background=new m2D::Sprite[3];
    
    for(int i=0;i<3;i++){
        background[i].setTexture(texture);
    }
    
    //fondo
    background[0].setOrigin(585/2,510/2);
    background[0].setTextureRect(95,355,585,510);
    background[0].setPosition(1535/2,0);
    background[0].scale(1.5,1.5);
    
    background[1].setOrigin(585/2,510/2);
    background[1].setTextureRect(95,355,585,510);
    background[1].setPosition((1535/2),0-(1.5*510));
    background[1].scale(1.5,1.5);
    
    background[2].setOrigin(585/2,510/2);
    background[2].setTextureRect(95,355,585,510);
    background[2].setPosition((1535/2),0-3*(510));
    background[2].scale(1.5,1.5);
    
    lastBgMoved=0;
   
    //nave
    ship = Nave::Instance();
    ship->setTexture(texture);
    
    //vista
    view.setSize(1535.0f,860.0f);
    m2D::RenderWindow::Instance()->setView(view);
    
}

void Partida::handleInput(){
    m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        
        if(event.getEventType()== sf::Event::Closed){
           m2D::RenderWindow::Instance()->close();
        }
        else if(event.getEventType() == sf::Event::KeyPressed){
            switch(event.getKey()){
                case sf::Keyboard::Space:
                    Nave::Instance()->disparar(texture);
                break;
            }
        }
    }
}

void Partida::update(){
    //updateamos el fondo
    this->moveBackground();
    //updateamos el player
    ship->update();
    //updateamos la vista
    view.setCenter(1535/2,ship->getPosition().getVectorY()-360);
    m2D::RenderWindow::Instance()->setView(view);
    
}

void Partida::draw(){
    for(int i=0;i<3;i++){
        m2D::RenderWindow::Instance()->draw(background[i]);
    }
    
    ship->draw();
    
    
}

void Partida::moveBackground(){
    
    if(ship->getPosition().getVectorY()-360<=background[lastBgMoved].getPositionY()+50){
        int move=lastBgMoved+1;
        if(move==3){
            move=0;
        }
        background[move].setPosition((1535/2),background[lastBgMoved].getPositionY()-765);
        lastBgMoved=move;
    }
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

