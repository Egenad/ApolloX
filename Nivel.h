/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:32
 */

#ifndef NIVEL_H
#define NIVEL_H

#include "Jefe.h"

class Nivel {
public:
    Nivel();
    Nivel(const Nivel& orig);
    virtual ~Nivel();
private:
    int numLevel;
    int longPath;
    int state; //inicio-trayectoria-jefe-final
    bool bossIn;
    Jefe* boss;
};

#endif /* NIVEL_H */

