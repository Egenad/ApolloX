/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.cpp
 * Author: angel
 * 
 * Created on 18 de abril de 2018, 18:56
 */

#include "Event.h"
namespace m2D{
    Event::Event() {
    }

    Event::Event(const Event& orig) {
    }

    Event::~Event() {
    }
    
    sf::Event::EventType Event::getEventType(){
        return event.type;
    }
    
    sf::Keyboard::Key Event::getKey(){
        return event.key.code;
    }
    
    sf::Event& Event::getEvent(){
        return event;
    }
}

