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
    
    /*std::string Event::getEvent(){
        switch(event.type){
            case sf::Event::Closed:
                return "Closed";
            break;
            case sf::Event::KeyPressed:
                switch(event.key.code){
                    case sf::Keyboard::Left:
                        return "Left";
                    break;
                    case sf::Keyboard::Right:
                        return "Right";
                    break;
                    case sf::Keyboard::Up:
                        return "Up";
                    break;
                    case sf::Keyboard::Down:
                        return "Down";
                    break;
                    case sf::Keyboard::Return:
                        return "Return";
                    break;
                    case sf::Keyboard::Space:
                        return "Space";
                    break;
                    default:
                        return "Innecesario";
                    break;
                }
            break;
        }
    }*/
    sf::Event& Event::getTrueEvent(){
        return event;
    }
}

