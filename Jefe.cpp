/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jefe.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:34
 */

#include "Jefe.h"
#include "Nave.h"
#include "Partida.h"
#include "Game.h"
#include "Missions.h"

Jefe::Jefe() {
    fase = 0;
    maxLife = 0;
    life = 0;
    type = 0;
    nsprite = 0;
    strategy = NULL;
}

void Jefe::setType(int n){
    type = n;
    switch(n){
        case 1:
            maxLife = 10000;
            life = 10000;
        break;
        case 2:
            maxLife = 50000;
            life = 50000;
        break;
        case 3:
            maxLife = 100000;
            life = 100000;
        break;
    }
}

Jefe::Jefe(const Jefe& orig) {
}

Jefe::~Jefe() {
}

void Jefe::setTexture(m2D::Texture& textura){
    sprite.setTexture(textura);
    switch(type){
        case 1:
            sprite.setOrigin(285/2,210/2);
            sprite.setTextureRect(0,30,285,210);
        break;
        case 2:
            
        break;
        case 3:
            
        break;
    }
}

void Jefe::atacar(m2D::Texture& texture){
    strategy->execute(sprite, balas_jefe, texture);
}

void Jefe::draw(){
    for(int i=0; i<balas_jefe.size(); i++){
        balas_jefe[i]->draw();
    }
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Jefe::danyo(int n){
    life -= n;
}

int Jefe::getvida(){
    return life;
}

void Jefe::changeSprite(){
    switch(type){
        case 1:{
            if(nsprite == 0 && change_sprite.getElapsedTimeAsSeconds() > 0.5){
                nsprite++;
                sprite.setTextureRect(455,0,285,205);
                change_sprite.restart();
            }else if(nsprite == 1 && change_sprite.getElapsedTimeAsSeconds() > 0.5){
                nsprite++;
                sprite.setTextureRect(740,0,285,205);
                change_sprite.restart();
            }else if(nsprite == 2 && change_sprite.getElapsedTimeAsSeconds() > 0.5){
                nsprite = 0;
                sprite.setTextureRect(0,30,285,210);
                change_sprite.restart();
            }
        }break;
    }
}
void Jefe::updateVida(){
    int quitarvida = Nave::Instance()->comprobarChoqueJefe(sprite);
    life = life - quitarvida;
    Partida::Instance()->reduceLifeBarBoss(life);
    if(life<=0){
        Missions::Instance()->setDesbloq();
        Game::Instance()->setState(Missions::Instance());
        
    }
}

void Jefe::update(m2D::Texture& texture){
    switch(type){
        case 1:{
            if(life > 5000 && fase == 0){
                sprite.setPosition(765, Nave::Instance()->getPosition().getVectorY() - 900);
                fase = 1;   
            }
            else if(fase == 1 && life <= 5000){
                this->setStrategy(new StrategyB());
                fase = 2;
            }
        }
    }
    this->updateVida();
    this->changeSprite();
    this->atacar(texture);
}

int Jefe::getFase(){
    return fase;
}

void Jefe::setFase(int n){
    fase = n;
}

void Jefe::setStrategy(Strategy *obj){
    if(strategy != NULL){
        delete strategy;
    }
    strategy = obj;
}

int Jefe::getType(){
    return type;
}

void Jefe::setPos(float x, float y){
    sprite.setPosition(x, y);
}

