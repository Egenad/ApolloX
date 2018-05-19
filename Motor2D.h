/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor2D.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:36
 */

/*** SINGLETON */

#ifndef MOTOR2D_H
#define MOTOR2D_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

namespace m2D{
    class Motor2D {
    public:
        Motor2D();
        Motor2D(const Motor2D& orig);
        virtual ~Motor2D();
    private:
        
    };
}
#endif /* MOTOR2D_H */

