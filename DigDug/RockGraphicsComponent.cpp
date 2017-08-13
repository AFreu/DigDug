//
//  RockGraphicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 30/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "RockGraphicsComponent.hpp"


void RockGraphicsComponent:: update(float dt)
{
    if(!obj->isActive()) return;
    int numOfFrames = 0;
    
    if(destroyed)
    {
        falling = false;
        counter++;
        numOfFrames = 4;
    }
    if(falling)
    {
        counter++;
        numOfFrames = 2;
    }
    sprites.at(0)->draw(obj->getPosition().x, obj->getPosition().y, counter, numOfFrames, NO);
    
}

void RockGraphicsComponent:: reset()
{
    destroyed = false;
    falling = false;
    fallingFor = 0;
    lastElapsed = 0;
    counter = 0;
}

void RockGraphicsComponent:: onNotify(Event event)
{
    if(!obj->isActive()) return;
    switch(event)
    {
        case DESTROYED:
            destroyed = true;
            falling = false;
            break;
        case FALLING:
            if(!destroyed) falling = true;
        default:
            break;
    }
}

void RockGraphicsComponent:: onNotify(Event event, Entity entity)
{
    if(!obj->isActive()) return;
    if(entity == ROCK) onNotify(event);
}


