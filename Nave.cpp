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
#include "Game.h"
#include "Missions.h"
#include "Partida.h"

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
    materials=new int[4];
    for(int i=0;i<4;i++){
        materials[i]=0;
    }
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
    
    if(state==1){
        //escudo
        sprite.setTextureRect(2*110,212,110,142);
        sprite2.setTextureRect(2*110,290,0,0);
        sprite.setPosition(1535/2,100);
        sprite.setOrigin(110/2,142/2);
        shell.restart();
    }else if(state==2){
        //normal
        sprite.setTextureRect(35,212,40,139);
        sprite2.setTextureRect(0,290,110,60);
        sprite2.setOrigin(110/2,60/2);
        sprite.setOrigin(40/2,139/2);
        sprite.setPosition(1535/2,0);
    }
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
    sprite2.setPosition(position.getVectorX(),position.getVectorY()+15);
    sprite.setPosition(position.getVectorX(),position.getVectorY());
}

void Nave::setTexture(m2D::Texture& texture){
    sprite.setTexture(texture);
    sprite.setOrigin(40/2,139/2);
    sprite.setTextureRect(35,212,40,139);
    sprite.setPosition(1535/2,0);
    sprite.scale(0.4,0.4);
    sprite2.setTexture(texture);
    sprite2.setOrigin(110/2,60/2);
    sprite2.setTextureRect(0,290,110,60);
    sprite2.setPosition(1535/2,100);
    sprite2.scale(0.4,0.4);
}

void Nave::draw(){
    for(int i=0; i<vectorBalas.size(); i++){
        vectorBalas[i]->draw();
    }
    m2D::RenderWindow::Instance()->draw(sprite);
    m2D::RenderWindow::Instance()->draw(sprite2);
}

void Nave::update(){
    //cambiamos animacion
    if(animation.getElapsedTimeAsSeconds()>=0.5f){
        if(animationType==0){
            animationType=1;
            if(state==2){
                sprite2.setTextureRect(110,290,110,65);
            }else if(state==1){ //escudo
                sprite.setTextureRect(2*110,212,110,142);
                sprite2.setTextureRect(2*110,290,0,0);
            }
        }else{
            animationType=0;
            if(state==2){
                sprite2.setTextureRect(0,290,110,60);
            }else if(state==1){ //escudo
                sprite.setTextureRect(493,73,110,139);
                sprite2.setTextureRect(2*110,290,0,0);
            }
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
    //Escudo
    if(shell.getElapsedTimeAsSeconds()>=10.0f && state==1){
        this->setState(2);
    }
}

void Nave::update2(){
    //cambiamos animacion
    if(animation.getElapsedTimeAsSeconds()>=0.5f){
        if(animationType==0){
            animationType=1;
            if(state==2){
                sprite2.setTextureRect(110,290,110,65);
            }else if(state==1){ //escudo
                sprite.setTextureRect(2*110,212,110,142);
                sprite2.setTextureRect(2*110,290,0,0);
            }
        }else{
            animationType=0;
            if(state==2){
                sprite2.setTextureRect(0,290,110,60);
            }else if(state==1){ //escudo
                sprite.setTextureRect(493,73,110,139);
                sprite2.setTextureRect(2*110,290,0,0);
            }
        }
        animation.restart();
    }
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

int Nave::comprobarChoqueJefe(m2D::Sprite& jefazo){
    int quitarvida = 0;
    
    for(int i=0; i<vectorBalas.size(); i++){
        if(vectorBalas[i]->returnShape().getGlobalBounds().intersects(jefazo.getGlobalBounds())){
            quitarvida = quitarvida + 50;
            delete vectorBalas[i];
            vectorBalas.erase(vectorBalas.begin() + i);
        }
    }
    
    return quitarvida;
}

m2D::Sprite& Nave::returnShape(){
    return sprite;
}

m2D::Sprite& Nave::returnShape2(){
    return sprite2;
}

void Nave::danyo(int n){
     life = life - n;
     if(life<=0){
         Game::Instance()->setState(Missions::Instance());
     }
     Partida::Instance()->reduceLifeBar(life);
     
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
void Nave::moveUp(){
    if(position.getVectorY()>-11600)
        this->setPosition(position.getVectorX(),position.getVectorY()-velocity-5);
}
void Nave::moveDown(){
    if(position.getVectorY()<-10820)
        this->setPosition(position.getVectorX(),position.getVectorY()+velocity+5);
}
bool Nave::checkCollMete(Meteorito& meteorito){
        //ESTAMOS COLISIONANDO 100%
    bool cola=false;
    if(state != 1 ){
        if(sprite.getGlobalBounds().intersects(meteorito.returnShape().getGlobalBounds())||sprite2.getGlobalBounds().intersects(meteorito.returnShape().getGlobalBounds())&&meteorito.getColisioned()==false){ 
            //detectar lo de la vida
            cola=true;
            meteorito.setColisioned();
            life = life - 50;
            Partida::Instance()->reduceLifeBar(life);
            if(life<=0){
               Game::Instance()->setState(Missions::Instance());
            }
        }
    }
}

bool Nave::checkColl(Bala &bullet){//COLISIONES
        //ESTAMOS COLISIONANDO 100%
    bool cola=false;
    if(state != 1 ){
        if(sprite.getGlobalBounds().intersects(bullet.returnShape().getGlobalBounds())||sprite2.getGlobalBounds().intersects(bullet.returnShape().getGlobalBounds())){ 
            //detectar lo de la vida
            cola=true;
            life = life - 100;
            Partida::Instance()->reduceLifeBar(life);
            if(life<=0){
                Game::Instance()->setState(Missions::Instance());
            }
        }
    }
    
    return cola;
}

bool Nave::checkCollEsc(Escudo& escudo){
    //ESTAMOS COLISIONANDO 100%
    bool cola=false;
    if(sprite.getGlobalBounds().intersects(escudo.returnSprite().getGlobalBounds())||sprite2.getGlobalBounds().intersects(escudo.returnSprite().getGlobalBounds())){ 
        //detectar lo de la vida
        cola=true;
        this->setState(1);
        
    }
}

bool Nave::checkCollMaterial(Material& material){
    //ESTAMOS COLISIONANDO 100%
    bool cola=false;
    //int t=0;
    if(sprite.getGlobalBounds().intersects(material.returnSprite().getGlobalBounds())||sprite2.getGlobalBounds().intersects(material.returnSprite().getGlobalBounds())){ 
        //detectar lo de la vida
        cola=true;
        //sumar material
        if(material.getState() == 1){
            materials[material.getType()] ++;
            /*
            std::cout << "Materiales: " << std::endl;
            std::cout << "Carbon: " << materials[0]<< std::endl;
            std::cout << "Hierro: " << materials[1]<<std::endl;
            std::cout << "Titanio: " << materials[2]<< std::endl;
            std::cout << "Magnesio: " << materials[3]<< std::endl;
             */ 
        }
    }
}
bool Nave::checkCollMunition(Municion& municion){
    //ESTAMOS COLISIONANDO 100%
    bool cola=false;
    //int t=0;
    if(sprite.getGlobalBounds().intersects(municion.returnSprite().getGlobalBounds())||sprite2.getGlobalBounds().intersects(municion.returnSprite().getGlobalBounds())){ 
        //detectar lo de la vida
        cola=true;
        //sumar material
        if(municion.getState() == 1){
            //cambiar municion
            this->setMunition(municion.getType());
        }
    }
}

int Nave::getLife(){
    return life;
}


void Nave::golpea(Alien& alien){
    for(int i=0;i<vectorBalas.size();i++){
        if(vectorBalas[i]->returnShape().getGlobalBounds().intersects(alien.getShape().getGlobalBounds())){
            if(vectorBalas[i]->getTipo()==4){
                bomb_alive=false;
            }
            if(vectorBalas[i]->getTipo() != 3 && vectorBalas[i]->getTipo() != 6 ){
               delete vectorBalas[i];
                vectorBalas.erase(vectorBalas.begin()+i); 
            }
            alien.setState();
            Partida::Instance()->aumentScore();
        }
    }
}

void Nave::golpea2(Alien2& alien){
    for(int i=0;i<vectorBalas.size();i++){
        
        if(vectorBalas[i]->returnShape().getGlobalBounds().intersects(alien.getShape().getGlobalBounds())){
            if(vectorBalas[i]->getTipo()==4){
                bomb_alive=false;
            }
            if(vectorBalas[i]->getTipo() != 3 && vectorBalas[i]->getTipo() != 6 ){
               delete vectorBalas[i];
                vectorBalas.erase(vectorBalas.begin()+i); 
            }
            alien.setState();
            Partida::Instance()->aumentScore();
            
        }
    }
}

int* Nave::getMaterials(){
    return materials;
}

void Nave::setLife(int i){
    life=i;
}