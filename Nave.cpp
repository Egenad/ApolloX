/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nave.cpp
 * Author: raquel
 * 
 * Created on 27 de febrero de 2018, 18:18
 */
#include <iostream>
#include "Nave.h"
#include "RenderWindow.h"
#include "Texture.h"
#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"
#include "Bala.h"
#include "Alien.h"

Nave* Nave::pinstance=0;
Nave* Nave::Instance(){
    if(pinstance==0){
        pinstance=new Nave;
    }
    
    return pinstance;
}


Nave::Nave (){
    position.setVectorX(1535/2);
    position.setVectorY(0);
    state=2;
    velocity=5;
    animationType=0;
    munition = 1; // cambiar en un futuro
    life=1000;
    canyon = false;
    bomb_alive = false;
    lastMove.setVectorX(0.0f);
    lastMove.setVectorY(0.0f);
    contador_canyon = 0;
    moving = false;
    explosion = false;
}
Nave::Nave(const Nave& orig) {
}

Nave::~Nave() {
}

void Nave::disparar(m2D::Texture& texture){
    if(!canyon && tiempo_entre_balas.getElapsedTimeAsSeconds() > 0.2){
        tiempo_entre_balas.restart();
        switch(munition){
            case 1:{
                Bala * bullet = new Bala(texture, 1, 20.0f);
                bullet->setPos(m2D::Vector2f(position.getVectorX(), position.getVectorY()));
                vectorBalas.push_back(bullet);
            }break;
            case 2:{
                float angul = 60;
                for(int i=0; i<6; i++){
                    if(i < 4){
                        Bala * bullet = new Bala(texture, 2, angul, 20.0f);
                        bullet->setPos(m2D::Vector2f(position.getVectorX(), position.getVectorY()));
                        vectorBalas.push_back(bullet);
                        angul = angul + 20;
                    }
                    else{
                        angul = angul - 40;
                        Bala * bullet = new Bala(texture, 2, angul, 16.0f);
                        bullet->setPos(m2D::Vector2f(position.getVectorX(), position.getVectorY()));
                        vectorBalas.push_back(bullet);
                        angul = angul + 20;
                    }
                }
            }break;
            case 3:{
                for(int i=0; i<2; i++){
                    if(i==0){
                        Bala * bullet = new Bala(texture, 3, 30.0f);
                        if(!moving){
                            bullet->setPos(m2D::Vector2f(position.getVectorX()-17, position.getVectorY()-20));
                        }
                        else{
                            if(lastMove.getVectorX() < 0){
                                bullet->setPos(m2D::Vector2f(position.getVectorX()-10, position.getVectorY()-20));
                            }
                            else{
                                bullet->setPos(m2D::Vector2f(position.getVectorX()-24, position.getVectorY()-20));
                            }
                        }
                        vectorBalas.push_back(bullet);
                    }else{
                        Bala * bullet = new Bala(texture, 6, 30.0f);
                        if(!moving){
                            bullet->setPos(m2D::Vector2f(position.getVectorX()-17, position.getVectorY()-20));
                        }
                        else{
                            if(lastMove.getVectorX() < 0){
                                bullet->setPos(m2D::Vector2f(position.getVectorX()-10, position.getVectorY()-20));
                            }
                            else{
                                bullet->setPos(m2D::Vector2f(position.getVectorX()-24, position.getVectorY()-20));
                            }
                        }
                        vectorBalas.push_back(bullet);
                    }
                }

                cb_time.restart();
                canyon = true;       
            }break;
            case 4:{
                if(!bomb_alive){
                    Bala * bullet = new Bala(texture, 4, 15.0f);
                    bullet->setPos(m2D::Vector2f(position.getVectorX()-5, position.getVectorY()-50));
                    vectorBalas.push_back(bullet);
                    bomb_alive = true;
                    cb_time.restart();
                    explosion = false;
                }
            }break;
        }
    }
}

void Nave::setMunition(int n){
    munition = n;
}

int Nave::getMunition(){
    return munition;
}

void Nave::setState(int d){
    state=d;
}
m2D::Vector2f& Nave::getPosition(){
    return position;
}
int Nave::getState(){
    return state;
}
void Nave::setPosition(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
    
    sprite.setPosition(position.getVectorX(),position.getVectorY());
}

void Nave::setTexture(m2D::Texture& texture){
    sprite.setTexture(texture);
    sprite.setOrigin(110/2,139/2);
    sprite.setTextureRect(0,212,110,139);
    sprite.setPosition(1535/2,0);
    sprite.scale(0.8,0.8);
}

void Nave::draw(){
    for(int i=0; i<vectorBalas.size(); i++){
        vectorBalas[i]->draw();
    }
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Nave::update(){
    //cambiamos animacion
    if(animation.getElapsedTimeAsSeconds()>=0.5f){
        if(animationType==0){
            animationType=1;
            sprite.setTextureRect(110,212,110,142);
        }else{
            animationType=0;
            sprite.setTextureRect(0,212,110,139);
        }
        animation.restart();
    }
    //cambiamos posicion
    this->setPosition(position.getVectorX(),position.getVectorY()-velocity);
    
    //updateamos balas
    if(!vectorBalas.empty()){
        for(int i=0; i<vectorBalas.size(); i++){         
            if(vectorBalas[i]->getTipo() == 1){
                vectorBalas[i]->disparar();
            }else if(vectorBalas[i]->getTipo() == 2){
                vectorBalas[i]->disparar_angulo(1);
            }else if(vectorBalas[i]->getTipo() == 3 || vectorBalas[i]->getTipo() == 6){
                vectorBalas[i]->disparar_canyon(position, vectorBalas[i]->getTipo()); 
                if(cb_time.getElapsedTimeAsSeconds() >= 1){
                    vectorBalas[i]->escalarCanyon();
                    vectorBalas[i]->moverbala(contador_canyon); 
                    if(contador_canyon > 4){
                        if(vectorBalas[i]->getTipo() == 6){
                            contador_canyon = 0;
                            canyon = false;
                            munition = 1;
                        } 
                        delete vectorBalas[i];
                        vectorBalas.erase(vectorBalas.begin() + i);     
                    }
                    else{
                        if(vectorBalas[i]->getTipo() == 6){
                            cb_time.restart();
                            contador_canyon++;
                        }
                    }
                }    
            }else{
                if(cb_time.getElapsedTimeAsSeconds() > 0.6){
                    delete vectorBalas[i];
                    vectorBalas.erase(vectorBalas.begin() + i);
                    bomb_alive = false;
                    explosion = false;
                } 
                else if(cb_time.getElapsedTimeAsSeconds() > 0.5){
                    if(!explosion){
                        vectorBalas[i]->disparar_bomba(2);
                        explosion = true;
                    }
                }
                else{
                    vectorBalas[i]->disparar_bomba(1);   
                }
            }
            float res = position.getVectorY() - vectorBalas[i]->getY();
            if(vectorBalas[i]->getTipo()!=3){
                if(res > 800 || vectorBalas[i]->getX() < 340 || vectorBalas[i]->getX() > 1190){
                    if(vectorBalas[i]->getTipo() == 4){
                        bomb_alive = false;
                    }
                    delete vectorBalas[i];
                    vectorBalas.erase(vectorBalas.begin() + i);
                    i--;
                }
            }
        }      
    }
}

void Nave::moveLeft(){
    if(position.getVectorX()>375){ //475
        this->setPosition(position.getVectorX()-velocity-5,position.getVectorY());
    }
}
void Nave::moveRight(){
    if(position.getVectorX()<1150){ //1059
        this->setPosition(position.getVectorX()+velocity+5,position.getVectorY());
    }
}

bool Nave::checkCollMete(Meteorito& meteorito){
        //ESTAMOS COLISIONANDO 100%
    bool cola=false;
    if(sprite.getGlobalBounds().intersects(meteorito.returnShape().getGlobalBounds())){ 
        //detectar lo de la vida
        cola=true;
        
        life = life - 50;
        if(life<=0){
           sprite.setPosition(10000,10000);
        }
    }
}

bool Nave::checkColl(Bala &bullet){//COLISIONES
        //ESTAMOS COLISIONANDO 100%
    bool cola=false;
    if(sprite.getGlobalBounds().intersects(bullet.returnShape().getGlobalBounds())){ 
        //detectar lo de la vida
        cola=true;
        life = life - 225;
        if(life<=0){
           sprite.setPosition(10000,10000);
        }
    }
    
    return cola;
}

int Nave::getLife(){
    return life;
}


void Nave::golpea(m2D::Sprite& alien){
    for(int i=0;i<vectorBalas.size();i++){
        if(vectorBalas[i]->returnShape().getGlobalBounds().intersects(alien.getGlobalBounds())){
            delete vectorBalas[i];
            vectorBalas.erase(vectorBalas.begin()+i);
            alien.setPosition(1000,1000);//lo saca del mapa
        }
    }
}