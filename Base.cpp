/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   Base.cpp
 * Author: shiro
 * 
 * Created on 16 de mayo de 2018, 16:11
 */

#include "Base.h"
#include "RenderWindow.h"
#include "Nave.h"
#include <string>
#include "Game.h"
#include <sstream>


Base* Base::pinstance=0;
Base* Base::Instance(){
    if(pinstance==0){
        pinstance=new Base;
    }
 
    return pinstance;
}

void Base::handleInput(){
    m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        
        if(event.getEventType()== sf::Event::Closed){
            
           m2D::RenderWindow::Instance()->close();
           
        }else if(event.getEventType()== sf::Event::KeyPressed){
            if(event.getKey() == sf::Keyboard::Return){
                intro.play();
                if(seleccionado!=-1){
                    if(seleccionado==2){
                        
                        this->reparar();
                        
                    }else{
                        
                        Game::Instance()->setState(Menu::Instance());
                        text[6].setString("");
                        this->resetSelected(); 
                        
                    }
                }
                
            }else if(event.getKey() == sf::Keyboard::Right){
                this->right();
                
            }else if(event.getKey() == sf::Keyboard::Left){
                this->left();
                
            }else if(event.getKey() == sf::Keyboard::Space){
                Nave::Instance()->getMaterials()[0]=100;
                Nave::Instance()->getMaterials()[1]=100;
                Nave::Instance()->getMaterials()[2]=100;
                Nave::Instance()->getMaterials()[3]=100;
                
            }
                
        }
    }
    
}

void Base::draw(){
    for(int i=0;i<10;i++){
        
        m2D::RenderWindow::Instance()->draw(sprites[i]);
        
    }
    if(animation==true){
        m2D::RenderWindow::Instance()->draw(sprites[10]);
        m2D::RenderWindow::Instance()->draw(sprites[11]);
    }
    
    for(int i=0;i<7;i++){
        m2D::RenderWindow::Instance()->drawT(text[i]);
    }
}

void Base::update(){
    if(animation==true){
        //cambiamos animacion
        if(animationClock.getElapsedTimeAsSeconds()>=0.20f){
            if(stateSprite==0){
                stateSprite=1;
                sprites[10].setTextureRect(220,1770,220,150);
                sprites[11].setTextureRect(220,1770,220,150);
            }else if(stateSprite==1){
                stateSprite=2;
                sprites[10].setTextureRect(440,1770,220,150);
                sprites[11].setTextureRect(440,1770,220,150);
            }else{
                stateSprite=0;
                sprites[10].setTextureRect(0,1770,220,150);
                sprites[11].setTextureRect(0,1770,220,150);
                animation=false; //terminamos la animacion
            }
            animationClock.restart();
        }
    }
}

void Base::right(){
    if(seleccionado==-1){
        sprites[3].setTextureRect(1160,1220,400,130);
        seleccionado=1;
        button.play();
    }else{
        //seleccionamos reparar
        sprites[2].setTextureRect(740,1220,400,130);
        //deseleccionamos salir
        sprites[3].setTextureRect(1575,1085,400,130);
        seleccionado=2;
        button.play();
    }
    
}

void Base::left(){
    if(seleccionado==-1){
        sprites[3].setTextureRect(1160,1220,400,130);
        seleccionado=1;
        button.play();
    }else{
        //seleccionamos salir
        sprites[3].setTextureRect(1160,1220,400,130);
        //deseleccionamos reparar
        sprites[2].setTextureRect(740,1085,400,130);
        seleccionado=1;
        button.play();
    }
}

void Base::resetSelected(){
    seleccionado=-1;
    sprites[2].setTextureRect(740,1085,400,130);
    sprites[3].setTextureRect(1575,1085,400,130);
}


Base::Base() {
    
    seleccionado=-1;
    animation=false;
    stateSprite=0;
    
    texture.setLoadFromFile("resources/BASE.png");
    
    sprites=new m2D::Sprite[12];
    for(int i=0;i<12;i++){
        sprites[i].setTexture(texture);
    }
    
    //fondo
    sprites[0].setOrigin(0,0);
    sprites[0].setTextureRect(0,0,1926,1080);
    sprites[0].setPosition(0,0);
    sprites[0].scale(0.8,0.8);
    
    //cuadro azul
    sprites[1].setOrigin(730/2,640/2);
    sprites[1].setTextureRect(0,1080,730,640);
    sprites[1].setPosition((1535/2),(860/2));
    sprites[1].scale(1.2,1.2);
    
    //reparar
    sprites[2].setOrigin(0,0);
    sprites[2].setTextureRect(740,1085,400,130); //el amarillo es 740,1220
    sprites[2].setPosition((1535/2)+50,(860/2)+250);
    sprites[2].scale(0.8,0.8);
    
    //salir
    sprites[3].setOrigin(0,0);
    sprites[3].setTextureRect(1575,1085,400,130); //amarillo 1160,1220
    sprites[3].setPosition((1535/2)-350,(860/2)+250);
    sprites[3].scale(0.8,0.8);
    
    //barra de vida
    sprites[4].setTextureRect(0,1733,234,19);
    sprites[4].setPosition(500,200);
    sprites[4].scale(2.3,2.3);
    
    this->reduceLifeBar();
    sprites[5].setPosition(516,212);
    sprites[5].scale(2.3,2.3);
    
    //materiales
    sprites[6].setTextureRect(1187,1120,30,35);
    sprites[6].setPosition(500,400);
    sprites[6].scale(2.5,2.5);
    
    sprites[7].setTextureRect(1218,1120,30,35);
    sprites[7].setPosition(500,550);
    sprites[7].scale(2.5,2.5);
    
    sprites[8].setTextureRect(1251,1120,30,35);
    sprites[8].setPosition(800,400);
    sprites[8].scale(2.5,2.5);
    
    sprites[9].setTextureRect(1283,1120,30,35);
    sprites[9].setPosition(800,550);
    sprites[9].scale(2.5,2.5);
    
    sprites[10].setTextureRect(0,1770,220,150); //2: //3:
    sprites[10].setOrigin(220/2,150/2);
    sprites[10].setPosition(640,225);
    sprites[10].scale(0.6,0.6);
    
    sprites[11].setTextureRect(0,1770,220,150); //2: //3:
    sprites[11].setOrigin(220/2,150/2);
    sprites[11].setPosition(900,225);
    sprites[11].scale(0.6,0.6);
    
    //textos
    font.loadFromFile("resources/pirulen.ttf");
    text=new m2D::Text[7];
    for(int i=0;i<7;i++){
        text[i].setFont(font);
        text[i].setColor(255,255,255);
    }
    
    text[0].setString("Base");
    text[0].setPosition((1535/2)-150,80);
    text[0].setCharacterSize(80);
    
    text[1].setString("Coste de reparacion:");
    text[1].setPosition((1535/2)-250,300);
    
    text[2].setPosition(600,425);
    
    text[3].setPosition(600,575);
    
    text[4].setPosition(900,425);
    
    text[5].setPosition(900,575);
    
    text[6].setString("");
    text[6].setPosition((1535/2)-390,350);
    text[6].setColor(255,0,0);
    
    
    this->checkMaterialsNedeed();
    
    button.openFromFile("resources/button-33a.ogg");
    button.setLoop(false);
    button.setVolumen(100);
    
    intro.openFromFile("resources/button-34.ogg");
    intro.setLoop(false);
    intro.setVolumen(100);
}

void Base::reduceLifeBar(){
    if(Nave::Instance()->getLife()>0){
        sprites[5].setTextureRect(0,1721,(Nave::Instance()->getLife()*221)/1000,8);
    }else{
        sprites[5].setTextureRect(0,1721,0,8);
    }
}

void Base::checkMaterialsNedeed(){
    
    if(Nave::Instance()->getLife()>=750){
        titanio=1;
        magnesio=2;
        hierro=3;
        carbon=2;
    }else if(Nave::Instance()->getLife()>500&&Nave::Instance()->getLife()<750){
        titanio=3;
        magnesio=4;
        hierro=6;
        carbon=6;
    }else if(Nave::Instance()->getLife()>250&&Nave::Instance()->getLife()<=500){
        titanio=7;
        magnesio=8;
        hierro=14;
        carbon=10;
    }else if(Nave::Instance()->getLife()<=250){
        titanio=10;
        magnesio=12;
        hierro=15;
        carbon=18;
    }
    
    //titanio magnesio hierro crbon
    
    std::stringstream ss;
    ss << titanio;
    std::string strs = ss.str();
    std::stringstream rr;
    rr << Nave::Instance()->getMaterials()[0];
    std::string strr = rr.str();
    text[2].setString("x"+strs+" ("+strr+")");
    
    std::stringstream ss1;
    ss1 << carbon;
    std::string strs1 = ss1.str();
    std::stringstream rr1;
    rr1 << Nave::Instance()->getMaterials()[3];
    std::string strr1 = rr1.str(); 
    text[3].setString("x"+strs1+" ("+strr1+")");
    
    std::stringstream ss2;
    ss2 << magnesio;
    std::string strs2 = ss2.str();
    std::stringstream rr2;
    rr2 << Nave::Instance()->getMaterials()[1];
    std::string strr2 = rr2.str();
    text[4].setString("x"+strs2+" ("+strr2+")");
    
    std::stringstream ss3;
    ss3 << hierro;
    std::string strs3 = ss3.str();
    std::stringstream rr3;
    rr3 << Nave::Instance()->getMaterials()[2];
    std::string strr3 = rr3.str();
    text[5].setString("x"+strs3+" ("+strr3+")");
    
    
}

void Base::reparar(){
    
    if(Nave::Instance()->getMaterials()[0]>=titanio&&Nave::Instance()->getMaterials()[1]>magnesio&Nave::Instance()->getMaterials()[2]>=hierro&&Nave::Instance()->getMaterials()[3]>=carbon){
        if(Nave::Instance()->getLife()!=1000){
            Nave::Instance()->getMaterials()[0]=Nave::Instance()->getMaterials()[0]-titanio;
            Nave::Instance()->getMaterials()[1]=Nave::Instance()->getMaterials()[1]-magnesio;
            Nave::Instance()->getMaterials()[2]=Nave::Instance()->getMaterials()[2]-hierro;
            Nave::Instance()->getMaterials()[3]=Nave::Instance()->getMaterials()[3]-carbon;

            Nave::Instance()->setLife(1000);
            Nave::Instance()->saveLife(1000);
            animation=true;
            animationClock.restart();
            text[6].setString("");
        }
        
    }else{
        //no hay suficientes
        text[6].setString("No tienes suficientes materiales");
    }
    
    
    this->checkMaterialsNedeed();
    this->reduceLifeBar();
}

Base::Base(const Base& orig) {
}

Base::~Base() {
}


