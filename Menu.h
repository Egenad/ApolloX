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

#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"

class Menu : public Estado {
public:
    static Menu* Instance();
    void handleInput();
    void update();
    void draw();
    void up();
    void down();
    void resetSelected();
protected:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
private:
    int seleccionado;
    m2D::Sprite* sprites;
    m2D::Texture texture;
    static Menu* pinstance;

};

#endif /* MENU_H */

