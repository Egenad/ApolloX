/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:30
 */

/*** SINGLETON */

#ifndef MENU_H
#define MENU_H

#include "Clock.h"
#include "Sprite.h"
#include "Vector2f.h"

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
private:
    int selected;
    int* options;
    //m2D::Text fuente;
    m2D::Sprite sprite;

};

#endif /* MENU_H */

