/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPC.h
 * Author: raquel
 *
 * Created on 26 de marzo de 2018, 21:34
 */

#ifndef NPC_H
#define NPC_H

class NPC {
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void setTexture(m2D::Texture& texture)=0;
    
private:

    
};

#endif /* NPC_H */

