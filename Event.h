/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: angel
 *
 * Created on 18 de abril de 2018, 18:56
 */

#ifndef EVENT_H
#define EVENT_H
#include "Motor2D.h"

namespace m2D{
    class Event : public Motor2D{
    public:
        Event();
        Event(const Event& orig);
        virtual ~Event();
        sf::Event::EventType getEventType();
        sf::Event& getEvent();
        sf::Keyboard::Key getKey();
    private:
        sf::Event event;
    };
}
#endif /* EVENT_H */

