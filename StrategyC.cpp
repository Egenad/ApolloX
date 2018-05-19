/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyC.cpp
 * Author: angel
 * 
 * Created on 16 de mayo de 2018, 18:42
 */

#include "StrategyC.h"

StrategyC::StrategyC() {
    state = false;
}

void StrategyC::execute(m2D::Sprite& sprite, std::vector<Bala*>& balas_jefe, m2D::Texture& texture, m2D::Vector2f& position){
    if(!balas_jefe.empty()){
        for(int i=0; i<balas_jefe.size(); i++){
            delete balas_jefe[i];
            balas_jefe.erase(balas_jefe.begin() + i);
        }
    }
    if(temporizador.getElapsedTimeAsSeconds() > 0.1){
        if(!state){
            state = true;
            sprite.move(3,0);
        }
        else{
            state = false;
            sprite.move(-3,0);
        }
        temporizador.restart();
    }
}

void StrategyC::draw(m2D::Sprite& sprite,m2D::Vector2f& position){
}