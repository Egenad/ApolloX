/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Music.cpp
 * Author: angel
 * 
 * Created on 18 de abril de 2018, 19:26
 */


#include "Music.h"
namespace m2D{
    
    Music::Music(){
        /*if(n=="menu"){
            music.openFromFile("resources/Europa.ogx");
            std::cout<<"pillo archivo"<<std::endl;
        }
        else{
            std::cout <<"Error al crear la musica"<<std::endl;
        }*/
    }
    
    Music::Music(const Music& orig) {
        
    }

    Music::~Music() {
        
    }
    void Music::setLoop(bool t){
        music.setLoop(t);
    }
    void Music::openFromFile(std::string nombre){
        music.openFromFile(nombre);
    }
    void Music::setVolumen(float vol){
        music.setVolume(vol);
    }
    void Music::pause(){
        music.pause();
    }
    
    void Music::play(){
        music.play();
    }
    
    void Music::stop(){
        music.stop();
    }
    
    
    

}
