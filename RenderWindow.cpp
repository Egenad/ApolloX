/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RenderWindow.cpp
 * Author: angel
 * 
 * Created on 18 de abril de 2018, 18:36
 */

#include "RenderWindow.h"

namespace m2D{
    
    RenderWindow* RenderWindow::pinstance=0;
    
    RenderWindow* RenderWindow::Instance(){
        if(pinstance==0){
            pinstance=new RenderWindow;
        }
        return pinstance;
    }
    
    void RenderWindow::setView(m2D::View& view){
        window.setView(view.getView());
    }
    
    RenderWindow::RenderWindow() {
        
        window.create(sf::VideoMode(1535, 860), "Apollo X");
        window.setFramerateLimit(60);
    }

    RenderWindow::RenderWindow(const RenderWindow& orig) {
    }

    RenderWindow::~RenderWindow() {
    }
    void RenderWindow::clear(){
        window.clear();
    }
    void RenderWindow::close(){
        window.close();
    }
    void RenderWindow::display(){
        window.display();
    }
    bool RenderWindow::isOpen(){
        return window.isOpen();
    }
    void RenderWindow::setFramerateLimit(int n){
        window.setFramerateLimit(n);
    }
    bool RenderWindow::pollEvent(m2D::Event& event){
        return window.pollEvent(event.getTrueEvent());
    }
    void RenderWindow::draw(m2D::Sprite& sprite){
        window.draw(sprite.getSprite());
    }
}

