/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: shiro
 * 
 * Created on 23 de abril de 2018, 13:44
 */

#include "Game.h"
#include "RenderWindow.h"

#define UPDATE_TICK_TIME 1000/15

Game* Game::pinstance=0;

Game* Game::Instance(){
    if(pinstance==0){
        pinstance=new Game;
    }
    
    return pinstance;
}

void Game::setState(Estado* state){
    this->state=state;
}

void Game::runGame(){
    m2D::RenderWindow* window = m2D::RenderWindow::Instance();
    
    while(window->isOpen()){
        window->clear();
        state->handleInput();
        p=(updateClock.getElapsedTimeAsSeconds()*1000)/UPDATE_TICK_TIME;
        if(updateClock.getElapsedTimeAsSeconds()*1000>UPDATE_TICK_TIME){
            state->update();
            updateClock.restart();
        }
        state->draw();
        window->display();
    }
}

Game::Game() {
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

float Game::getP(){
    return p;
}

