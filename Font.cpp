/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Font.cpp
 * Author: angel
 * 
 * Created on 28 de abril de 2018, 14:19
 */

#include "Font.h"
#include <iostream>

namespace m2D{
    Font::Font() {
    }

    Font::Font(const Font& orig) {
    }

    Font::~Font() {
    }
    void Font::loadFromFile(std::string cadena){
        if(!font.loadFromFile(cadena)){
            std::cout << "Error cargando fichero de texto" << std::endl;
            exit(0);
        }
    }
    sf::Font& Font::getFont(){
        return font;
    }
}
