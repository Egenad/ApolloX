/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nave.h
 * Author: raquel
 *
 * Created on 27 de febrero de 2018, 18:18
 */

/*** SINGLETON */


#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef NAVE_H
#define NAVE_H

class Nave {
    
public:
    Nave ();
    Nave (int, int, sf::Sprite);
    void set_sprite(sf::Sprite);
    void set_estado(int);
    int get_posx();
    int get_posy();
    sf::Sprite get_sprite();
    int get_estado();
    void move(int, int);
    Nave(const Nave& orig);
    virtual ~Nave();
private:
    int coord_x;
    int coord_y;
    sf::Sprite sprite;
    int estado;
};

#endif /* NAVE_H */

