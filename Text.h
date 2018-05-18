/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Text.h
 * Author: angel
 *
 * Created on 28 de abril de 2018, 14:25
 */

#ifndef TEXT_H
#define TEXT_H
#include "Motor2D.h"
#include "Font.h"
namespace m2D{
    class Text : public Motor2D{
    public:
        Text();
        Text(const Text& orig);
        virtual ~Text();
        void setFont(m2D::Font&);
        void setString(std::string);
        void setCharacterSize(int);
        void setColor(int, int, int);
        void setPosition(float, float);
        void setOrigin(float, float);
        sf::Text& getText();
    private:
        sf::Text text;
    };
}
#endif /* TEXT_H */

