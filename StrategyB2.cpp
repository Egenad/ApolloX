/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyB2.cpp
 * Author: angel
 * 
 * Created on 20 de mayo de 2018, 12:16
 */


#include "StrategyB2.h"
#include "Nave.h"
StrategyB2::StrategyB2(){
    reset_fase = true;
    x=0;
    y=0;
    contador = 0;
    movido = false;
    lastmove = 0;
    movimiento_terminado = true;
    centro = 765;
}

void StrategyB2::execute(m2D::Sprite& sprite, std::vector<Bala*>& balas_jefe, m2D::Texture& texture, m2D::Vector2f& position){
    if(reset_fase == true){//paso de la fase A a la B
        if(sprite.getPositionX() < 765){//se encuentra por la izquierda
            x=10;
            y=0;
            position.setVectorX(position.getVectorX() + x);
            position.setVectorY(position.getVectorY());
            sprite.setPosition(position.getVectorX(),position.getVectorY());
        }
        else{
            if(sprite.getPositionX() > 765){//se encuentra por la derecha
                x=-10;
                y=0;
                position.setVectorX(position.getVectorX() +x);
                position.setVectorY(position.getVectorY());
                sprite.setPosition(position.getVectorX(),position.getVectorY());
            }
        }
        if(!balas_jefe.empty()){
            for(int i=0; i<balas_jefe.size(); i++){ 
                delete balas_jefe[i];
                balas_jefe.erase(balas_jefe.begin() + i);
            } 
        }
        if(sprite.getPositionX() >= 760  && sprite.getPositionX() <= 770 && balas_jefe.size() == 0){
            reset_fase = false;
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
                            x=10;
                            y=5;
                            position.setVectorX(position.getVectorX() + x);
                            position.setVectorY(position.getVectorY() + y);
                            sprite.setPosition(position.getVectorX(),position.getVectorY());
                        }
                        else{
                            movimiento_terminado = true;
                            temporizador.restart();
                            movido = true;
                        }
                    }
                    else{
                        if(sprite.getPositionX() > 500){
                            x=-10;
                            y=5;
                            position.setVectorX(position.getVectorX() + x);
                            position.setVectorY(position.getVectorY() + y);
                            sprite.setPosition(position.getVectorX(),position.getVectorY());
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
                        x=-10;
                        y=-5;
                        position.setVectorX(position.getVectorX() +x);
                        position.setVectorY(position.getVectorY() + y);
                        sprite.setPosition(position.getVectorX(),position.getVectorY());
                    }
                    else{
                        movido = false;
                        temporizador.restart();
                    }
                }
                else{
                    if(lastmove == 2){
                        if(sprite.getPositionX() < centro){
                            x=10;
                            y=-5;
                            position.setVectorX(position.getVectorX() + x);
                            position.setVectorY(position.getVectorY() + y);
                            sprite.setPosition(position.getVectorX(),position.getVectorY());
                        }
                        else{
                            movido = false;
                            temporizador.restart();
                        }
                    }
                }
            }
        }   
        if(tiempoEntreBalas.getElapsedTimeAsSeconds() > 1){
            if(contador > 2){
                contador = 0;
            }
            switch(contador){
                case 0:{
                    for(int i=0; i<4; i++){
                        if(i==0){
                            Bala * bullet = new Bala(texture, 4, 0, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);
                        }else if(i == 1){
                            Bala * bullet = new Bala(texture, 4, 20, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }else if(i == 2){
                            Bala * bullet = new Bala(texture, 4, 20, 10.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }else{
                            Bala * bullet = new Bala(texture, 4, 40, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }
                    }
                break;}
                case 1:{
                    for(int i=0; i<4; i++){
                        if(i==0){
                            Bala * bullet = new Bala(texture, 4, 90, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);
                        }else if(i == 1){
                            Bala * bullet = new Bala(texture, 4, 70, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }else if(i == 2){
                            Bala * bullet = new Bala(texture, 4, 90, 10.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }else{
                            Bala * bullet = new Bala(texture, 4, 110, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }
                    }
                break;}
                case 2:{
                    for(int i=0; i<4; i++){
                        if(i==0){
                            Bala * bullet = new Bala(texture, 4, 180, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);
                        }else if(i == 1){
                            Bala * bullet = new Bala(texture, 4, 160, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }else if(i == 2){
                            Bala * bullet = new Bala(texture, 4, 160, 10.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }else{
                            Bala * bullet = new Bala(texture, 4, 140, 13.0f);
                            bullet->setRectBala(620,0,70,70);
                            bullet->setColor(12, 198, 255);
                            bullet->escalarBala(0.4, 0.4);
                            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
                            balas_jefe.push_back(bullet);     
                        }
                    }
                break;}
                
            }
            contador++;
            tiempoEntreBalas.restart();
        }
    }
    
    if(tiempoEntreBalas2.getElapsedTimeAsSeconds() > 3){
        int angulo = 0;
        for(int i=0; i<8; i++){
            Bala * bullet = new Bala(texture, 4, angulo, 15.0f);
            bullet->setRectBala(620,0,70,70);
            bullet->setColor(251, 245, 38);
            bullet->escalarBala(0.2, 0.2);
            bullet->setPos(m2D::Vector2f(sprite.getPositionX(), sprite.getPositionY()));
            balas_jefe.push_back(bullet);
            angulo += 45;
        }
        tiempoEntreBalas2.restart();
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

void StrategyB2::draw(m2D::Sprite& sprite,m2D::Vector2f& position){
    if(Game::Instance()->getP()<1){
            float posY=position.getVectorY()*(1-Game::Instance()->getP())+(position.getVectorY()+x)*Game::Instance()->getP();
            float posX=position.getVectorX()*(1-Game::Instance()->getP())+(position.getVectorX()+y)*Game::Instance()->getP();
            sprite.setPosition(posX,posY);
        }
}