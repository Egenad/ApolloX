/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FactoriaNivel.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:34
 */
/*** SINGLETON */
#include "resources/tinyxml/tinystr.h"
#include "resources/tinyxml/tinyxml.h"

#ifndef FACTORIANIVEL_H
#define FACTORIANIVEL_H

class FactoriaNivel {
public:
    static FactoriaNivel* Instance();
    void readLevel(int);
    const char* getPath();
    const char* getAlien1();
    const char* getAlien2();
    const char* getMeteor();
    const char* getbNormal();
    const char* getbBurst();
    const char* getbCannon();
    const char* getbBomb();
    const char* getbBoss();
protected:
    FactoriaNivel();
    FactoriaNivel(const FactoriaNivel& orig);
    virtual ~FactoriaNivel();
private:
    static FactoriaNivel* pinstance;
    TiXmlDocument* doc;
    TiXmlElement* level;
    const char* path; 
    const char* alien1; 
    const char* alien2; 
    const char* meteor; 
    const char* bNormal;
    const char* bBurst;
    const char* bCannon;
    const char* bBomb;
    const char* bBoss;
};

#endif /* FACTORIANIVEL_H */

