/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector2f.cpp
 * Author: angel
 * 
 * Created on 19 de abril de 2018, 9:16
 */

#include "Vector2f.h"

namespace m2D{
    Vector2f::Vector2f(){
        vector.x = 0.0f;
        vector.y = 0.0f;
    }
    Vector2f::Vector2f(float _a, float _b) {
        vector.x = _a;
        vector.y = _b;
    }

    Vector2f::Vector2f(const Vector2f& orig) {
    }

    Vector2f::~Vector2f() {
    }
    float Vector2f::getVectorX(){
        return vector.x;
    }
    float Vector2f::getVectorY(){
        return vector.y;
    }
    sf::Vector2f Vector2f::getVector(){
        return vector;
    }
    void Vector2f::setVectorX(float n){
        vector.x = n;
    }
    void Vector2f::setVectorY(float n){
        vector.y = n;
    }
}
