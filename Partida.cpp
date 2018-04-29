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

#include "Game.h"
#include "Pausa.h"
#include "Partida.h"
#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"
#include "RenderWindow.h"
#include "Meteorito.h"
#include "FactoriaNivel.h"
#include <math.h>
#include <sstream>
#include <string>

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
    state=0;
    
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
                    if(state==0){
                        ship->disparar(texture);
                    }
                break;
                
                case sf::Keyboard::Right:
                    if(state==0){
                        ship->moveRight();
                    }
                break;
                
                case sf::Keyboard::Left:
                    if(state==0){
                        ship->moveLeft();
                    }
                break;
                
                case sf::Keyboard::Escape:
                    Game::Instance()->setState(Pausa::Instance());
                break;
            }
        }
    }
}

void Partida::update(){
    if(state==0){
        //updateamos el fondo
        this->moveBackground();
        //updateamos el player
        ship->update();
        if(ship->getPosition().getVectorY()<=(-length-860)){
            state=1;
        }
        
        //updateamos la vista
        view.setCenter(1535/2,ship->getPosition().getVectorY()-360);
        m2D::RenderWindow::Instance()->setView(view);
        
        
        //UPDATE METEORITO
        for(int i=0;i<t3;i++){
           if((view.getCenter().getVectorY()+420)>meteor[i].getCoord().getVectorY()&&(view.getCenter().getVectorY()-420)<meteor[i].getCoord().getVectorY()){
                meteor[i].update();
                ship->checkCollMete(meteor[i]);//comprobamos la colision de los meteorios con la nave
                //std::cout << "vida: " << ship->getLife()<<std::endl;
            }      
        }
 
        //UPDATE ALIENS A (GRANDES)
        for(int i=0;i<t1;i++){
            //los updateamos solo si estan dentro de la pantalla
            if((view.getCenter().getVectorY()+420)>aliens[i].getPos().getVectorY()&&(view.getCenter().getVectorY()-420)<aliens[i].getPos().getVectorY()){
                aliens[i].Update();
                aliens[i].dibujaBalas();
                aliens[i].dispara(texture);
                ship->golpea(aliens[i].getShape()); //si mata al alien
            }
        }
    }else{
        //updateamos de distinta forma
    }
    
}

void Partida::draw(){
    for(int i=0;i<3;i++){
        m2D::RenderWindow::Instance()->draw(background[i]);
    }
    
    ship->draw();
    
    for(int i=0;i<t3;i++){
        if((view.getCenter().getVectorY()+420)>meteor[i].getCoord().getVectorY()&&(view.getCenter().getVectorY()-420)<meteor[i].getCoord().getVectorY()){
            if(meteor[i].getCoord().getVectorX()<1059&&meteor[i].getCoord().getVectorX()>475){
                meteor[i].draw();
            }
        }
    }
    
    for(int i=0;i<t1;i++){
        //los dibujamos solo si estan dentro de la pantalla
        if((view.getCenter().getVectorY()+420)>aliens[i].getPos().getVectorY()&&(view.getCenter().getVectorY()-420)<aliens[i].getPos().getVectorY()){
            //si se ha salido de los bordes no dibujamos pero si updateamos
            if(aliens[i].getPos().getVectorX()<1059&&aliens[i].getPos().getVectorX()>475){
                aliens[i].draw();
            }
        }
    }
    
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

void Partida::Init(int i){
    
    FactoriaNivel* fLvl = FactoriaNivel::Instance();

    fLvl->readLevel(i);

    const char* p = fLvl->getPath();
    std::stringstream ss;
    ss << p;
    ss>>length;
    
    const char* enemy1 = fLvl->getAlien1();
    std::stringstream ss2;
    ss2 << enemy1;
    ss2>>t1;
    
    const char* enemy2 = fLvl->getAlien2();
    std::stringstream ss3;
    ss3 << enemy2;
    ss3>>t2;
    
    const char* m = fLvl->getMeteor();
    std::stringstream ss4;
    ss4 << m;
    ss4>>t3;

    int totalEnemies=t3+t2+t1;
    
    int cont1=0;
    int cont2=0;
    int cont3=0;
    
    int* enemiesB=new int[t2];
    int ran3=rand()%100;
    meteor=new Meteorito[t3]; //meteoritos
    aliens=new Alien[t1]; //aliens
    srand(time(NULL));
    for(int i=0;i<totalEnemies;i++){
        int a=rand() % 9;
        if(a>=0&&a<=5){
            //creamos enemigo A
            if(cont1<t1){
                
                int x1=rand() % 585;
                x1=x1+475;
                int y1 =(length/totalEnemies)*i;
                aliens[cont1].setPos(x1,-y1-860);
                aliens[cont1].setTexture(texture);
                cont1++;
                
            }else if(cont2<t2){
                enemiesB[cont2]=i;
                cont2++;
            }else if(cont3<t3){
                int x=rand() % 585;
                x=x+475;
                int y =(length/totalEnemies)*i;
                meteor[cont3].setCoord(x,-y-860);
                meteor[cont3].setTexture(texture);
                cont3++;
            }
            
        }else if(a>=6&&a<=7){
            //creamos meteorito
            if(cont2<t2){
                
                enemiesB[cont2]=i;
                cont2++;
            }else if(cont3<t3){
                int x=rand() % 585;
                x=x+475;
                int y =(length/totalEnemies)*i;
                meteor[cont3].setCoord(x,-y-860);
                meteor[cont3].setTexture(texture);
                cont3++;
                
            }else if(cont1<t1){
                
                int x1=rand() % 585;
                x1=x1+475;
                int y1 =(length/totalEnemies)*i;
                aliens[cont1].setPos(x1,-y1-860);
                aliens[cont1].setTexture(texture);
                cont1++;
            }
        }else{
            //creamos enemigo B
            if(cont3<t3){
                int x=rand() % 585;
                x=x+475;
                int y =(length/totalEnemies)*i;
                meteor[cont3].setCoord(x,-y-860);
                meteor[cont3].setTexture(texture);
                cont3++;
                
            }else if(cont1<t1){
                
                int x1=rand() % 585;
                x1=x1+475;
                int y1 =(length/totalEnemies)*i;
                aliens[cont1].setPos(x1,-y1-860);
                aliens[cont1].setTexture(texture);
                cont1++;
            }else if(cont2<t2){
                
                enemiesB[cont2]=i;
                cont2++;
            }
        }
    }
    
}

float Partida::getCoordViewX(){
    return view.getCenter().getVectorX();
}
float Partida::getCoordViewY(){
    return view.getCenter().getVectorY();
}

void Partida::setViewtoOrigin(){
    view.setCenter(1535/2,860/2);
    m2D::RenderWindow::Instance()->setView(view);
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

