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
#include <iostream>



Alien::Alien() {
        type=(rand()%3)+1; //tipo de movimiento
        //sprite.setTexture(textura);
       // sprite.setTextureRect(280,70, 100, 110);
       // position.setVectorX(rand()%(600-100));
       // position.setVectorY(-50);
    if(type==1){
        grados=90.0f;
        std::cout<< "soy 1" <<std::endl;
    }
    else if(type==2){
        grados=180.0f;
        std::cout<< "soy 2" <<std::endl;
        
    }
    else if(type==3){
        grados=135.0f;
        std::cout<< "soy 3" <<std::endl;
    }
        //sprite.setPosition(position.getVectorX(),position.getVectorY());
    

}

Alien::Alien(const Alien& orig) {
}

Alien::~Alien() {
}

void Alien::setPos(int x, int y){
    sprite.setPosition(x,y);
}
 int Alien::getX(){
     return sprite.getPositionX();
}
 int Alien::getY(){
     return sprite.getPositionY();
        
}
void Alien::draw(){
    m2D::RenderWindow::Instance()->draw(sprite);//para dibujar el sprite (SINGLETON)
}

m2D::Sprite& Alien::getShape(){
    return sprite;
}

m2D::Vector2f Alien::getPos(){
    return position;
}

void Alien::dispara(m2D::Texture &textura){
    if(dis.getElapsedTimeAsSeconds()>1){
        Bala *newBullet= new Bala(textura);//TAMAÑO DE BALA
        newBullet->setPos(m2D::Vector2f(sprite.getPositionX()+50,sprite.getPositionY()+20));//POSICION DE LA BALA
        balas.push_back(newBullet);//VECTOR DE BALAS
        dis.restart();
    }

}

void Alien::dibujaBalas(){
        for(int n=0; n< balas.size(); n++){//DIBUJAMOS LAS BALAS 
            m2D::RenderWindow::Instance()->draw(balas[n]->returnShape());//dibujamos las balas, le pasamos el sprite de la bala al SINGLETON de WINDOW
            balas[n]->fire(6);//LE PASAMOS LA VELOCIDAD DE DISPARO
        }
        
        for(int k=0;k< balas.size();k++){
            bool cola=false;
            //cola=Nave::Instance.checkColl(*balas[k]); //LE PASAMOS LA BALA CON LA QUE COLOSIONA
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

void Alien::Update(){ //UPDATE DE ALIEN
    //dispara(texture);
    //dibujaBalas();
    sprite.move(sin(grados),1);
    grados=grados+0.006f;
}

void Alien::setTexture(m2D::Texture& texture){
        sprite.setTexture(texture);
        sprite.setTextureRect(280,70, 100, 110);
}

