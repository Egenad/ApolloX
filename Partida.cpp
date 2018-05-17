/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.cpp
 * Author: raquel
 * 
 * Created on 26 de marzo de 2018, 21:31
 */
#include <iostream>

#include "Game.h"
#include "Pausa.h"
#include "Partida.h"
#include "Sprite.h"
#include "Estado.h"
#include "Texture.h"
#include "RenderWindow.h"
#include "Meteorito.h"
#include "FactoriaNivel.h"
#include <math.h>
#include <sstream>
#include "Strategy.h"
#include "StrategyA.h"
#include "StrategyB.h"
#include <string>
#include "Escudo.h"

Partida* Partida::pinstance=0;
Partida* Partida::Instance(){
    if(pinstance==0){
        pinstance=new Partida;
    }
    
    return pinstance;
}

Partida::Partida() {
   //inicializamos todo
    score=0;
    state=0;
    
    texture.setLoadFromFile("resources/nivel.png");
    
    background=new m2D::Sprite[3];
    
    for(int i=0;i<3;i++){
        background[i].setTexture(texture);
    }
    
    //fondo
    background[0].setOrigin(585/2,510/2);
    background[0].setTextureRect(95,355,585,510);
    background[0].setPosition(1535/2,0);
    background[0].scale(1.5,1.5);
    
    background[1].setOrigin(585/2,510/2);
    background[1].setTextureRect(95,355,585,510);
    background[1].setPosition((1535/2),0-(1.5*510));
    background[1].scale(1.5,1.5);
    
    background[2].setOrigin(585/2,510/2);
    background[2].setTextureRect(95,355,585,510);
    background[2].setPosition((1535/2),0-3*(510));
    background[2].scale(1.5,1.5);
    
    lastBgMoved=0;
   
    //nave
    ship = Nave::Instance();
    ship->setTexture(texture);
    
    //vista
    view.setSize(1535.0f,860.0f);
    m2D::RenderWindow::Instance()->setView(view);
    
     //Jefe
    bossTexture.setLoadFromFile("resources/bosses.png");
    jefe = new Jefe();
    jefe->setTexture(bossTexture);
    
    
    //variables score y vida
    font.loadFromFile("resources/pirulen.ttf");
    
    text=new m2D::Text[5];
    
    for(int i=0;i<5;i++){
        text[i].setFont(font);
    }
    
    text[0].setString("VIDA");
    text[0].setCharacterSize(30);
    text[0].setPosition(20,ship->getPosition().getVectorY()-790);
    
    text[1].setString("PUNTUACION");
    text[1].setCharacterSize(30);
    text[1].setPosition(20,ship->getPosition().getVectorY()-550);
    
    text[2].setString("MUNICION");
    text[2].setCharacterSize(30);
    text[2].setPosition(20,ship->getPosition().getVectorY()-500);
    
    text[3].setString("000");
    text[3].setCharacterSize(30);
    text[3].setPosition(40,ship->getPosition().getVectorY()-590);
    
    text[4].setString("normal");
    text[4].setCharacterSize(25);
    text[4].setPosition(40,ship->getPosition().getVectorY()-445);
    
    lifeS=new m2D::Sprite[4];
    for(int i=0;i<4;i++){
        lifeS[i].setTexture(bossTexture);//vida del jefe
    }
    
    lifeS[0].setTextureRect(0,810,234,15);
    lifeS[0].setPosition(10,ship->getPosition().getVectorY()-720);
    lifeS[0].scale(1.3,1.3);
    
    lifeS[1].setTextureRect(0,0,219,5);
    lifeS[1].setPosition(20,ship->getPosition().getVectorY()-715);
    lifeS[1].scale(1.3,1.3);
    
    lifeS[2].setTextureRect(0,810,234,15);
    lifeS[2].setPosition(500,ship->getPosition().getVectorY()-720);
    lifeS[2].scale(1.3,1.3);
    
    lifeS[3].setTextureRect(0,0,219,5);
    lifeS[3].setPosition(510,ship->getPosition().getVectorY()-715);
    lifeS[3].scale(1.3,1.3);
    lifeS[3].setColor(150,0,0);
}

void Partida::handleInput(){
    m2D::Event event;
    
    while(m2D::RenderWindow::Instance()->pollEvent(event)){
        
        if(event.getEventType()== sf::Event::Closed){
           m2D::RenderWindow::Instance()->close();
        }
         if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left)){
             ship->moveLeft();
         }
         if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right)){
             ship->moveRight();
         }
         if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space)){
             ship->disparar(texture);
         }
         if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape)){
             Game::Instance()->setState(Pausa::Instance());
         }
         if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up)){
             if(state==1){
                 ship->moveUp();
             }
         }
         if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down)){
             if(state==1){
                 ship->moveDown();
             }
         }
    }    //Si pulsamos cursor izquierda
}

void Partida::update(){
    if(state==0){
        //updateamos el fondo
        this->moveBackground();
        //updateamos el player
        ship->update();
        if(ship->getPosition().getVectorY()<=(-length-860)){
            if(mode==0){
               state=1; 
            }else{
                this->Infinite();
            }
        }
        
        //updateamos la vista
        view.setCenter(1535/2,ship->getPosition().getVectorY()-360);
        m2D::RenderWindow::Instance()->setView(view);
        
        
        //UPDATE METEORITO
        for(int i=0;i<t3;i++){
           if((view.getCenter().getVectorY()+420)>meteor[i].getCoord().getVectorY()&&(view.getCenter().getVectorY()-420)<meteor[i].getCoord().getVectorY()){
                meteor[i].update();
                ship->checkCollMete(meteor[i]);//comprobamos la colision de los meteorios con la nave
            }      
        }
 
        //UPDATE ALIENS A (GRANDES)
        for(int i=0;i<t1;i++){
            //los updateamos solo si estan dentro de la pantalla
            if((view.getCenter().getVectorY()+420)>aliens[i].getPos().getVectorY()&&(view.getCenter().getVectorY()-420)<aliens[i].getPos().getVectorY()){
                aliens[i].Update();
                if(aliens[i].getStateAlien() == 0){
                    aliens[i].dispara(texture);
                    ship->golpea(aliens[i]); //si mata al alien
                }
            }
        }
        
        this->updateText();
        
        //Coger escudo
        for(int i=0;i<ts;i++){
           if((view.getCenter().getVectorY()+420)>shell[i].getCoord().getVectorY()&&(view.getCenter().getVectorY()-420)<shell[i].getCoord().getVectorY()){
                //shell[i].update();
                ship->checkCollEsc(shell[i]);
                
            }      
        }
        
    }else{
        //updateamos de distinta forma
        ship->disparar(texture);
        jefe->update(texture);
        ship->update2();
    }
    
    
    
}

void Partida::draw(){
    for(int i=0;i<3;i++){
        m2D::RenderWindow::Instance()->draw(background[i]);
    }
    
    for(int i=0;i<5;i++){
        m2D::RenderWindow::Instance()->drawT(text[i]);
    }
    for(int i=0;i<2;i++){
        m2D::RenderWindow::Instance()->draw(lifeS[i]);
    }
    
    ship->draw();
    
    for(int i=0;i<t1;i++){
        aliens[i].dibujaBalas();
    }
    
    for(int i=0;i<t3;i++){
        if((view.getCenter().getVectorY()+420)>meteor[i].getCoord().getVectorY()&&(view.getCenter().getVectorY()-420)<meteor[i].getCoord().getVectorY()){
            if(meteor[i].getCoord().getVectorX()<1159&&meteor[i].getCoord().getVectorX()>400){
                meteor[i].draw();
            }
        }
    }
    
    for(int i=0;i<t1;i++){
        //los dibujamos solo si estan dentro de la pantalla
        if((view.getCenter().getVectorY()+420)>aliens[i].getPos().getVectorY()&&(view.getCenter().getVectorY()-420)<aliens[i].getPos().getVectorY()){
            //si se ha salido de los bordes no dibujamos pero si updateamos
            if(aliens[i].getPos().getVectorX()<1159&&aliens[i].getPos().getVectorX()>400){
                aliens[i].draw();
            }
        }
    }
    if(state == 1){
        jefe->draw();
        m2D::RenderWindow::Instance()->draw(lifeS[2]);
        m2D::RenderWindow::Instance()->draw(lifeS[3]);
    } 
    
    //escudos
    for(int i=0;i<ts;i++){
        shell[i].draw();
    }
    
    //materiales
    /*
    if(mode==1){
        for(int i=0;i<m1;i++){
            carbon[i].draw();
        }
        for(int i=0;i<m2;i++){
            hierro[i].draw();
        }
        for(int i=0;i<m3;i++){
            titanio[i].draw();
        }
        for(int i=0;i<m4;i++){
            magnesio[i].draw();
        }
    }
     */ 

}

void Partida::moveBackground(){
    
    if(ship->getPosition().getVectorY()-360<=background[lastBgMoved].getPositionY()+50){
        int move=lastBgMoved+1;
        if(move==3){
            move=0;
        }
        background[move].setPosition((1535/2),background[lastBgMoved].getPositionY()-765);
        lastBgMoved=move;
    }
}

void Partida::Init(int i){
    
    mode=0;
    
    FactoriaNivel* fLvl = FactoriaNivel::Instance();

    fLvl->readLevel(i);

    const char* p = fLvl->getPath();
    std::stringstream ss;
    ss << p;
    ss>>length;
    
    const char* enemy1 = fLvl->getAlien1();
    std::stringstream ss2;
    ss2 << enemy1;
    ss2>>t1;
    
    const char* enemy2 = fLvl->getAlien2();
    std::stringstream ss3;
    ss3 << enemy2;
    ss3>>t2;
    
    const char* m = fLvl->getMeteor();
    std::stringstream ss4;
    ss4 << m;
    ss4>>t3;
    
    const char* jeff = fLvl->getbBoss();
    std::stringstream ss5;
    ss5 << jeff;
    ss5>>t4;
    
    jefe->setType(t4);
    jefe->setTexture(bossTexture);
    if(t4 == 1){
        jefe->setStrategy(new StrategyA());   
    }
    jefe->setFase(0);

    int totalEnemies=t3+t2+t1;
    
    int cont1=0;
    int cont2=0;
    int cont3=0;
    
    int* enemiesB=new int[t2];
    int ran3=rand()%100;
    meteor=new Meteorito[t3]; //meteoritos
    aliens=new Alien[t1]; //aliens
    
    //Escudos
    ts=2;
    shell=new Escudo[ts];
    int conts=0;
    
    
    int total=totalEnemies+ts;
    
    int intS = total/(ts+1);
    
    srand(time(NULL));
    for(int i=0;i<total;i++){
        
        if(intS==i && conts<ts){
            int x1=rand() % 585;
            x1=x1+475;
            
            int y1 =(length/total)*i;
            shell[conts].setCoord(x1,-y1-860);
            shell[conts].setTexture(texture);
            conts++;
            intS = intS + total/(ts+1);
            
        }else {
            int a=rand() % 9;
            if(a>=0&&a<=5){
                //creamos enemigo A
                if(cont1<t1){

                    int x1=rand() % 585;
                    x1=x1+475;
                    int y1 =(length/total)*i;
                    aliens[cont1].setPos(x1,-y1-860);
                    aliens[cont1].setTexture(texture);
                    cont1++;

                }else if(cont2<t2){
                    enemiesB[cont2]=i;
                    cont2++;
                }else if(cont3<t3){
                    int x=rand() % 585;
                    x=x+475;
                    int y =(length/total)*i;
                    meteor[cont3].setCoord(x,-y-860);
                    meteor[cont3].setTexture(texture);
                    cont3++;
                }

            }else if(a>=6&&a<=7){
                //creamos meteorito
                if(cont2<t2){

                    enemiesB[cont2]=i;
                    cont2++;
                }else if(cont3<t3){
                    int x=rand() % 585;
                    x=x+475;
                    int y =(length/total)*i;
                    meteor[cont3].setCoord(x,-y-860);
                    meteor[cont3].setTexture(texture);
                    cont3++;

                }else if(cont1<t1){

                    int x1=rand() % 585;
                    x1=x1+475;
                    int y1 =(length/total)*i;
                    aliens[cont1].setPos(x1,-y1-860);
                    aliens[cont1].setTexture(texture);
                    cont1++;
                }
            }else{
                //creamos enemigo B
                if(cont3<t3){
                    int x=rand() % 585;
                    x=x+475;
                    int y =(length/total)*i;
                    meteor[cont3].setCoord(x,-y-860);
                    meteor[cont3].setTexture(texture);
                    cont3++;

                }else if(cont1<t1){

                    int x1=rand() % 585;
                    x1=x1+475;
                    int y1 =(length/total)*i;
                    aliens[cont1].setPos(x1,-y1-860);
                    aliens[cont1].setTexture(texture);
                    cont1++;
                }else if(cont2<t2){

                    enemiesB[cont2]=i;
                    cont2++;
                }
            }
        }
    }
    
}
void Partida::Infinite(){
    
    mode=1; //modo infinito
    
    FactoriaNivel* fLvl = FactoriaNivel::Instance();
    
    if(ship->getPosition().getVectorY()==0){
        //Empieza
        lvlI=1;
        std::cout<<"Empieza modo infinito"<<std::endl;
        
        fLvl->readLevel(lvlI);
        
        //Leer xml
        const char* p = fLvl->getPath();
        std::stringstream ss;
        ss << p;
        ss>>path;
        std::cout<<"Path: "<< path<<std::endl;
        
        length=path;
        

        const char* enemy1 = fLvl->getAlien1();
        std::stringstream ss2;
        ss2 << enemy1;
        ss2>>t1;
        std::cout<<"Enemigo1: "<< t1<<std::endl;

        const char* enemy2 = fLvl->getAlien2();
        std::stringstream ss3;
        ss3 << enemy2;
        ss3>>t2;
        std::cout<<"Enemigo2: "<< t2<<std::endl;

        const char* m = fLvl->getMeteor();
        std::stringstream ss4;
        ss4 << m;
        ss4>>t3;
        std::cout<<"Enemigo3: "<< t3<<std::endl;
        
        m1=3;
        m2=4;
        m3=3;
        m4=8;  

    }else{
        std::cout<<"Continuamos modo infinito"<< lvlI << std::endl;
        length=length+path;
    }
    
    
    
    int totalEnemies = t3+t2+t1;
    int cont1=0;
    int cont2=0;
    int cont3=0;
    
    int* enemiesB=new int[t2]; //Alien2
    int ran3=rand()%100;
    meteor=new Meteorito[t3]; //meteoritos
    aliens=new Alien[t1]; //aliens
    
    int totalmaterials=m3+m2+m1;
    
    int cont4=0;
    int cont5=0;
    int cont6=0;
    
    int* materialA=new int[m1];
    int* materialB= new int[m2];
    int* materialC = new int[m3];
    
    //Enemigos
    srand(time(NULL));
    for(int i=0;i<totalEnemies;i++){
        int a=rand() % 9;
        if(a>=0&&a<=5){
            //creamos enemigo A
            if(cont1<t1){
                
                int x1=rand() % 585;
                x1=x1+475;
                int y1 =(length/totalEnemies)*i;
                aliens[cont1].setPos(x1,-y1-860);
                aliens[cont1].setTexture(texture);
                cont1++;
                
            }else if(cont2<t2){
                enemiesB[cont2]=i;
                cont2++;
            }else if(cont3<t3){
                int x=rand() % 585;
                x=x+475;
                int y =(length/totalEnemies)*i;
                meteor[cont3].setCoord(x,-y-860);
                meteor[cont3].setTexture(texture);
                cont3++;
            }
            
        }else if(a>=6&&a<=7){
            //creamos meteorito
            if(cont2<t2){
                
                enemiesB[cont2]=i;
                cont2++;
            }else if(cont3<t3){
                int x=rand() % 585;
                x=x+475;
                int y =(length/totalEnemies)*i;
                meteor[cont3].setCoord(x,-y-860);
                meteor[cont3].setTexture(texture);
                cont3++;
                
            }else if(cont1<t1){
                
                int x1=rand() % 585;
                x1=x1+475;
                int y1 =(length/totalEnemies)*i;
                aliens[cont1].setPos(x1,-y1-860);
                aliens[cont1].setTexture(texture);
                cont1++;
            }
        }else{
            //creamos enemigo B
            if(cont3<t3){
                int x=rand() % 585;
                x=x+475;
                int y =(length/totalEnemies)*i;
                meteor[cont3].setCoord(x,-y-860);
                meteor[cont3].setTexture(texture);
                cont3++;
                
            }else if(cont1<t1){
                
                int x1=rand() % 585;
                x1=x1+475;
                int y1 =(length/totalEnemies)*i;
                aliens[cont1].setPos(x1,-y1-860);
                aliens[cont1].setTexture(texture);
                cont1++;
            }else if(cont2<t2){
                
                enemiesB[cont2]=i;
                cont2++;
            }
        }
    }
    /*
    //materiales
    srand(time(NULL));
    for(int i=0;i<totalmaterials;i++){
        int a=rand() % 9;
        if(a>=0&&a<=5){
            //creamos material A
            if(cont4<m1){
                
                materialA[cont4]=i;
                cont4++;
            }else if(cont5<m2){
                
                materialB[cont5]=i;
                cont5++;
            }else if(cont6<m3){
                int x=rand() % 585;
                x=x+475;
                int y =(path/totalmaterials)*i - ship->getPosition().getVectorY();
                materialC[cont6]=i;
                cont6++;
            }
            
        }else if(a>=6&&a<=7){
            //creamos meteorito
            if(cont5<m2){
                
                materialB[cont5]=i;
                cont5++;
            }else if(cont6<m3){
                int x=rand() % 585;
                x=x+475;
                int y =(path/totalmaterials)*i - ship->getPosition().getVectorY();
                materialC[cont6]=i;
                cont6++;
            }else if(cont4<m1){
                
                materialA[cont4]=i;
                cont4++;
            }
        }else{
            //creamos enemigo B
            if(cont6<m3){
                int x=rand() % 585;
                x=x+475;
                int y =(path/totalmaterials)*i - ship->getPosition().getVectorY();
                materialC[cont6]=i;
                cont6++;
            }else if(cont4<m1){
                
                materialA[cont4]=i;
                cont4++;
            }else if(cont5<m2){
                
                materialB[cont5]=i;
                cont5++;
            }
        }
    }
     */ 
     
    
}

float Partida::getCoordViewX(){
    return view.getCenter().getVectorX();
}
float Partida::getCoordViewY(){
    return view.getCenter().getVectorY();
}

void Partida::setViewtoOrigin(){
    view.setCenter(1535/2,860/2);
    m2D::RenderWindow::Instance()->setView(view);
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

void Partida::updateText(){
    text[0].setPosition(20,ship->getPosition().getVectorY()-790);
    text[1].setPosition(20,ship->getPosition().getVectorY()-650);
    text[2].setPosition(20,ship->getPosition().getVectorY()-500);
    lifeS[0].setPosition(10,ship->getPosition().getVectorY()-720);
    lifeS[1].setPosition(20,ship->getPosition().getVectorY()-715);
    text[3].setPosition(40,ship->getPosition().getVectorY()-590);
    text[4].setPosition(40,ship->getPosition().getVectorY()-445);
    lifeS[2].setPosition(1200,ship->getPosition().getVectorY()-720);
    lifeS[3].setPosition(1210,ship->getPosition().getVectorY()-715);
}

void Partida::reduceLifeBar(int life){
    int width=(life*219)/1000;
    lifeS[1].setTextureRect(0,0,width,5);
}

void Partida::reduceLifeBarBoss(int life){
    int width=(life*219)/10000;
    lifeS[3].setTextureRect(0,0,width,5);
}


void Partida::aumentScore(){
    score=score+400;
    
    std::stringstream sa;
    sa << score;
    std::string strs = sa.str();
    text[3].setString(strs);
}

void Partida::setViewtoShip(){
    view.setCenter(1535/2,ship->getPosition().getVectorY()-360);
    m2D::RenderWindow::Instance()->setView(view);
}