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
    if( n == 2 || n == 1 || n == 4){
        bala.setTextureRect(0,0,20,15);
        bala.setOrigin(20/2,15/2);
        bala.rotate(270);
    }else{
        if( n == 3){
            bala.setTextureRect(0,75,180,75);
            bala.setOrigin(180/2,75/2);
            bala.rotate(90);
        }
        else{
            bala.setTextureRect(0,75,140,75);
            bala.setOrigin(180/2,75/2);
            bala.rotate(90);
            bala.scale(4.2, 1);
        }
    }
    
   
    type = n;
    velocidad = velo;
}

void Bala::setRectBala(int a,int b ,int c,int d){
    bala.setTextureRect(a,b,c,d);
    bala.setOrigin(c/2, d/2);
}

void Bala::setColor(int r, int g, int b){
    bala.setColor(r,g,b);
}

Bala::Bala(m2D::Texture &textura, int n, float angul, float velo) {
    bala.setTexture(textura);
    bala.setTextureRect(0,0,20,15);
    bala.setOrigin(20/2,15/2);
    if(angul==60){
        bala.rotate(angul+230);
    }
    else{
        if(angul >= 100){
            if(angul == 100){
                bala.rotate(angul+150); 
            }else{
                bala.rotate(angul+100); 
            }
        }
        else{
            bala.rotate(angul+200);
        }
    }
    
    type = n;
    angulo = angul;
    velocidad = velo;
}

Bala::Bala(const Bala& orig) {
}

Bala::~Bala() {
}

void Bala::fire(int speed){
    position.setVectorX(position.getVectorX());
    position.setVectorY(position.getVectorY()+speed);
    bala.setPosition(position.getVectorX(),position.getVectorY());
}

void Bala::disparar_canyon(m2D::Vector2f& shiposition, int n){
    if(n == 3){
        position.setVectorX(shiposition.getVectorX());
        position.setVectorY(shiposition.getVectorY() - 120);
        bala.setPosition(position.getVectorX(), position.getVectorY());
    }
    else{
        position.setVectorX(shiposition.getVectorX());
        position.setVectorY(shiposition.getVectorY() - 420);
        bala.setPosition(position.getVectorX(), position.getVectorY());
    }
}

void Bala::escalarCanyon(){
    bala.scale(1,0.5);
}

void Bala::setAngulo(float n){
    angulo = n;
}

void Bala::disparar(){
    position.setVectorX(position.getVectorX());
    position.setVectorY(position.getVectorY()-velocidad);
    bala.setPosition(position.getVectorX(),position.getVectorY());
}

void Bala::disparar_bomba(int n){
    switch(n){
        case 1:
            position.setVectorX(position.getVectorX());
            position.setVectorY(position.getVectorY()-velocidad);
            bala.setPosition(position.getVectorX(),position.getVectorY());
        break;
        case 2:
            bala.setTextureRect(620,0,70,70);
            bala.setOrigin(70/2, 70/2);
        break;
    }
}

void Bala::moverbala(int contador){
    switch(contador){
        case 0:
            position.setVectorX(position.getVectorX() + 7);
            position.setVectorY(position.getVectorY());
            bala.setPosition(position.getVectorX(),position.getVectorY());
            break;
        case 1:
            position.setVectorX(position.getVectorX() + 5);
            position.setVectorY(position.getVectorY());
            bala.setPosition(position.getVectorX(),position.getVectorY());
            break;
        case 2:
            position.setVectorX(position.getVectorX() + 1);
            position.setVectorY(position.getVectorY());
            bala.setPosition(position.getVectorX(),position.getVectorY());
            break;
        case 3:
            position.setVectorX(position.getVectorX() + 1);
            position.setVectorY(position.getVectorY());
            bala.setPosition(position.getVectorX(),position.getVectorY());
            break;
        case 4:
            position.setVectorX(position.getVectorX());
            position.setVectorY(position.getVectorY());
            bala.setPosition(position.getVectorX(),position.getVectorY());
            break;
    }
    
}

void Bala::disparar_angulo(int tipo_npc){
    switch(tipo_npc){
        case 1:
            position.setVectorX(position.getVectorX() + cos(degree2radian*angulo)*velocidad);
            position.setVectorY(position.getVectorY() - velocidad*sin(degree2radian*angulo));
            bala.setPosition(position.getVectorX(),position.getVectorY());
            break;
        case 2:
            position.setVectorX(position.getVectorX() + cos(degree2radian*angulo)*-velocidad);
            position.setVectorY(position.getVectorY() + velocidad*sin(degree2radian*angulo));
            bala.setPosition(position.getVectorX(),position.getVectorY());
            break;
    }   
}

void Bala::setPos(m2D::Vector2f pos){
    bala.setPosition(pos.getVectorX(),pos.getVectorY());
    position.setVectorX(pos.getVectorX());
    position.setVectorY(pos.getVectorY());
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

int Bala::getX(){
    return bala.getPositionX();
}

int Bala::getY(){
    return bala.getPositionY();
}
void Bala::rotarBala(int n){
    bala.rotate(n);
}
void Bala::escalarBala(float x, float y){
    bala.scale(x,y);
}