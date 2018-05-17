/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 19:15
 */
#include <iostream>

#ifndef ESTADO_H
#define ESTADO_H

class Estado {
public:
    /*Estado();
    Estado(const Estado& orig);
    virtual ~Estado();*/
    virtual void handleInput()=0;
    virtual void draw()=0;
    virtual void update()=0;
private:
    
};

#endif /* ESTADO_H */

