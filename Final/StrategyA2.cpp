/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   StrategyA2.cpp
 * Author: angel
 * 
 * Created on 17 de mayo de 2018, 18:08
 */

#include "StrategyA2.h"
#include "Clock.h"
#include "Nave.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Game.h"

#define PI 3.14159265

StrategyA2::StrategyA2(){
    movido = false;
    lastmove = 0;
    movimiento_terminado = true;
    initied = false;
    centro = 0.0f;
    contadorOleada = 0;
    oleadasInitied = false;
    lanzandoOleada = false;
    canyon = false;
    grados = 0;
    cambio = false;
    contador = 3;
}

void StrategyA2::execute(m2D::Sprite& sprite, std::vector<Bala*>& balas_jefe, m2D::Texture& texture, m2D::Vector2f& position){  
    if(!initied){
        if(Nave::Instance()->getPosition().getVectorY() - sprite.getPositionY() < 600){
            initied = true;
            centro = 765;
            temporizador.restart();
        }
        else{
            //sprite.move(0, 2);
            x=0;
            y=10;
            position.setVectorX(position.getVectorX());
            position.setVectorY(position.getVectorY() + y);
            sprite.setPosition(position.getVectorX(),position.getVectorY());
        }
    }
    else{
        if(contador <= 0 && (position.getVectorX() >= 1100 || position.getVectorX() <= 500)){
            canyon = true;
            contador = 3;
        }
        else{
            if(!canyon){
                if(oleadasInitied != false){
                    lanzandoOleada = true;
                    if(contadorOleada < 5){
                        if(primer_ataque.getElapsedTimeAsSeconds() > 0.5f){
                            float angul = 40;
                            if(contadorOleada == 0){
                                reseteoAngulo.restart();
                            }
                            for(int i=0; i<6; i++){
                                Bala * bullet = new Bala(texture, 2, angul, 13.0f);
                                bullet->setPos(m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30));
                                bullet->setRectBala(620,0,70,70);
                                bullet->escalarBala(0.4,0.4);
                                bullet->setColor(220, 19, 7);
                                bullet->rotarBala(180);
                                balas_jefe.push_back(bullet);
                                angul = angul + 20;
                            }
                            primer_ataque.restart();
                            reseteoAngulo.restart();
                            contadorOleada++;
                        }
                    } 
                    else{
                        contadorOleada = 0;
                        oleadasInitied = false;
                        lanzandoOleada = false;
                        int rain = rand() % 10 + 1;
                        if(rain <= 5){
                            lastmove = 1;

                        }else{
                            lastmove = 2;

                        }
                    }
                }else{
                    if(lastmove == 0 && lanzandoOleada == false){            
                        int rain2 = rand() % 10 + 1;
                        if(rain2 > 4){
                            oleadasInitied = true;
                            lanzandoOleada = true;
                        }
                        else{
                            if(rain2<=3){
                                lastmove = 2;  
                            }
                            else{
                                lastmove = 1;                       
                            }
                        }
                    }else if(lanzandoOleada == false){

                        if(tiempo_balas1.getElapsedTimeAsSeconds() > 1){
                            tiempo_balas1.restart();
                            Bala * bullet = new Bala(texture, 1, 90, 13.0f);
                            bullet->setColor(9, 166, 82);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX()-5, sprite.getPositionY()-30));
                            bullet->setRectBala(620,0,70,70);
                            bullet->escalarBala(0.6,0.6);
                            balas_jefe.push_back(bullet);
                        }

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
                                        x=7;
                                        y=0;
                                        if(sprite.getPositionX() < 1100){
                                            position.setVectorX(position.getVectorX() + x);
                                            position.setVectorY(position.getVectorY());
                                            sprite.setPosition(position.getVectorX(),position.getVectorY());
                                        }
                                        else{
                                            movimiento_terminado = true;
                                            temporizador.restart();
                                            movido = true;
                                            contador--;
                                        }
                                    }
                                    else{
                                        if(sprite.getPositionX() > 500){
                                            x=-7;
                                            y=0;
                                            position.setVectorX(position.getVectorX() + x);
                                            position.setVectorY(position.getVectorY());
                                            sprite.setPosition(position.getVectorX(),position.getVectorY());
                                        }
                                        else{
                                            movimiento_terminado = true;
                                            temporizador.restart();
                                            movido = true;
                                            contador--;
                                        }
                                    }
                                }
                            }else{//me muevo de un lado al centro
                                if(lastmove == 1){
                                    y = 0;
                                    x = -7;
                                    if(sprite.getPositionX() > centro){
                                        position.setVectorX(position.getVectorX() + x);
                                        position.setVectorY(position.getVectorY());
                                        sprite.setPosition(position.getVectorX(),position.getVectorY());
                                    }
                                    else{
                                        movido = false;
                                        temporizador.restart();
                                        lastmove = 0;
                                    }
                                }
                                else{
                                    if(lastmove == 2){
                                        if(sprite.getPositionX() < centro){
                                            x = 7;
                                            y = 0;
                                            position.setVectorX(position.getVectorX() + x);
                                            position.setVectorY(position.getVectorY());
                                            sprite.setPosition(position.getVectorX(),position.getVectorY());
                                        }
                                        else{
                                            movido = false;
                                            temporizador.restart();
                                            lastmove = 0;
                                        }
                                    }
                                }
                            }
                        }
                    } 
                }
            }
            else{
                if(tiempo_balas4.getElapsedTimeAsSeconds() > 0.3){
                    tiempo_balas4.restart();
                    Bala * bullet = new Bala(texture, 4, 90, 16.0f);
                    bullet->setRectBala(620,0,70,70);
                    bullet->setColor(12, 198, 255);
                    bullet->escalarBala(0.8, 0.8);
                    bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                    balas_jefe.push_back(bullet);     
                }
                if(lastmove == 2){
                    if(sprite.getPositionX() < 1000){
                        x = 13;
                        y = 0;
                        position.setVectorX(position.getVectorX() + x);
                        position.setVectorY(position.getVectorY());
                        sprite.setPosition(position.getVectorX(),position.getVectorY());
                    }
                    else{
                        movido = true;
                        temporizador.restart();
                        lastmove = 1;
                        canyon = false;
                    }
                }
                else{
                    if(sprite.getPositionX() > 400){
                        x = -13;
                        y = 0;
                        position.setVectorX(position.getVectorX() + x);
                        position.setVectorY(position.getVectorY());
                        sprite.setPosition(position.getVectorX(),position.getVectorY());
                    }
                    else{
                        movido = true;
                        temporizador.restart();
                        lastmove = 2;
                        canyon = false;
                        for(int xx=0; xx<balas_jefe.size(); xx++){
                            if(balas_jefe[xx]->getTipo() == 3 || balas_jefe[xx]->getTipo() == 6){
                                delete balas_jefe[xx];
                                balas_jefe.erase(balas_jefe.begin() + xx);
                            }
                        }
                    }
                }
            }
            if(reseteoAngulo.getElapsedTimeAsSeconds() > 1.0f){
                if(!balas_jefe.empty()){
                    for(int i=0; i<balas_jefe.size(); i++){
                        if(balas_jefe[i]->getTipo() == 2){
                            balas_jefe[i]->setAngulo(90);
                        }
                    }
                    reseteoAngulo.restart();
                }
            }

            if(!balas_jefe.empty() && tiempo_balas2.getElapsedTimeAsSeconds() > 0.5){
                for(int i=0; i<balas_jefe.size(); i++){
                    if(balas_jefe[i]->getTipo() == 1){

                        if(grados >= 180 && !cambio){
                            cambio = true;
                        }
                        else{
                            if(grados <= 0 && cambio)
                                cambio = false;
                        }

                        if(cambio == false){
                            grados += 20;
                        }
                        else{
                            grados -= 20;
                        }

                        balas_jefe[i]->setAngulo(grados);
                    }
                }
                tiempo_balas2.restart();
            }

            int contador = 2;

            if(tiempo_balas3.getElapsedTimeAsSeconds() > 10 && !balas_jefe.empty()){
                for(int i=0; i<balas_jefe.size() && contador != 0; i++){
                    if(balas_jefe[i]->getTipo() == 1 && contador != 0){
                       delete balas_jefe[i];
                       balas_jefe.erase(balas_jefe.begin() + i); 
                       contador--;
                    }
                }
                tiempo_balas3.restart();
            }

            for(int i=0; i<balas_jefe.size(); i++){
                balas_jefe[i]->disparar_angulo();   
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
}

void StrategyA2::draw(m2D::Sprite& sprite,m2D::Vector2f& position){
    if(Game::Instance()->getP()<1){
        float posY=position.getVectorY()*(1-Game::Instance()->getP())+(position.getVectorY()+x)*Game::Instance()->getP();
        float posX=position.getVectorX()*(1-Game::Instance()->getP())+(position.getVectorX()+y)*Game::Instance()->getP();
        sprite.setPosition(posX,posY);
    }
}
