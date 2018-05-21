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
#include "Partida.h"
#include "Missions.h"

Pausa* Pausa::pinstance=0;
Pausa* Pausa::Instance(){
    if(pinstance==0){
        pinstance=new Pausa;
    }
    
    return pinstance;
}

Pausa::Pausa() {
    
    seleccionado=-1;
    
    texture.setLoadFromFile("resources/interfaz.png");
    
    sprites=new m2D::Sprite[3];
    
    for(int i=0;i<3;i++){
        sprites[i].setTexture(texture);
    }
    
    //fondo
    sprites[0].setOrigin(730/2,640/2);
    sprites[0].setPosition(1535/2,860/2);
    sprites[0].setTextureRect(0,1080,730,640);
    sprites[0].scale(2.11,1.345);
    
    //boton reanudar
    sprites[1].setOrigin(400/2,130/2);
    sprites[1].setPosition(1535/2,860/2+50);
    sprites[1].setTextureRect(790,1615,400,130); //amarillo 790,1750
    sprites[1].scale(0.7,0.7);
    
    //boton salir
    sprites[2].setOrigin(400/2,130/2);
    sprites[2].setPosition(1535/2,860/2+150);
    sprites[2].setTextureRect(1575,1085,400,130); //amarillo 1160,1220
    sprites[2].scale(0.7,0.7);
    
    //texto
    font.loadFromFile("resources/pirulen.ttf");
    
    
    text.setFont(font);
    text.setCharacterSize(100);
    text.setString("Pausa");
    text.setPosition((1535/2)-225,(860/2)-250);
    text.setColor(70,255,213);
    
    button.openFromFile("resources/button-33a.ogg");
    button.setLoop(false);
    button.setVolumen(100);
    
    intro.openFromFile("resources/button-34.ogg");
    intro.setLoop(false);
    intro.setVolumen(100);
}

void Pausa::handleInput(){
    m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        
        if(event.getEventType()== sf::Event::Closed){
           m2D::RenderWindow::Instance()->close();
        }
        else if(event.getEventType()== sf::Event::KeyPressed){
            if(event.getKey() == sf::Keyboard::Return){
                intro.play();
                if(seleccionado!=-1){
                    if(seleccionado==1){
                        Partida::Instance()->setViewtoShip();
                        Game::Instance()->setState(Partida::Instance());
                        
                    }else{
                        Nave::Instance()->borrarBalas();
                        Nave::Instance()->setMunition(1);
                        Nave::Instance()->setCanyonBool();
                        Partida::Instance()->pausarMusica();
                        Menu::Instance()->playMusica();
                        
                        if(Partida::Instance()->getMode() == 0){
                            Partida::Instance()->saveLife();
                            Game::Instance()->setState(Missions::Instance());
                        }else{
                            Partida::Instance()->setStartI();
                            Game::Instance()->setState(Menu::Instance()); 
                        }
                        
                    }
                    
                    this->resetSelected();
                }
                
            }else if(event.getKey() == sf::Keyboard::Up){
                button.play();
                this->up();
            }else if(event.getKey() == sf::Keyboard::Down){
                button.play();
                this->down();
            }
                
        }
    }
}

void Pausa::up(){
    if(seleccionado!=-1){
        if(seleccionado>1){
            sprites[seleccionado].setTextureRect(1575,1085,400,130);
            seleccionado--;
            sprites[seleccionado].setTextureRect(790,1750,400,130);
        }
    }else{
        seleccionado=1;
        sprites[seleccionado].setTextureRect(790,1750,400,130);
    }
}

void Pausa::down(){
    if(seleccionado!=-1){
        if(seleccionado<2){
            sprites[seleccionado].setTextureRect(790,1615,400,130);
            seleccionado++;
            sprites[seleccionado].setTextureRect(1160,1220,400,130);
        }
    }else{
        seleccionado=1;
        sprites[seleccionado].setTextureRect(790,1750,400,130);
    }
}

void Pausa::draw(){
    
    for(int i=0;i<3;i++){
        m2D::RenderWindow::Instance()->draw(sprites[i]);
    }
    
    m2D::RenderWindow::Instance()->drawT(text);
}

void Pausa::update(){
    Partida::Instance()->setViewtoOrigin();
   
}

Pausa::Pausa(const Pausa& orig) {
}

Pausa::~Pausa() {
}

void Pausa::resetSelected(){
    seleccionado=-1;
    sprites[1].setTextureRect(790,1615,400,130);
    sprites[2].setTextureRect(1575,1085,400,130);
}

void Pausa::Thanos(){
    if(pinstance!=0){
        intro.close();
        button.close();
    }
}
