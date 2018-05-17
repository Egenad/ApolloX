/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tienda.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:31
 */

#include "Logo.h"
#include "Menu.h"
#include "RenderWindow.h"
#include "Game.h"
#include "Missions.h"
#include <iostream>

Logo* Logo::pinstance=0;

Logo* Logo::Instance(){
    if(pinstance==0){
        pinstance=new Logo;
    }
    return pinstance;
}

void Logo::handleInput(){
  m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        
        if(event.getEventType()== sf::Event::Closed){
           m2D::RenderWindow::Instance()->close();
        }
    }
}

void Logo::update(){
    if(time.getElapsedTimeAsSeconds() > 5){
        Game::Instance()->setState(Menu::Instance());
    }
    if(time.getElapsedTimeAsSeconds() > 4){
        if(alpha < 255)
            alpha += 5;
        sprites[1].setColorWithA(0,0,0,alpha);
    }
        
}

void Logo::draw(){
    m2D::RenderWindow::Instance()->draw(sprites[0]);
    m2D::RenderWindow::Instance()->draw(sprites[1]);
}

Logo::Logo(){
    texture.setLoadFromFile("resources/logo.png");
    texture2.setLoadFromFile("resources/color_negro.jpg");
    alpha = 0;
    
    sprites=new m2D::Sprite[2];
    sprites[0].setTexture(texture);
    
    //fondo
    sprites[0].setOrigin(0,0);
    sprites[0].setPosition(90,40);
    sprites[0].scale(0.65,0.65);
    
    sprites[1].setTexture(texture2);
    
    //fondo
    sprites[1].setOrigin(0,0);
    sprites[1].setPosition(90,40);
    sprites[1].setColorWithA(0,0,0,alpha);
}

Logo::Logo(const Logo& orig){}

Logo::~Logo(){}

