/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyB2.h
 * Author: angel
 *
 * Created on 20 de mayo de 2018, 12:16
 */

#ifndef STRATEGYB2_H
#define STRATEGYB2_H
#include "Strategy.h"
#include "Clock.h"
#include "Game.h"

class StrategyB2 : public Strategy{
public:
    StrategyB2();
    void execute(m2D::Sprite&, std::vector<Bala*>&, m2D::Texture&, m2D::Vector2f& position);
    void draw(m2D::Sprite&,m2D::Vector2f& position);
private:
    bool reset_fase;
    int x, y;
    m2D::Clock tiempoEntreBalas;
    m2D::Clock tiempoEntreBalas2;
    m2D::Clock temporizador;
    bool movido;
    bool movimiento_terminado;
    int lastmove;
    int centro;
    int contador;
};

#endif /* STRATEGYB2_H */

