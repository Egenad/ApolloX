/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 19:16
 */
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Estado.h"

Estado::Estado() {

}
Estado::Estado(sf::Vector2f coord_nave) {
    nave=coord_nave;
}

Estado::Estado(const Estado& orig) {
}

Estado::~Estado() {
}

sf::Vector2f Estado::get_coord_nave(){
    return nave;
}

