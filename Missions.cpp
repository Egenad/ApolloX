/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Missions.cpp
 * Author: shiro
 * 
 * Created on 23 de abril de 2018, 19:57
 */

#include "Missions.h"
#include "Menu.h"
#include "RenderWindow.h"
#include "Game.h"
#include "Missions.h"
#include "Partida.h"
#include "Meteorito.h"
#include <iostream>

#define aumento 205

Missions* Missions::pinstance=0;
Missions* Missions::Instance(){
    if(pinstance==0){
        pinstance=new Missions;
    }
    
    return pinstance;
}


Missions::Missions() {
    
    texture.setLoadFromFile("resources/interfaz.png");
    seleccionado=-1;
    
    sprites=new m2D::Sprite[6];
    for(int i=0;i<6;i++){
        sprites[i].setTexture(texture);
    }
    
    //fondo
    sprites[0].setOrigin(0,0);
    sprites[0].setTextureRect(0,0,1926,1080);
    sprites[0].setPosition(0,0);
    sprites[0].scale(0.8,0.8);
    
    //misiones
    //1
    sprites[1].setOrigin(240/2,230/2);
    sprites[1].setTextureRect(337,1720,240,230); 
    sprites[1].setPosition((1535/2)-400,(860/2)+50);
    sprites[1].scale(0.7,0.7);
    //2
    sprites[2].setOrigin(205/2,200/2);
    sprites[2].setTextureRect(575,1720,205,200); 
    sprites[2].setPosition((1535/2),(860/2)+50);
    sprites[2].scale(0.8,0.8);
    sprites[2].setColor(0,0,0);
    //3
    sprites[3].setOrigin(337/2,320/2);
    sprites[3].setTextureRect(0,1720,337,320); 
    sprites[3].setPosition((1535/2)+400,(860/2)+50);
    sprites[3].scale(0.7,0.7);
    sprites[3].setColor(0,0,0);
    
    //salir
    sprites[4].setOrigin(0,0);
    sprites[4].setTextureRect(1575,1085,400,130); //amarillo 1160,1220
    sprites[4].setPosition(0,860-110);
    sprites[4].scale(0.8,0.8);
    
    //seleccionador
    sprites[5].setOrigin(800/2,400/2);
    sprites[5].setTextureRect(1320,1650,800,400);
    sprites[5].setPosition(-500,-500);
    sprites[5].scale(1,1);
    
    desbloq=new int[3];
    desbloq[0]=1;
    desbloq[1]=0;
    desbloq[2]=0;
}

void Missions::handleInput(){
    m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        
        if(event.getEventType()== sf::Event::Closed){
           m2D::RenderWindow::Instance()->close();
        }
        
        if(event.getEventType()== sf::Event::KeyPressed && event.getKey() == sf::Keyboard::Return){
            
            if(seleccionado==4){
                //atras
                Game::Instance()->setState(Menu::Instance());
            }else if(seleccionado==3){
                //mission3
            }else if(seleccionado==2){
                //mission2
                Game::Instance()->setState(Partida::Instance());
                Partida::Instance()->Init(2);
            }else if(seleccionado==1){
                //mision1
                Game::Instance()->setState(Partida::Instance());
                Partida::Instance()->Init(1);
            }
            
            
        }else if(event.getEventType()== sf::Event::KeyPressed && event.getKey() == sf::Keyboard::Down){
            this->down();            
        }else if(event.getEventType()== sf::Event::KeyPressed && event.getKey() == sf::Keyboard::Up){
            this->up();
        }else if(event.getEventType()== sf::Event::KeyPressed && event.getKey() == sf::Keyboard::Right){
            this->right();            
        }else if(event.getEventType()== sf::Event::KeyPressed && event.getKey() == sf::Keyboard::Left){
            this->left();
        }
    }
}

void Missions::right(){
    
    if(seleccionado!=4){
        if(seleccionado!=-1){

            if(seleccionado<3){
                //seleccionamos el siguiente
                seleccionado++;
                sprites[5].setPosition(sprites[seleccionado].getPositionX()+aumento,sprites[seleccionado].getPositionY());

            }
        }else{
            //seleccionamos el 1
            seleccionado=1;
            sprites[5].setPosition(sprites[seleccionado].getPositionX()+aumento,sprites[seleccionado].getPositionY());
        } 
    }
}

void Missions::left(){
    if(seleccionado!=4){
        if(seleccionado!=-1){
            if(seleccionado>1){
                //seleccionamos el anterior
                seleccionado--;
                sprites[5].setPosition(sprites[seleccionado].getPositionX()+aumento,sprites[seleccionado].getPositionY());
            }
        }else{
            //seleccionamos el 1
            seleccionado=1;
            sprites[5].setPosition(sprites[seleccionado].getPositionX()+aumento,sprites[seleccionado].getPositionY());
        }

    }
}

void Missions::down(){
    if(seleccionado!=4){
        //deseleccionamos mundo
        sprites[5].setPosition(-500,-500);
        //seleccionamos salir
        seleccionado=4;
        sprites[seleccionado].setTextureRect(1160,1220,400,130);
    }
}

void Missions::up(){
    if(seleccionado==4){
        //deseleccionamos salir
        sprites[seleccionado].setTextureRect(1575,1085,400,130);
        //seleccionamos mundo 2
        seleccionado=2;
        sprites[5].setPosition(sprites[seleccionado].getPositionX()+aumento,sprites[seleccionado].getPositionY());
    }
}

void Missions::update(){
    Partida::Instance()->setViewtoOrigin();
}

void Missions::draw(){
    for(int i=0;i<5;i++){
        m2D::RenderWindow::Instance()->draw(sprites[i]);
        if(i==0){
            m2D::RenderWindow::Instance()->draw(sprites[5]);
        }
    }
}

Missions::Missions(const Missions& orig) {
}

Missions::~Missions() {
}

void Missions::setDesbloq(){
    bool ya=false;
    for(int i=0;i<3&&ya==false;i++){
        if(desbloq[i]==0){
            desbloq[i]=1;
            ya=true;
            sprites[i+1].setColor(255,255,255);
            
        }
    }
}

