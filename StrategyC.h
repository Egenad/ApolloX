/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyC.h
 * Author: angel
 *
 * Created on 16 de mayo de 2018, 18:42
 */

#ifndef STRATEGYC_H
#define STRATEGYC_H
#include "Strategy.h"
#include "Clock.h"

class StrategyC : public Strategy{
public:
    StrategyC();
    void execute(m2D::Sprite&, std::vector<Bala*>&, m2D::Texture&, m2D::Vector2f& position);
private:
    bool state;
    m2D::Clock temporizador;
};

#endif /* STRATEGYC_H */

