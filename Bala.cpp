/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bala.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:32
 */

#include "Bala.h"

Bala::Bala(m2D::Texture &textura) {//CONSTRUCTOR
    bala.setTexture(textura);
    bala.setTextureRect(25,0,20,15);
    bala.rotate(90);
    type=1;
}

Bala::Bala(const Bala& orig) {
}

Bala::~Bala() {
}


void Bala::fire(int speed){
    bala.move(0,speed); //MOVEMOS LA BALA EN Y negativa (hacia abajo)
}

void Bala::setPos(m2D::Vector2f pos){
    bala.setPosition(pos.getVectorX(),pos.getVectorY());
}
void Bala::draw(m2D::RenderWindow &window){
    window.draw(bala);
}

m2D::Sprite Bala::returnShape(){
    return bala;
}

int Bala::getTipo(){
    return type;
}

