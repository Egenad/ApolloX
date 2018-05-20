/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clock.h
 * Author: angel
 *
 * Created on 19 de abril de 2018, 10:02
 */

#ifndef CLOCK_H
#define CLOCK_H
#include "Motor2D.h"
namespace m2D{
    class Clock {
    public:
        Clock();
        Clock(const Clock& orig);
        virtual ~Clock();
        void restart();
        float getElapsedTimeAsSeconds();
    private:
        sf::Clock reloj;
    };
}
#endif /* CLOCK_H */

