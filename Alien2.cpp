/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * 
 * File:   Alien2.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:34
 */

#include "Alien2.h"
#include "Nave.h"
#include "Game.h"

Alien2::Alien2() {
    type=(rand()%3)+1; //tipo de movimiento
    state=0;
    life=1;
    stop=false;
    animationState=0;
    estado=0;
    restart=false;
    restart2=false;
}

Alien2::Alien2(const Alien2& orig) {
}

Alien2::~Alien2() {
}

void Alien2::setPos(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
}
 int Alien2::getX(){
     return sprite.getPositionX();
}
 int Alien2::getY(){
     return sprite.getPositionY();
        
}
void Alien2::draw(){
    if(state==0){
        if(restart2==false){
            co.restart();
            restart2=true;
        }
        m2D::RenderWindow::Instance()->draw(sprite); //para dibujar el sprite (SINGLETON)
    }
    
}

m2D::Sprite& Alien2::getShape(){
    return sprite;
}

m2D::Vector2f& Alien2::getPos(){
    return position;
}

void Alien2::dispara(m2D::Texture &textura){
    if(stop==true && state==0){
        if(dis.getElapsedTimeAsSeconds()>1){
            Bala *newBullet= new Bala(textura);//TAMAÑO DE BALA
            newBullet->setPos(m2D::Vector2f(sprite.getPositionX()+15,sprite.getPositionY()+20));//POSICION DE LA BALA
            balas.push_back(newBullet);//VECTOR DE BALAS
            dis.restart();
        }
    }

}

void Alien2::dibujaBalas(){
        for(int n=0; n< balas.size(); n++){//DIBUJAMOS LAS BALAS 
            m2D::RenderWindow::Instance()->draw(balas[n]->returnShape());//dibujamos las balas, le pasamos el sprite de la bala al SINGLETON de WINDOW
            balas[n]->fire(6);//LE PASAMOS LA VELOCIDAD DE DISPARO
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

int Alien2::getTipo(){
    return type;
}

void Alien2::Update(){ //UPDATE DE ALIEN
    if(state==0){
        this->animation();
        if(Nave::Instance()->getPosition().getVectorY()-400<sprite.getPositionY()){
            sprite.move(0,-4);  //stop
            stop=true;
            if(co.getElapsedTimeAsSeconds()>3 && estado==0){
                estado=1;
                if(restart==false){
                    co.restart();
                    restart=true;
                }
            }
            if(estado==1){
                if(sprite.getPositionX()<=600){
                    sprite.move(-6,0); // se va fuera de la pantalla
                }
                else{
                    sprite.move(6,0);
                }

            }
                if(Nave::Instance()->getPosition().getVectorX()<sprite.getPositionX() ){
                    sprite.move(-4,0);      //movemos izquierda
                }
                if(Nave::Instance()->getPosition().getVectorX()>sprite.getPositionX() ){
                    sprite.move(4,0);    //movemos derecha
                }
        }
        else{
            if(Nave::Instance()->getPosition().getVectorX()<sprite.getPositionX() && stop==false ){
                sprite.move(-2,1);      //movemos izquierda
            }
            if(Nave::Instance()->getPosition().getVectorX()>sprite.getPositionX() && stop ==false){
                sprite.move(2,1);    //movemos derecha
            }
        }
        //updateamos la pos
        this->setPos(sprite.getPositionX(),sprite.getPositionY());
        if(sprite.getPositionX()<380 || sprite.getPositionX()>1200){
            this->setState();
        }
    }
}

void Alien2::animation(){
    if(animationClock.getElapsedTimeAsSeconds()>0.4f){
        if(animationState==0){
            animationState=1;
            sprite.setTextureRect(835,0, 87, 70);
            sprite.setOrigin(87/5,70/2);
        }else{
            animationState=0;
            sprite.setTextureRect(370,0, 87, 50);
            sprite.setOrigin(63/2,50/2);
        }
        animationClock.restart();
    }
}

void Alien2::setTexture(m2D::Texture& texture){
    sprite.setTexture(texture);
    sprite.setTextureRect(370,0, 87, 50);
    sprite.setOrigin(63/2,50/2);
    sprite.setPosition(position.getVectorX(),position.getVectorY());
}

void Alien2::quitarVida(){
    //detectar lo de la vida
    life = life - 50;
    if(life<=0){
        sprite.setPosition(10000,10000);
    }
}

int Alien2::getVida(){
    return life;
}

void Alien2::setState(){
    state=1; //muerto
}

int Alien2::getStateAlien(){
    return state;
}