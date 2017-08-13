//
//  FireGraphicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 17/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "FireGraphicsComponent.hpp"

void FireGraphicsComponent:: update(float dt)
{
    if(!obj->isActive())
    {
        start = obj->getPosition();
        return;
    }
    
        switch(obj->getDirection())
        {
            case UP:
                break;
            case DOWN:
                break;
            case RIGHT:
                lastFlip = HORIZONTAL;
                tailOffsetX = +OBJECT_SIZE;
                break;
            case LEFT:
                lastFlip = NO;
                tailOffsetX = -OBJECT_SIZE;
                break;
            case NONE:
                break;
                
                
        }
    
    if(length == 3)
    {
        sprites.at(3)->
        draw(start.x + tailOffsetX, start.y, lastFlip);
        sprites.at(4)->draw(start.x + tailOffsetX*2, start.y, lastFlip);
        sprites.at(2)->draw(start.x + tailOffsetX*3, start.y, lastFlip);
    }
    else if(length == 2)
    {
        sprites.at(1)->draw(start.x + tailOffsetX, start.y, lastFlip);
        sprites.at(2)->draw(start.x + tailOffsetX*2, start.y, lastFlip);
    }
    else if(length == 1)
    {
        sprites.at(0)->draw(start.x + tailOffsetX, start.y, lastFlip);
    }
}

void FireGraphicsComponent:: reset()
{
    length = 0;
    tailOffsetY = 0;
    tailOffsetX = 0;
    lastFlip = NO;
}

void FireGraphicsComponent:: onNotify(Event event)
{
    switch(event)
    {
        case SPREAD_FIRE:
            length++;
            break;
        case RESETED:
            length = 0;
            break;
        default:
            break;
    }
}