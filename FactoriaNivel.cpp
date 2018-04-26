/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FactoriaNivel.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:34
 */

#include "FactoriaNivel.h"
#include "resources/tinyxml/tinystr.h"
#include "resources/tinyxml/tinyxml.h"

FactoriaNivel* FactoriaNivel::pinstance=0;
FactoriaNivel* FactoriaNivel::Instance(){
    if(pinstance==0){
        pinstance=new FactoriaNivel;
    }
    
    return pinstance;
}

FactoriaNivel::FactoriaNivel() {
    doc = new TiXmlDocument("resources/mapa.xml");
    bool ok = doc->LoadFile();
    if(!ok){
        exit(0);
    }
}

FactoriaNivel::FactoriaNivel(const FactoriaNivel& orig) {
}

FactoriaNivel::~FactoriaNivel() {
}

void FactoriaNivel::readLevel(int lvl){
    TiXmlElement* map = doc->RootElement();
     
    if(lvl==1){
        level = map->FirstChildElement("Nivel1");
    }else if(lvl==2){
        level = map->FirstChildElement("Nivel2");
    }else if(lvl==3){
        level = map->FirstChildElement("Nivel3");
    }
    
    //Longitud
    path = level->FirstChildElement("Mapa")->GetText();
    //Enemigos
    alien1 = level->FirstChildElement("Enemigos")->FirstChildElement("Alien1")->GetText();
    alien2 = level->FirstChildElement("Enemigos")->FirstChildElement("Alien2")->GetText();
    meteor = level->FirstChildElement("Enemigos")->FirstChildElement("Meteorito")->GetText();
    //Escudo

    //Municion
    bNormal = level->FirstChildElement("Municion")->FirstChildElement("Normal")->GetText();
    bBurst = level->FirstChildElement("Municion")->FirstChildElement("Rafaga")->GetText();
    bCannon = level->FirstChildElement("Municion")->FirstChildElement("Canyon")->GetText();
    bBomb = level->FirstChildElement("Municion")->FirstChildElement("Bomba")->GetText();
    
}
const char* FactoriaNivel::getPath(){
    return path;
}
const char* FactoriaNivel::getAlien1(){
    return alien1;
}
const char* FactoriaNivel::getAlien2(){
    return alien2;
}
const char* FactoriaNivel::getMeteor(){
    return meteor;
}
const char* FactoriaNivel::getbNormal(){
    return bNormal;
}
const char* FactoriaNivel::getbBurst(){
    return bBurst;
}
const char* FactoriaNivel::getbCannon(){
    return bCannon;
}
const char* FactoriaNivel::getbBomb(){
    return bBomb;
}

