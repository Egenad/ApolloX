/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyA2.h
 * Author: angel
 *
 * Created on 17 de mayo de 2018, 18:08
 */

#ifndef STRATEGYA2_H
#define STRATEGYA2_H
#include "Strategy.h"
#include "Clock.h"
#include "Sprite.h"

class StrategyA2 : public Strategy{
public:
    StrategyA2();
    void execute(m2D::Sprite&, std::vector<Bala*>&, m2D::Texture&, m2D::Vector2f& position);
private:
    bool movido;
    float centro;
    bool movimiento_terminado;
    int lastmove;
    int contadorOleada;
    m2D::Clock temporizador;
    m2D::Clock primer_ataque;
    m2D::Clock reseteoAngulo;
    m2D::Clock tiempo_balas1;
    m2D::Clock tiempo_balas2;
    m2D::Clock tiempo_balas3;
    bool initied;
    float grados;
    bool oleadasInitied;
    bool lanzandoOleada;
    bool canyon;
    bool cambio;
    int contador;
    m2D::Clock tiempo_balas4;
};
#endif 

