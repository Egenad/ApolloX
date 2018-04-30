/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   View.cpp
 * Author: shiro
 * 
 * Created on 25 de abril de 2018, 14:53
 */

#include "View.h"
#include <SFML/Graphics.hpp>

namespace m2D{
    View::View() {
        
    }

    View::View(const View& orig) {
    }

    View::~View() {
    }
    
    void View::setCenter(float a, float b){
        view.setCenter(a,b);
    }
    
    void View::setSize(float a, float b){
        view.setSize(a,b);
    }
    
    sf::View& View::getView(){
        return view;
    }
    
    m2D::Vector2f View::getCenter(){
        return m2D::Vector2f(view.getCenter().x,view.getCenter().y);
    }
}
