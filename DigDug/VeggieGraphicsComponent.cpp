//
//  VeggieGraphicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 20/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "VeggieGraphicsComponent.hpp"

//VeggieGraphicsComponent:: VeggieGraphicsComponent(std::vector<Sprite*> sprites)
//{
//    this->sprites = sprites;
//}

void VeggieGraphicsComponent:: update(float dt)
{
    if(!obj->isActive()) return;
    sprites.at(level-1)->draw(obj->getPosition().x, obj->getPosition().y);
}

void VeggieGraphicsComponent:: reset()
{
    level = 1;
}

void VeggieGraphicsComponent:: onNotify(Event event)
{
    
}

void VeggieGraphicsComponent:: onNotify(Event event, int value)
{
    this->level = value % sprites.size();
}
