/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Material.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:35
 */
#include "Material.h"
#include <iostream>

Material::Material() {
    
    this->setCoord(0,0);
}

Material::Material(const Material& orig) {
}

Material::~Material() {
}
void Material::setTexture(m2D::Texture& texture){
    
    sprite.setTexture(texture);
    if(type==1){
        sprite.setTextureRect(49, 0, 29, 29);
    }else if(type==2){
        sprite.setTextureRect(79, 0, 29, 29);
    }else if(type==3){
        sprite.setTextureRect(139, 0, 29, 29);
    }else{
        sprite.setTextureRect(170, 0, 29, 29);
    }
    
    sprite.setOrigin(29/2,29/2);
    sprite.setPosition(position.getVectorX(),position.getVectorY());
    
}

void Material::setCoord(int x, int y){
    position.setVectorX(x);
    position.setVectorY(y);
}
void Material::setType(int x){
    type=x;
}
m2D::Sprite& Material::returnSprite(){
    return sprite;
}

void Material::move(){

    sprite.move(0,5);

}

void Material::draw(){
    m2D::RenderWindow::Instance()->draw(sprite);
}

void Material::update(){
    move();
}

m2D::Vector2f& Material::getCoord(){
    return position;
}

int Material::getType(){
    return type;
}

