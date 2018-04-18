/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 19:15
 */
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef ESTADO_H
#define ESTADO_H

class Estado {
public:
    Estado();
    Estado(sf::Vector2f);
    sf::Vector2f get_coord_nave();
    Estado(const Estado& orig);
    virtual ~Estado();
private:
    sf::Vector2f nave;
};

#endif /* ESTADO_H */

