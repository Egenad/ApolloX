/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.cpp
 * Author: angel
 * 
 * Created on 19 de abril de 2018, 13:11
 */

#include "Texture.h"
#include <iostream>
namespace m2D{
    Texture::Texture(std::string cadena) {
        if (!text.loadFromFile(cadena))
        {
            std::cerr << "Error cargando la imagen " << cadena << std::endl;
            exit(0);
        }
    }
    
    sf::Texture& Texture::getTexture(){
        return text;
    }
    
    Texture::Texture(const Texture& orig) {
    }

    Texture::~Texture() {
    }
}

