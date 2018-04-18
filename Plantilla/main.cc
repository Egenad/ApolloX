#include <iostream>
#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "Estado.h"

#define d 300
#define updateTickTime 15

void render_interpolacion(sf::RenderWindow &, Estado &, Estado &, float , Nave &);

int main()
{
    //Ventana 
    sf::RenderWindow window(sf::VideoMode(640, 880), "Apollo X");
    
    //Limito el numero de fps
    window.setFramerateLimit(60);
    

    
    /*Crear nave*/
     sf::Texture tex_nave;
    if (!tex_nave.loadFromFile("resources/spritesheet.png"))
    {
        std::cerr << "Error cargando la imagen spritessheet.png";
        exit(0);
    }

    sf::Sprite s_nave(tex_nave);
    s_nave.setOrigin(110/2,400/2);
    s_nave.setTextureRect(sf::IntRect(0, 0, 110, 400));
    s_nave.scale(0.5, 0.5);
   
    
    Nave nave(320, 800, s_nave);
    
    
    /*Inicializar clock*/
    sf::Clock clock;
    sf::Vector2f coord_nave(nave.get_posx(), nave.get_posy());
    sf::Vector2f nuevas;
    Estado * estado_ant = new Estado(coord_nave);
    Estado * nuevoEstado;
    /*
    int xi = nave.get_posx();
    int yi = nave.get_posy();
    int xf;
    int yf;
     * */
    bool mov=false;
    
    //Bucle del juego
    while (window.isOpen())
    {      
        
        //Interpolacion
        
        if(mov == true){
            
            float p = (clock.getElapsedTime().asSeconds()/updateTickTime);
            if(p>1){
                estado_ant=nuevoEstado;
                
                //mover nave final
                mov=false;
                clock.restart();
            }
            if(p>1){
                p = 1.f;
            }
            
            render_interpolacion(window, *estado_ant, *nuevoEstado, p, nave);         
            
        }
        
        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            switch(event.type){
                
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                    
                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {
                        
                        //Mapeo del cursor
                        
                       
                        case sf::Keyboard::Right:
                            nuevas.x=nave.get_posx()+d;
                            nuevas.y=nave.get_posy();
                            nuevoEstado = new Estado(nuevas);
                            mov=true;
                            clock.restart();
                        break;
                        
                        case sf::Keyboard::Left:
                            nuevas.x=nave.get_posx()-d;
                            nuevas.y=nave.get_posy();
                            nuevoEstado = new Estado(nuevas);
                            mov=true;
                            clock.restart();
                        break;
                        
                        case sf::Keyboard::Up:
                            nuevas.x=nave.get_posx();
                            nuevas.y=nave.get_posy()-d;
                            nuevoEstado = new Estado(nuevas);
                            mov=true;
                            clock.restart();
                        break;
                        
                        case sf::Keyboard::Down:
                            nuevas.x=nave.get_posx();
                            nuevas.y=nave.get_posy()+d;
                            nuevoEstado = new Estado(nuevas);
                            mov=true;
                            clock.restart();
                        break;
                      
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;
                        
                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.key.code << std::endl;
                        break;
                              
                    }

            }
            
        }
         
        
        

        window.clear();
        
        window.draw(nave.get_sprite());
        
        window.display();
    }

    return 0;
}

void render_interpolacion(sf::RenderWindow &window, Estado &antiguo, Estado &nuevo, float p, Nave &nave){  
                
    window.clear();
    

    int xalt= antiguo.get_coord_nave().x*(1-p)+nuevo.get_coord_nave().x*p;
    //int xalt = xi;
    int yalt = antiguo.get_coord_nave().y*(1-p)+nuevo.get_coord_nave().y*p;

    nave.move(xalt, yalt);

    window.draw(nave.get_sprite());


    
}