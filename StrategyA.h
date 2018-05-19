/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyA.h
 * Author: angel
 *
 * Created on 21 de abril de 2018, 16:51
 */
#ifndef STRATEGYA_H
#define STRATEGYA_H
#include "Strategy.h"
#include "Clock.h"
#include "Sprite.h"

class StrategyA : public Strategy{
public:
    StrategyA();
    void execute(m2D::Sprite&, std::vector<Bala*>&, m2D::Texture&, m2D::Vector2f& position);
    void draw(m2D::Sprite&,m2D::Vector2f& position);
private:
    bool movido;
    float centro;
    bool movimiento_terminado;
    int lastmove;
    m2D::Clock temporizador;
    m2D::Clock primer_ataque;
    bool initied;
    int x;
    int y;
};
#endif 

