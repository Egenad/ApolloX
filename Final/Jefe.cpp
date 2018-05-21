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
#include "StrategyC.h"
#include "Resultado.h"

Jefe::Jefe() {
    fase = 0;
    scoreup=false;
    maxLife = 0;
    life = 0;
    type = 0;
    nsprite = 0;
    strategy = NULL;
    deathAnimation = false;
    deathStart = false;
    alpha = 0;
}

void Jefe::setType(int n){
    type = n;
    switch(n){
        case 1:
            maxLife = 10000;
            life = 10000;
        break;
        case 2:
            maxLife = 30000;
            life = 30000;
        break;
        case 3:
            maxLife = 50000;
            life = 50000;
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
            sprite.setOrigin(240/2,300/2);
            sprite.setTextureRect(0,2*235,240,300);
        break;
        case 3:
            sprite.setOrigin(240/2,260/2);
            sprite.setTextureRect(10,220,240,260); 
        break;
    }
}

void Jefe::atacar(m2D::Texture& texture){
    strategy->execute(sprite, balas_jefe, texture, position);
}

void Jefe::draw(){
    for(int i=0; i<balas_jefe.size(); i++){
        balas_jefe[i]->draw();
    }
    strategy->draw(sprite,position);
    m2D::RenderWindow::Instance()->draw(sprite);
    if(exppCreado){
        m2D::RenderWindow::Instance()->draw(expp);
    }
}

void Jefe::danyo(int n){
    life -= n;
}

int Jefe::getvida(){
    return life;
}

int Jefe::getMaxLife(){
    return maxLife;
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
        case 2:{
            if(nsprite == 0 && change_sprite.getElapsedTimeAsSeconds() > 0.5){
                sprite.setOrigin(240/2,300/2);
                sprite.setTextureRect(0,2*235,240,300);
                change_sprite.restart();
                nsprite = 1;
            }
            else if(change_sprite.getElapsedTimeAsSeconds() > 0.5 && nsprite == 1){
                sprite.setOrigin(215/2,300/2);
                sprite.setTextureRect(2*273,2*218,215,300);
                nsprite = 0;
                change_sprite.restart();
            }
        }break;
        case 3:{
            if(nsprite == 0 && change_sprite.getElapsedTimeAsSeconds() > 0.5){
                nsprite++;
                sprite.setTextureRect(2*255,205,245,230);
                sprite.setOrigin(245/2,230/2);
                change_sprite.restart();
            }else if(nsprite == 1 && change_sprite.getElapsedTimeAsSeconds() > 0.5){
                nsprite++;
                sprite.setTextureRect(275,205,233,230);
                sprite.setOrigin(233/2,230/2);
                change_sprite.restart();
            }else if(nsprite == 2 && change_sprite.getElapsedTimeAsSeconds() > 0.5){
                nsprite = 0;
                sprite.setTextureRect(10,240,257,228); //primero
                sprite.setOrigin(257/2,228/2);
                change_sprite.restart();
            }
        }break;
    }
}
void Jefe::updateVida(m2D::Texture& texture){
    int quitarvida = Nave::Instance()->comprobarChoqueJefe(sprite);
    if(life > 0){    
        life = life - quitarvida;
        Partida::Instance()->reduceLifeBarBoss(life);
    }
    else{
        if(!deathAnimation){
            if(!deathStart){
                if(type == 1){
                    sprite.setTextureRect(260,2*220,285,260);
                    sprite.setOrigin(285/2, 260/2);
                }else if(type == 2){
                    sprite.setTextureRect(3*255,2*218,215,300);
                    sprite.setOrigin(215/2, 300/2);
                }else if(type == 3){
                    sprite.setTextureRect(3*262,205,233,230);
                    sprite.setOrigin(233/2, 230/2);
                }
                strategy = new StrategyC();
                deathStart = true;
                explosion.restart();
            }
            else{
                if(explosion.getElapsedTimeAsSeconds() > 3 && explosion.getElapsedTimeAsSeconds() < 4){
                    
                    if(!exppCreado){
                        expp.setTexture(texture);
                        expp.setPosition(sprite.getPositionX(), sprite.getPositionY());
                        expp.setTextureRect(620,0,70,70);
                        expp.scale(60,60);
                        expp.setOrigin(70/2, 70/2);
                        expp.setColorWithA(0,0,0,0);
                        exppCreado = true;
                        explosion2.restart();
                    }
                    else{
                        if(explosion2.getElapsedTimeAsSeconds() > 0.1){
                            if(alpha < 255)
                                alpha += 5;
                            expp.setColorWithA(0,0,0,alpha);
                        }
                    }
                }else if(explosion.getElapsedTimeAsSeconds() > 4){
                    deathAnimation = true;
                }
            }
        }
        else{
            Nave::Instance()->ismovingDown(false);
            Nave::Instance()->ismovingUp(false);
            Nave::Instance()->ismovingRight(false);
            Nave::Instance()->ismovingLeft(false);
            Missions::Instance()->setDesbloq();
            Nave::Instance()->saveLife(Nave::Instance()->getLife());
            Partida::Instance()->aumentScore(1400);
            Resultado::Instance()->setScore(Partida::Instance()->getScore());
            Game::Instance()->setState(Resultado::Instance());
            Partida::Instance()->stopMusica();
            Menu::Instance()->playMusica();
        }
    }
}

void Jefe::update(m2D::Texture& texture){
    switch(type){
        case 1:{
            if(life > 5000 && fase == 0){
                position.setVectorX(765);
                position.setVectorY(Nave::Instance()->getPosition().getVectorY() - 900);
                sprite.setPosition(position.getVectorX(), position.getVectorY());
                fase = 1;   
            }
            else if(fase == 1 && life <= 5000){
                this->setStrategy(new StrategyB());
                fase = 2;
            }
            break;
        }
        case 2:{
            if(life > 15000 && fase == 0){
                position.setVectorX(765);
                position.setVectorY(Nave::Instance()->getPosition().getVectorY() - 900);
                sprite.setPosition(position.getVectorX(), position.getVectorY());
                fase = 1;   
            }
            else if(fase == 1 && life <= 15000){
                this->setStrategy(new StrategyB2());
                fase = 2;
            }
            break;
        }
        case 3:{
            if(life > 25000 && fase == 0){
                position.setVectorX(765);
                position.setVectorY(Nave::Instance()->getPosition().getVectorY() - 900);
                sprite.setPosition(position.getVectorX(), position.getVectorY());
                fase = 1;   
            }
            else if(fase == 1 && life <= 25000){
                int randoming = rand() % 10 + 1;
                if(randoming > 5){
                    this->setStrategy(new StrategyB());
                }else{
                    this->setStrategy(new StrategyB2()); 
                }
                fase = 2;
            }
            break;
        }
    }
    this->updateVida(texture);
    if(life > 0){
        this->changeSprite();  
    }
    else if(scoreup==false){
        scoreup=true;
    }
    this->atacar(texture);
    
}

int Jefe::getFase(){
    return fase;
}

void Jefe::setFase(int n){
    fase = n;
}

void Jefe::setStrategy(Strategy *obj){
    strategy = obj;
}

int Jefe::getType(){
    return type;
}

void Jefe::setPos(float x, float y){
    sprite.setPosition(x, y);
}

