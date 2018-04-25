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
#include <iostream>
#include <math.h>
const float degree2radian = (3.14159f / 180.0f);

Bala::Bala(m2D::Texture &textura) {//CONSTRUCTOR
    bala.setTexture(textura);
    bala.setTextureRect(25,0,20,15);
    bala.rotate(90);
    type=1;
}

Bala::Bala(m2D::Texture &textura, int n, float velo) {
    bala.setTexture(textura);
    bala.setTextureRect(0,0,20,15);
    bala.setOrigin(20/2,15/2);
    bala.rotate(270);
    type = n;
    velocidad = velo;
}

Bala::Bala(m2D::Texture &textura, int n, float angul, float velo) {
    bala.setTexture(textura);
    bala.setTextureRect(25,0,20,15);
    type = n;
    angulo = angul;
    velocidad = velo;
}

Bala::Bala(const Bala& orig) {
}

Bala::~Bala() {
}

void Bala::fire(int speed){
    bala.move(0,speed); //MOVEMOS LA BALA EN Y negativa (hacia abajo)
}

void Bala::disparar_canyon(m2D::Vector2f shiposition){
    bala.move(shiposition.getVectorX(), shiposition.getVectorY());
}

void Bala::escalarCanyon(){
    bala.scale(0.5,1);
}

void Bala::setAngulo(float n){
    angulo = n;
}

void Bala::disparar(){
    bala.move(0,-velocidad);
}

void Bala::disparar_bomba(int n){
    switch(n){
        case 1:
            bala.move(0, -velocidad);
        break;
        case 2:
            bala.scale(8, 4);
            bala.move(-20,0);
        break;
    }
}

void Bala::moverbala(int contador){
    switch(contador){
        case 0:
            bala.move(7, 0);
            break;
        case 1:
            bala.move(5, 0);
            break;
        case 2:
            bala.move(1, 0);
            break;
        case 3:
            bala.move(1, 0);
            break;
        case 4:
            bala.move(0, 0);
            break;
    }
    
}

void Bala::disparar_angulo(int tipo_npc){
    switch(tipo_npc){
        case 1:
            bala.move(cos(degree2radian*angulo)*velocidad,-velocidad*sin(degree2radian*angulo));
            break;
        case 2:
            bala.move(cos(degree2radian*angulo)*-velocidad,velocidad*sin(degree2radian*angulo));
            break;
    }  
}

void Bala::setPos(m2D::Vector2f pos){
    bala.setPosition(pos.getVectorX(),pos.getVectorY());
}

void Bala::draw(){
    m2D::RenderWindow::Instance()->draw(bala);
}

m2D::Sprite& Bala::returnShape(){
    return bala;
}

int Bala::getTipo(){
    return type;
}
