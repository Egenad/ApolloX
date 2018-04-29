/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   View.h
 * Author: shiro
 *
 * Created on 25 de abril de 2018, 14:53
 */

#ifndef VIEW_H
#define VIEW_H

#include "Motor2D.h"
#include "Vector2f.h"

namespace m2D{
class View : public Motor2D{
public:
    View();
    View(const View& orig);
    virtual ~View();
    m2D::Vector2f getCenter();
    void setCenter(float, float);
    void setSize(float, float);
    sf::View& getView();
private:
    sf::View view;
};
}

#endif /* VIEW_H */

