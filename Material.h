/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Material.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:35
 */
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sprite.h"
#include "Vector2f.h"

#ifndef MATERIAL_H
#define MATERIAL_H

class Material {
public:
    Material();
    Material(const Material& orig);
    virtual ~Material();
private:
    int type;
    m2D::Sprite sprite;
    m2D::Vector2f position;
    int state;
    int p_appear;
};

#endif /* MATERIAL_H */

