/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.h
 * Author: angel
 *
 * Created on 19 de abril de 2018, 13:10
 */

#ifndef TEXTURE_H
#define TEXTURE_H
#include "Motor2D.h"
namespace m2D{
    class Texture {
    public:
        Texture(std::string);
        Texture(const Texture& orig);
        virtual ~Texture();
        sf::Texture& getTexture();
    private:
        sf::Texture text;
    };
}
#endif /* TEXTURE_H */

