#include <iostream>
#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "Partida.h"
#include "Motor2D.h"
#include "RenderWindow.h"
#include "Vector2f.h"
#include "Clock.h"
#include "Event.h"

#define d 300
#define updateTickTime 15

void render_interpolacion(m2D::RenderWindow &, Partida &, Partida &, float , Nave &);

int main()
{
    //Ventana 
    m2D::RenderWindow window;
    
    //Limito el numero de fps
    window.setFramerateLimit(60);

    /*Crear nave*/
    m2D::Texture text("./resources/spritesheet.png");
    m2D::Sprite s_nave(text);
    s_nave.setOrigin(110/2,400/2);
    s_nave.setTextureRect(0,0,110,440);
    s_nave.setPosition(350, 350);
    s_nave.scale(0.5, 0.5);
   
    Nave* nave = new Nave(320, 800, s_nave);
    
    
    /*Inicializar clock*/
    m2D::Clock clock;
    m2D::Vector2f coord_nave(nave->getPosition().getVectorX(), nave->getPosition().getVectorY());
    m2D::Vector2f nuevas;
    Partida * estado_ant = new Partida(coord_nave);
    Partida * nuevoEstado;

    bool mov=false;
    
    //Bucle del juego
    while (window.isOpen())
    {      
        
        //Interpolacion
        
        if(mov == true){
            
            float p = (clock.getElapsedTimeAsSeconds()/updateTickTime);
            
            if(p>1){
                estado_ant=nuevoEstado;
                
                //mover nave final
                nave->setPosition(estado_ant->getCoordShip().getVectorX(), estado_ant->getCoordShip().getVectorY());
                mov=false;
                clock.restart();
            }
            if(p>1){
                p = 1.f;
            }
            
            render_interpolacion(window, *estado_ant, *nuevoEstado, p, *nave);         
            
        }
        
        //Bucle de obtención de eventos
        m2D::Event event;
        while (window.pollEvent(event))
        {
            
            switch(event.getEventType()){
                
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                    
                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.getKey()) {
                        
                        //Mapeo del cursor
                        
                       
                        case sf::Keyboard::Right:
                            nuevas.setVectorX(nave->getPosition().getVectorX()+d);
                            nuevas.setVectorY(nave->getPosition().getVectorY());
                            nuevoEstado = new Partida(nuevas);
                            mov=true;
                            clock.restart();
                        break;
                        
                        case sf::Keyboard::Left:
                            nuevas.setVectorX(nave->getPosition().getVectorX()-d);
                            nuevas.setVectorY(nave->getPosition().getVectorY());
                            nuevoEstado = new Partida(nuevas);
                            mov=true;
                            clock.restart();
                        break;
                        
                        case sf::Keyboard::Up:
                            nuevas.setVectorX(nave->getPosition().getVectorX());
                            nuevas.setVectorY(nave->getPosition().getVectorY()-d);
                            nuevoEstado = new Partida(nuevas);
                            mov=true;
                            clock.restart();
                        break;
                        
                        case sf::Keyboard::Down:
                            nuevas.setVectorX(nave->getPosition().getVectorX());
                            nuevas.setVectorY(nave->getPosition().getVectorY()+d);
                            nuevoEstado = new Partida(nuevas);
                            mov=true;
                            clock.restart();
                        break;
                      
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;
                        
                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.getKey() << std::endl;
                        break;
                              
                    }

            }
            
        }
         
        
        

        window.clear();
        
        window.draw(nave->getSprite());
        
        window.display();
    }

    return 0;
}

void render_interpolacion(m2D::RenderWindow &window, Partida &antiguo, Partida &nuevo, float p, Nave &nave){  
              
    window.clear();
    

    int xalt= antiguo.getCoordShip().getVectorX()*(1-p)+nuevo.getCoordShip().getVectorX()*p;
    //int xalt = xi;
    int yalt = antiguo.getCoordShip().getVectorY()*(1-p)+nuevo.getCoordShip().getVectorY()*p;

    nave.setPosition(xalt, yalt);
    antiguo.setCoordShip(xalt, yalt);
    
    window.draw(nave.getSprite());
   
}