/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resultado.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:31
 */

#include "Resultado.h"

#include "RenderWindow.h"
#include "Nave.h"
#include <string>
#include "Game.h"
#include "Partida.h"
#include <sstream>
#include "Missions.h"


Resultado* Resultado::pinstance=0;
Resultado* Resultado::Instance(){
    if(pinstance==0){
        pinstance=new Resultado;
    }
 
    return pinstance;
}

Resultado::Resultado() {
    
    seleccionado=-1;
    stateSprite=0;
    
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
    
    
    //misiones
    sprites[1].setOrigin(0,0);
    sprites[1].setTextureRect(740,1350,400,130); //amarillo 740,1485
    sprites[1].setPosition((1535/2)+50,(860/2)+150);
    sprites[1].scale(0.8,0.8);
    
    //salir
    sprites[2].setOrigin(0,0);
    sprites[2].setTextureRect(1575,1085,400,130); //amarillo 1160,1220
    sprites[2].setPosition((1535/2)-350,(860/2)+150);
    sprites[2].scale(0.8,0.8);
    
    
    //textos
    font.loadFromFile("resources/pirulen.ttf");
    text=new m2D::Text[2];
    for(int i=0;i<2;i++){
        text[i].setFont(font);
        text[i].setColor(255,255,255);
    }

    text[0].setString("Puntuacion");
    text[0].setPosition((1535/2)-250,(860/2)-250);
    text[0].setCharacterSize(60);
    text[0].setColor(70,255,213);
    

    text[1].setString("0");
    text[1].setPosition((1535/2)-100,350);
    text[1].setCharacterSize(50);
    
    button.openFromFile("resources/button-33a.ogg");
    button.setLoop(false);
    button.setVolumen(100);
    
    intro.openFromFile("resources/button-34.ogg");
    intro.setLoop(false);
    intro.setVolumen(100);
}

Resultado::Resultado(const Resultado& orig) {
}

Resultado::~Resultado() {
}
void Resultado::setScore(int s){

    std::stringstream sa;
    sa << s;
    std::string strs = sa.str();
    text[1].setString(strs);
}

void Resultado::handleInput(){
    m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        
        if(event.getEventType()== sf::Event::Closed){
            
           m2D::RenderWindow::Instance()->close();
           
        }else if(event.getEventType()== sf::Event::KeyPressed){
            if(event.getKey() == sf::Keyboard::Return){
                intro.play();
                if(seleccionado!=-1){
                    if(seleccionado==2){
                        
                        if(Partida::Instance()->getMode()==0){
                            Game::Instance()->setState(Missions::Instance());
                        }else if(Partida::Instance()->getMode()==1){
                            Partida::Instance()->Infinite();
                            Game::Instance()->setState(Partida::Instance());
                        }
                        
                    }else{
                        
                        Game::Instance()->setState(Menu::Instance());
                        text[1].setString("");
                        this->resetSelected(); 
                        
                    }
                }
                
            }else if(event.getKey() == sf::Keyboard::Right){
                this->right();
                
            }else if(event.getKey() == sf::Keyboard::Left){
                this->left();
                
            }
                
        }
    }
    
}

void Resultado::draw(){
    for(int i=0;i<3;i++){
        
        m2D::RenderWindow::Instance()->draw(sprites[i]);
        
    }
    
    for(int i=0;i<2;i++){
        m2D::RenderWindow::Instance()->drawT(text[i]);
    }
}

void Resultado::update(){
   Partida::Instance()->setViewtoOrigin();
}

void Resultado::right(){
    if(seleccionado==-1){
        sprites[2].setTextureRect(1160,1220,400,130);
        seleccionado=1;
        button.play();
    }else{
        //seleccionamos reparar
        sprites[1].setTextureRect(740,1485,400,130);
        //deseleccionamos salir
        sprites[2].setTextureRect(1575,1085,400,130);
        seleccionado=2;
        button.play();
    }
    
}

void Resultado::left(){
    if(seleccionado==-1){
        sprites[2].setTextureRect(1160,1220,400,130);
        seleccionado=1;
        button.play();
    }else{
        //seleccionamos salir
        sprites[2].setTextureRect(1160,1220,400,130);
        //deseleccionamos reparar
        sprites[1].setTextureRect(740,1350,400,130);
        seleccionado=1;
        button.play();
    }
}

void Resultado::resetSelected(){
    seleccionado=-1;
    sprites[1].setTextureRect(740,1350,400,130);
    sprites[2].setTextureRect(1575,1085,400,130);
}