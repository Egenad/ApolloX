/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RenderWindow.h
 * Author: angel
 *
 * Created on 18 de abril de 2018, 18:36
 */

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include "Motor2D.h"
#include "Event.h"
#include "Sprite.h"
#include "View.h"
#include "Text.h"

namespace m2D{
    class RenderWindow : public Motor2D{
    
    protected:
        RenderWindow();
        RenderWindow(const RenderWindow& orig);
        virtual ~RenderWindow();
    public:
        static RenderWindow* Instance();
        void setFramerateLimit(int);
        bool isOpen();
        void close();
        void clear();
        void draw(m2D::Sprite&);
        void drawT(m2D::Text&);
        void display();
        bool pollEvent(m2D::Event&);
        void setView(m2D::View&);
    private:
        sf::RenderWindow window;
        static RenderWindow* pinstance;
    };
}
#endif /* RENDERWINDOW_H */

