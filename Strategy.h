/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Strategy.h
 * Author: angel
 *
 * Created on 21 de abril de 2018, 16:34
 */

#ifndef STRATEGY_H
#define STRATEGY_H
#include "Bala.h"
#include "Motor2D.h"

class Strategy {
public:
    virtual void execute(m2D::Sprite& sprite, std::vector<Bala*>& balas_jefe, m2D::Texture& texture, m2D::Vector2f& position) = 0;
    virtual void draw(m2D::Sprite& sprite,m2D::Vector2f& position)=0;
private:

};

#endif /* STRATEGY_H */

