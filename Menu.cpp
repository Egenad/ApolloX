/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:30
 */

#include "Menu.h"
#include "RenderWindow.h"
#include "Game.h"
#include "Event.h"
#include "Pausa.h"
#include "Missions.h"
#include "Partida.h"
#include <iostream>
#include "Base.h"

Menu* Menu::pinstance=0;
Menu* Menu::Instance(){
    if(pinstance==0){
        pinstance=new Menu;
    }
    
    return pinstance;
}

void Menu::handleInput(){
    m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        
        if(event.getEventType()== sf::Event::Closed){
           m2D::RenderWindow::Instance()->close();
        }
        
        if(event.getEventType()== sf::Event::KeyPressed && event.getKey() == sf::Keyboard::Return){
            intro.play();
            if(seleccionado==4){
                m2D::RenderWindow::Instance()->close();
            }else if(seleccionado==3){
                //base
                Game::Instance()->setState(Base::Instance());
                Base::Instance()->checkMaterialsNedeed();
                Base::Instance()->reduceLifeBar();
            }else if(seleccionado==2){
                //infinito
                music.pause();
                Game::Instance()->setState(Partida::Instance());
                Partida::Instance()->Infinite();
            }else if(seleccionado==1){
                //misiones
                Game::Instance()->setState(Missions::Instance());
            }
            
            this->resetSelected();
            
            
        }else if(event.getEventType()== sf::Event::KeyPressed && event.getKey() == sf::Keyboard::Down){
            if(seleccionado!=-1){
                this->down();
            }else{
                seleccionado=1;
                sprites[seleccionado].setTextureRect(740,1485,400,130);
            }
            
        }else if(event.getEventType()== sf::Event::KeyPressed && event.getKey() == sf::Keyboard::Up){
            if(seleccionado!=-1){
                this->up();
            }else{
                seleccionado=1;
                //ponemos el 1 a selecionado
                sprites[seleccionado].setTextureRect(740,1485,400,130);
            }
        }
    }
}

void Menu::update(){
    
}

void Menu::draw(){
    for(int i=0;i<5;i++){
        m2D::RenderWindow::Instance()->draw(sprites[i]);
        if(i==0){
            m2D::RenderWindow::Instance()->draw(sprites[5]);
        }
    }
}


Menu::Menu() {
    
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
    
    //texto
    //historia
    sprites[1].setOrigin(0,0);
    sprites[1].setTextureRect(740,1350,400,130); //amarillo 740,1485
    sprites[1].setPosition((1535/2)-140,(860/2)-60);
    sprites[1].scale(0.8,0.8);
    //infinto
    sprites[2].setOrigin(0,0);
    sprites[2].setTextureRect(740,1085,400,130); //el amarillo es 740,1220
    sprites[2].setPosition((1535/2)-140,(860/2)+25);
    sprites[2].scale(0.8,0.8);
    //base
    sprites[3].setOrigin(0,0);
    sprites[3].setTextureRect(1575,1220,400,130); //amarillo 1160,1355
    sprites[3].setPosition((1535/2)-140,(860/2)+110);
    sprites[3].scale(0.8,0.8);
    //salir
    sprites[4].setOrigin(0,0);
    sprites[4].setTextureRect(1575,1085,400,130); //amarillo 1160,1220
    sprites[4].setPosition((1535/2)-140,(860/2)+195);
    sprites[4].scale(0.8,0.8);
    
    //cuadro azul
    sprites[5].setOrigin(730/2,640/2);
    sprites[5].setTextureRect(0,1080,730,640);
    sprites[5].setPosition((1535/2)+30,(860/2)+120);
    sprites[5].scale(0.7,0.7);
    
    //musica menu
    music.openFromFile("resources/Europa.ogx");
    music.setLoop(true);
    music.play();
    
    button.openFromFile("resources/button-33a.ogg");
    button.setLoop(false);
    button.setVolumen(50);
    
    intro.openFromFile("resources/button-34.ogg");
    intro.setLoop(false);
    intro.setVolumen(50);
}

void Menu::up(){
    if(seleccionado>1){
        if(seleccionado==2){
            //deseleccionamos infinito
            sprites[seleccionado].setTextureRect(740,1085,400,130);
            //seleccionamos historia
            sprites[seleccionado-1].setTextureRect(740,1485,400,130);
        }else if(seleccionado==3){
            //deseleccionamos base
            sprites[seleccionado].setTextureRect(1575,1220,400,130);
            //seleccionamos infinito
            sprites[seleccionado-1].setTextureRect(740,1220,400,130);
        }else if(seleccionado==4){
            //deseleccionamos salir
            sprites[seleccionado].setTextureRect(1575,1085,400,130);
            //seleccionamos base
            sprites[seleccionado-1].setTextureRect(1160,1355,400,130);
        }
        seleccionado--;
    }
    //efecto sonido
    button.play();
}

void Menu::down(){
    if(seleccionado<4){
        if(seleccionado==2){
            //deseleccionamos infinito
            sprites[seleccionado].setTextureRect(740,1085,400,130);
            //seleccionamos base
            sprites[seleccionado+1].setTextureRect(1160,1355,400,130);
        }else if(seleccionado==3){
            //deseleccionamos base
            sprites[seleccionado].setTextureRect(1575,1220,400,130);
            //seleccionamos salir
            sprites[seleccionado+1].setTextureRect(1160,1220,400,130);
        }else if(seleccionado==1){
            //deseleccionamos historia
            sprites[seleccionado].setTextureRect(740,1350,400,130);
            //seleccionamos infinito
            sprites[seleccionado+1].setTextureRect(740,1220,400,130);
        }
        seleccionado++;
    }
    button.play();
}


Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

void Menu::resetSelected(){
    seleccionado=-1;
    sprites[1].setTextureRect(740,1350,400,130);
    sprites[2].setTextureRect(740,1085,400,130);
    sprites[3].setTextureRect(1575,1220,400,130);
}

void Menu::pausarMusica(){
    music.pause();
}

