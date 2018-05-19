/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector2f.h
 * Author: angel
 *
 * Created on 19 de abril de 2018, 9:16
 */

#ifndef VECTOR2F_H
#define VECTOR2F_H
#include "Motor2D.h"
namespace m2D{
    class Vector2f : public Motor2D{
    public:
        Vector2f();
        Vector2f(float, float);
        Vector2f(const Vector2f& orig);
        sf::Vector2f getVector();
        virtual ~Vector2f();
        float getVectorX();
        float getVectorY();
        void setVectorX(float);
        void setVectorY(float);
    private:
        sf::Vector2f vector;
    };
}
#endif /* VECTOR2F_H */

