/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyA.cpp
 * Author: angel
 * 
 * Created on 21 de abril de 2018, 16:51
 */

#include "StrategyA.h"
#include "Clock.h"
#include "Nave.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

#define PI 3.14159265

StrategyA::StrategyA(){
    movido = false;
    lastmove = 0;
    movimiento_terminado = true;
    initied = false;
    centro = 0.0f;
}

void StrategyA::execute(m2D::Sprite& sprite, std::vector<Bala*>& balas_jefe, m2D::Texture& texture){
    if(!initied){
        if(Nave::Instance()->getPosition().getVectorY() - sprite.getPositionY() < 600){
            initied = true;
            centro = 765;
            temporizador.restart();
        }
        else{
            sprite.move(0, 2);
        }
    }
    else{
        if(temporizador.getElapsedTimeAsSeconds() >= 3){
            int random = rand() % 10 + 1;
            if(!movido){ //me muevo del centro a un lado
                if(movimiento_terminado){
                    if(random > 6){
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
                    if(sprite.getPositionX() > centro){
                        sprite.move(-1,0);
                    }
                    else{
                        movido = false;
                        temporizador.restart();
                    }
                }
                else{
                    if(lastmove == 2){
                        if(sprite.getPositionX() < centro){
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
        if(primer_ataque.getElapsedTimeAsSeconds() > 1.5f){
            float angul = 60;
            for(int i=0; i<8; i++){
                if(i < 4){
                    Bala * bullet = new Bala(texture, 2, angul, 3.0f);
                    bullet->setPos((m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30)));
                    bullet->rotarBala(180);
                    balas_jefe.push_back(bullet);
                    angul = angul + 20;
                }
                else{
                    if(i<6){
                        angul = angul - 30;
                        Bala * bullet = new Bala(texture, 2, angul, 2.0f);
                        bullet->setPos(m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30));
                        if(i == 4){
                            bullet->rotarBala(200);
                        }else{
                            bullet->rotarBala(200);
                        }
                        balas_jefe.push_back(bullet);
                        angul = angul - 10;
                    }
                    else{
                        if(i<7){
                            Bala * bullet = new Bala(texture, 2, 0, 3.0f);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30));
                            bullet->rotarBala(-10);
                            balas_jefe.push_back(bullet);
                        }
                        else{
                            Bala * bullet = new Bala(texture, 2, 180, 3.0f);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30));
                            bullet->rotarBala(88);
                            balas_jefe.push_back(bullet);
                        }
                    }
                }
            }
            float distancia2 = Nave::Instance()->getPosition().getVectorY() - sprite.getPositionY();
            float distancia = sqrt(pow((Nave::Instance()->getPosition().getVectorX()-sprite.getPositionX()),2)+pow((Nave::Instance()->getPosition().getVectorY()-sprite.getPositionY()),2));
            float result = asin(distancia2/distancia) * 180.0 / PI;
           
            
            if(Nave::Instance()->getPosition().getVectorX() > sprite.getPositionX()){
                result = (90-result) + 90 ;
            }
                    
            Bala * bullet = new Bala(texture, 4, result, 6.0f);
            bullet->setRectBala(620,0,70,70);
            bullet->setColor(255,0,0);
            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
            balas_jefe.push_back(bullet);     
            primer_ataque.restart();
            
        } 
        for(int i=0; i<balas_jefe.size(); i++){
            balas_jefe[i]->disparar_angulo(2);   
            float res = sprite.getPositionY() + 1000; 
            if(res < balas_jefe[i]->getY() || balas_jefe[i]->getX() < 340 || balas_jefe[i]->getX() > 1190){
                delete balas_jefe[i];
                balas_jefe.erase(balas_jefe.begin() + i);
            }
            
            if(balas_jefe[i]->returnShape().getGlobalBounds().intersects(Nave::Instance()->returnShape().getGlobalBounds()) || balas_jefe[i]->returnShape().getGlobalBounds().intersects(Nave::Instance()->returnShape2().getGlobalBounds())){
                Nave::Instance()->danyo(50);
                delete balas_jefe[i];
                balas_jefe.erase(balas_jefe.begin() + i);
            }
        }
    }
}

