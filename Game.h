/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: shiro
 *
 * Created on 23 de abril de 2018, 13:44
 */

#ifndef GAME_H
#define GAME_H

#include "Estado.h"
#include "Menu.h"

class Game {
public:
    static Game* Instance();
    void setState(Estado* state);
    void runGame();
    
protected:
    Game();
    Game(const Game& orig);
    virtual ~Game();
private:
    static Game* pinstance;
    Estado* state;

};

#endif /* GAME_H */

