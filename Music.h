/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Music.h
 * Author: angel
 *
 * Created on 18 de abril de 2018, 19:26
 */

#ifndef MUSIC_H
#define MUSIC_H
#include "Motor2D.h"
#include <iostream>

namespace m2D{
    class Music : public Motor2D{
    public:
        Music();
        Music(const Music& orig);
        virtual ~Music();
        void setLoop(bool t);
        void openFromFile(std::string nombre);
        void play();
        void setVolumen(float vol);
        void pause();
    private:
        sf::Music music;
    };
}
#endif /* MUSIC_H */

