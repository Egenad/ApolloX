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
#include <SFML/Graphics.hpp>
#include "Nave.h"
Nave::Nave (){
    coord_x=0;
    coord_y=0;
    estado=2;
    
}
Nave::Nave (int x, int y, sf::Sprite s ){
        coord_x=x;
        coord_y=y;
        estado=2;
        
        sprite = s;
        sprite.setPosition(x, y);
    }
void Nave::set_sprite(sf::Sprite s){
    sprite = s;
    sprite.setPosition(coord_x, coord_y);
}
void Nave::set_estado(int d){
    estado=d;
}
int Nave::get_posx(){
    return coord_x;
}
int Nave::get_posy(){
    return coord_y;
}
sf::Sprite Nave::get_sprite(){
    return sprite;
}
int Nave::get_estado(){
    return estado;
}
void Nave::move(int x, int y){
    coord_x=x;
    coord_y=y;
    
    sprite.setPosition(x,y);
}

Nave::Nave(const Nave& orig) {
}

Nave::~Nave() {
}

