/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyB.h
 * Author: angel
 *
 * Created on 22 de abril de 2018, 11:07
 */
#ifndef STRATEGYB_H
#define STRATEGYB_H
#include "Strategy.h"
#include "Clock.h"

class StrategyB : public Strategy{
public:
    StrategyB();
    void execute(m2D::Sprite&, std::vector<Bala*>&, m2D::Texture&);
private:
    m2D::Clock timer;
    bool reset_fase;
    bool oleada;
    bool creados;
    bool movido;
    m2D::Clock temporizador;
    m2D::Clock terceras_balas;
    m2D::Clock segundas_balas;
    bool movimiento_terminado;
    int lastmove;
    int namber;
    bool comp1;
    bool comp2;
    bool comp3;
    bool comp4;
};
#endif


