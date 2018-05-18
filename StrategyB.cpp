/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyB.cpp
 * Author: angel
 * 
 * Created on 22 de abril de 2018, 11:07
 */

#include "StrategyB.h"
#include "Clock.h"
#include "Nave.h"
#include <math.h>
#include <iostream>

#define PI 3.14159265

StrategyB::StrategyB(){
    reset_fase = true;
    oleada = false;
    creados = false;
    movido = false;
    lastmove = 0;
    movimiento_terminado = true;
    namber = 1;
    comp1 = false;
    comp2 = false;
    comp3 = false;
    comp4 = false;
}

void StrategyB::execute(m2D::Sprite& sprite, std::vector<Bala*>& balas_jefe, m2D::Texture& texture){
    if(reset_fase == true){//paso de la fase A a la B
        if(sprite.getPositionX() < 765){//se encuentra por la izquierda
            sprite.move(1,0);
        }
        else{
            if(sprite.getPositionX() > 765){//se encuentra por la derecha
                 sprite.move(-1,0);
            }
        }
        if(!balas_jefe.empty()){
            for(int i=0; i<balas_jefe.size(); i++){ 
                delete balas_jefe[i];
                balas_jefe.erase(balas_jefe.begin() + i);
            } 
        }
        if(sprite.getPositionX() == 765 && balas_jefe.size() == 0){
            reset_fase = false;
            timer.restart();
            temporizador.restart();
            segundas_balas.restart();
        }
    }else{
        if(temporizador.getElapsedTimeAsSeconds() >= 3){
            int random = rand() % 10 + 1;
            if(!movido){ //me muevo del centro a un lado
                if(movimiento_terminado){
                    if(random > 5){
                        //derecha
                        lastmove = 1;
                    }
                    else{
                        //izquierda  
                        lastmove = 2;
                    }
                    movimiento_terminado = false;
                }
                else{
                    //en movimiento
                    if(lastmove == 1){
                        if(sprite.getPositionX() < 1100){
                            sprite.move(1,0);
                        }
                        else{
                            movimiento_terminado = true;
                            temporizador.restart();
                            movido = true;
                        }
                    }
                    else{
                        if(sprite.getPositionX() > 500){
                            sprite.move(-1,0);
                        }
                        else{
                            movimiento_terminado = true;
                            temporizador.restart();
                            movido = true;
                        }
                    }
                }
            }else{//me muevo de un lado al centro
                if(lastmove == 1){
                    if(sprite.getPositionX() > 765){
                        sprite.move(-1,0);
                    }
                    else{
                        movido = false;
                        temporizador.restart();
                    }
                }
                else{
                    if(lastmove == 2){
                        if(sprite.getPositionX() < 765){
                            sprite.move(1,0);
                        }
                        else{
                            movido = false;
                            temporizador.restart();
                        }
                    }
                }
            }
        }        
        int angul = 60;
        if(!oleada && movimiento_terminado){
            if(creados == false){
                for(int i=0; i<8; i++){
                    Bala * bullet = new Bala(texture, 2, angul, 3.0f);
                    bullet->setColor(9, 166, 82);
                    bullet->setPos(m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30));
                    bullet->setRectBala(620,0,70,70);
                    bullet->escalarBala(0.5,0.5);
                    balas_jefe.push_back(bullet);
                    angul = angul + 45;
                    if(i == 7){
                        timer.restart();
                        creados = true;
                    }
                }
            }
        }
        if(timer.getElapsedTimeAsSeconds() < 0.5){
            for(int i=0; i<balas_jefe.size(); i++){
                if(balas_jefe[i]->getTipo() == 2){
                    balas_jefe[i]->disparar_angulo(2);
                }
            }
        }
        else{
            oleada = true;
        }
        if(terceras_balas.getElapsedTimeAsSeconds() > 2){
            float angul = 60;
            for(int i=0; i<4; i++){
                Bala * bullet = new Bala(texture, 3, angul, 3.0f);
                bullet->rotarBala(180);
                bullet->setPos(m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30));
                balas_jefe.push_back(bullet);
                angul = angul + 20;
            }
            terceras_balas.restart();
        }
        if(segundas_balas.getElapsedTimeAsSeconds() > 2 && namber < 5){
            float distancia2 = Nave::Instance()->getPosition().getVectorY() - sprite.getPositionY();
            float distancia = sqrt(pow((Nave::Instance()->getPosition().getVectorX()-sprite.getPositionX()),2)+pow((Nave::Instance()->getPosition().getVectorY()-sprite.getPositionY()),2));
            float result = asin(distancia2/distancia) * 180.0 / PI;
           
            if(Nave::Instance()->getPosition().getVectorX() > sprite.getPositionX()){
                result = (90-result) + 90 ;
            }
            
            for(int i=0; i<4; i++){
                Bala * bullet = new Bala(texture, 1, result, 4.0f);
                bullet->setColor(96, 30, 120);
                bullet->setPos(m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30));
                bullet->setRectBala(620,0,70,70);
                bullet->escalarBala(0.5,0.5);
                balas_jefe.push_back(bullet);
                namber++;
            }
        }
       
        if(oleada == true){
            for(int i=0; i<balas_jefe.size(); i++){
                if(balas_jefe[i]->getTipo() == 2){
                    float distancia2 = Nave::Instance()->getPosition().getVectorY() - sprite.getPositionY();
                    float distancia = sqrt(pow((Nave::Instance()->getPosition().getVectorX()-sprite.getPositionX()),2)+pow((Nave::Instance()->getPosition().getVectorY()-sprite.getPositionY()),2));
                    float result = asin(distancia2/distancia) * 180.0 / PI;
                    
                    if(Nave::Instance()->getPosition().getVectorX() > sprite.getPositionX()){
                        result = (90-result) + 90 ;
                    }
                  
                    //std::cout << "mov" << std::endl;
                    balas_jefe[i]->setAngulo(result);
                    balas_jefe[i]->disparar_angulo(2);
                    if(balas_jefe[i]->getX() < 340 || balas_jefe[i]->getX() > 1190 || -10220 < balas_jefe[i]->getY()){
                        delete balas_jefe[i];
                        balas_jefe.erase(balas_jefe.begin() + i);
                        // std::cout << "Eliminado" << std::endl;
                    }
                    if(balas_jefe[i]->returnShape().getGlobalBounds().intersects(Nave::Instance()->returnShape().getGlobalBounds()) || balas_jefe[i]->returnShape().getGlobalBounds().intersects(Nave::Instance()->returnShape2().getGlobalBounds())){
                        Nave::Instance()->danyo(50);
                        delete balas_jefe[i];
                        balas_jefe.erase(balas_jefe.begin() + i);
                    }
                }
            }
        }
        int numero_rojo = 1;
        for(int i=0; i<balas_jefe.size(); i++){
            if(balas_jefe[i]->getTipo() == 1){            
                switch(numero_rojo){
                    case 1:
                        if(balas_jefe[i]->getY() < sprite.getPositionY() + 150){
                            balas_jefe[i]->disparar_angulo(2);
                        }
                        else{
                            if(segundas_balas.getElapsedTimeAsSeconds() > 6){
                                if(!comp1){
                                    float r = rand() % 180 + 1;
                                    balas_jefe[i]->setAngulo(r);
                                    comp1 = true;
                                }
                                balas_jefe[i]->disparar_angulo(2);
                            }
                        }
                        break;
                    case 2:
                        if(balas_jefe[i]->getY() < sprite.getPositionY() + 230){
                            balas_jefe[i]->disparar_angulo(2);
                        }
                        else{
                            if(segundas_balas.getElapsedTimeAsSeconds() > 6){
                                if(!comp2){
                                    float r = rand() % 180 + 1;
                                    balas_jefe[i]->setAngulo(r);
                                    comp2 = true;
                                }
                                balas_jefe[i]->disparar_angulo(2);
                            }
                        }
                        break;
                    case 3:
                        if(balas_jefe[i]->getY() < sprite.getPositionY() + 310){
                            balas_jefe[i]->disparar_angulo(2);
                        }
                        else{
                            if(segundas_balas.getElapsedTimeAsSeconds() > 6){
                                if(!comp3){
                                    float r = rand() % 180 + 1;
                                    balas_jefe[i]->setAngulo(r);
                                    comp3 = true;
                                }
                                balas_jefe[i]->disparar_angulo(2);
                            }
                        }
                        break;
                    case 4:
                        if(balas_jefe[i]->getY() < sprite.getPositionY() + 390){
                            balas_jefe[i]->disparar_angulo(2);
                        }
                        else{
                            if(segundas_balas.getElapsedTimeAsSeconds() > 6){
                                if(!comp4){
                                    float r = rand() % 180 + 1;
                                    balas_jefe[i]->setAngulo(r);
                                    comp4 = true;
                                }
                                balas_jefe[i]->disparar_angulo(2);
                            }
                        }
                        break;
                }
                numero_rojo++;
                if(-10220 < balas_jefe[i]->getY() || balas_jefe[i]->getX() < 340 || balas_jefe[i]->getX() > 1190){
                    delete balas_jefe[i];
                    balas_jefe.erase(balas_jefe.begin() + i);
                    // std::cout << "Eliminado" << std::endl;
                }
                if(balas_jefe[i]->returnShape().getGlobalBounds().intersects(Nave::Instance()->returnShape().getGlobalBounds()) || balas_jefe[i]->returnShape().getGlobalBounds().intersects(Nave::Instance()->returnShape2().getGlobalBounds())){
                    Nave::Instance()->danyo(50);
                    delete balas_jefe[i];
                    balas_jefe.erase(balas_jefe.begin() + i);
                }
            }
            else{
                if(balas_jefe[i]->getTipo() == 3){
                    balas_jefe[i]->disparar_angulo(2);
                    if(-10220 < balas_jefe[i]->getY() || balas_jefe[i]->getX() < 340 || balas_jefe[i]->getX() > 1190){
                        delete balas_jefe[i];
                        balas_jefe.erase(balas_jefe.begin() + i);
                        // std::cout << "Eliminado" << std::endl;
                    }
                    if(balas_jefe[i]->returnShape().getGlobalBounds().intersects(Nave::Instance()->returnShape().getGlobalBounds()) || balas_jefe[i]->returnShape().getGlobalBounds().intersects(Nave::Instance()->returnShape2().getGlobalBounds())){
                        Nave::Instance()->danyo(50);
                        delete balas_jefe[i];
                        balas_jefe.erase(balas_jefe.begin() + i);
                    }
                }
            }
        }
        
        bool _comp = true;
        bool _comp2 = true;
        for(int i=0; i<balas_jefe.size(); i++){
            if(balas_jefe[i]->getTipo() == 2){
                _comp = false;
            }
            else{
                if(balas_jefe[i]->getTipo() == 1){
                    _comp2 = false;
                }
            }
        }
        if(_comp){
            oleada = false;
            creados = false;
            timer.restart();
        }
        if(_comp2 && segundas_balas.getElapsedTimeAsSeconds() > 2){
            segundas_balas.restart();
            namber = 1;
            comp1 = false;
            comp2 = false;
            comp3 = false;
            comp4 = false;
        }
    } 
}
