/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alien.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:34
 */

#include "Alien.h"
#include "Nave.h"
#include "Game.h"
#include "Partida.h"


Alien::Alien() {
    type=(rand()%3)+1; //tipo de movimiento
    state=0;
    animationState=0;
        //sprite.setTexture(textura);
       // sprite.setTextureRect(280,70, 100, 110);
       // position.setVectorX(rand()%(600-100));
       // position.setVectorY(-50);
    life=100;
    if(type==1){
        grados=90.0f;
    }
    else if(type==2){
        grados=180.0f;
    }
    else if(type==3){
        grados=135.0f;
    }
        //sprite.setPosition(position.getVectorX(),position.getVectorY());
    

}

Alien::Alien(const Alien& orig) {
}

Alien::~Alien() {
}

void Alien::setPos(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
}
 int Alien::getX(){
     return sprite.getPositionX();
}
 int Alien::getY(){
     return sprite.getPositionY();
        
}
void Alien::draw(){
    if(state==0){
        
        if(Game::Instance()->getP()<1){
            float posY=this->getPos().getVectorY()*(1-Game::Instance()->getP())+(this->getPos().getVectorY()+2)*Game::Instance()->getP();
            float posX=this->getPos().getVectorX()*(1-Game::Instance()->getP())+(this->getPos().getVectorX()+(sin(grados)*10))*Game::Instance()->getP();
            sprite.setPosition(posX,posY);
        }
        
        m2D::RenderWindow::Instance()->draw(sprite); //para dibujar el sprite (SINGLETON)
    }
    
}

m2D::Sprite& Alien::getShape(){
    return sprite;
}

m2D::Vector2f& Alien::getPos(){
    return position;
}

void Alien::dispara(m2D::Texture &textura){
    if(dis.getElapsedTimeAsSeconds()>1){
        Bala *newBullet= new Bala(textura, 6);//TAMAÑO DE BALA
        newBullet->setPos(m2D::Vector2f(sprite.getPositionX()+15,sprite.getPositionY()+20));//POSICION DE LA BALA
        balas.push_back(newBullet);//VECTOR DE BALAS
        dis.restart();
    }

}

void Alien::dibujaBalas(){
        for(int n=0; n< balas.size(); n++){//DIBUJAMOS LAS BALAS 
            m2D::RenderWindow::Instance()->draw(balas[n]->returnShape());//dibujamos las balas, le pasamos el sprite de la bala al SINGLETON de WINDOW
            balas[n]->disparar();//LE PASAMOS LA VELOCIDAD DE DISPARO
        }
        
        for(int k=0;k< balas.size();k++){
            bool cola=false;
            cola=Nave::Instance()->checkColl(*balas[k]); //LE PASAMOS LA BALA CON LA QUE COLOSIONA
            if(cola){
                delete balas[k];
                balas.erase(balas.begin()+k);
                
            }
        }
}

void Alien::move(float grados){
    sprite.move(sin(grados),1);
}

int Alien::getTipo(){
    return type;
}

int Alien::getStateAlien(){
    return state;
}

void Alien::Update(){ //UPDATE DE ALIEN
    if(state == 0){
        this->animation();
        
        grados=grados+0.3f;
        //updateamos la pos
        this->setPos(this->getPos().getVectorX()+(sin(grados)*10),this->getPos().getVectorY()+2);
        sprite.setPosition(position.getVectorX(),position.getVectorY());
    }
}

void Alien::animation(){
    if(animationClock.getElapsedTimeAsSeconds()>0.4f){
        if(animationState==0){
            animationState=1;
            sprite.setTextureRect(385,70, 100, 110);
        }else{
            animationState=0;
            sprite.setTextureRect(280,70, 100, 110);
        }
        animationClock.restart();
    }
    
}

void Alien::setTexture(m2D::Texture& texture){
    sprite.setTexture(texture);
    sprite.setTextureRect(280,70, 100, 110);
    sprite.setOrigin(100/2,110/2);
    sprite.setPosition(position.getVectorX(),position.getVectorY());
}

void Alien::quitarVida(int a){
    //detectar lo de la vida
    life = life - a;
    if(life<=0){
        this->setState();
        Partida::Instance()->aumentScore(400);
    }
}

int Alien::getVida(){
    return life;
}

void Alien::setState(){
    state=1; //muerto
}
