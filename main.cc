#include <iostream>
#include "Nave.h"
#include "Partida.h"
#include "Motor2D.h"
#include "RenderWindow.h"
#include "Vector2f.h"
#include "Clock.h"
#include "Event.h"
#include "Game.h"
#include "Logo.h"

int main()
{   
    Game* game = Game::Instance();
    game->setState(Logo::Instance());
    
    //bucle del juego
    game->runGame();

    return 0;
}