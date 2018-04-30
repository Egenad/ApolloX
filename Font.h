/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Font.h
 * Author: angel
 *
 * Created on 28 de abril de 2018, 14:19
 */

#ifndef FONT_H
#define FONT_H
#include "Motor2D.h"

namespace m2D{
    class Font : public Motor2D{
    public:
        Font();
        Font(const Font& orig);
        virtual ~Font();
        void loadFromFile(std::string);
        sf::Font& getFont();
    private:
        sf::Font font;
    };
}
#endif /* FONT_H */

