/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Text.cpp
 * Author: angel
 * 
 * Created on 28 de abril de 2018, 14:25
 */

#include "Text.h"
namespace m2D{
    Text::Text() {
    }

    Text::Text(const Text& orig) {
    }

    Text::~Text() {
    }
    void Text::setFont(m2D::Font& fuente){
        text.setFont(fuente);
    }
    void Text::setString(std::string cadena){
        text.setString(cadena);
    }
    void Text::setCharacterSize(int n){
        text.setCharacterSize(n);
    }
    void Text::setColor(int r,int g, int b){
        text.setColor(sf::Color(r,g,b));
    }
    void Text::setPosition(float x, float y){
        text.setPosition(x,y);
    }
    void Text::setOrigin(float x, float y){
        text.setOrigin(x,y);
    }
    sf::Text& Text::getText(){
        return text;
    }
}
