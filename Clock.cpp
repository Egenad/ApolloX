/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clock.cpp
 * Author: angel
 * 
 * Created on 19 de abril de 2018, 10:02
 */

#include "Clock.h"
namespace m2D{
    Clock::Clock() {
        reloj.restart();
    }

    Clock::Clock(const Clock& orig) {
    }

    Clock::~Clock() {
    }
    void Clock::restart(){
        reloj.restart();
    }
    float Clock::getElapsedTimeAsSeconds(){
        return reloj.getElapsedTime().asSeconds();
    }
}
