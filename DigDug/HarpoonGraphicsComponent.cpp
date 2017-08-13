  //
//  HarpoonGraphicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 26/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "HarpoonGraphicsComponent.hpp"


void HarpoonGraphicsComponent:: update(float dt)
{
    if(obj->isActive())
    {
        int numFrames = 0;
        switch(obj->getDirection())
        {
            case UP:
                lastSprite = 1;
                lastFlip = VERTICAL;
                tailSprite = 3;
                tailOffsetY = +OBJECT_SIZE;
                break;
            case DOWN:
                lastSprite = 1;
                lastFlip = NO;
                tailSprite = 3;
                tailOffsetY = -OBJECT_SIZE;
                break;
            case RIGHT:
                lastSprite = 0;
                lastFlip = HORIZONTAL;
                tailSprite = 2;
                tailOffsetX = -OBJECT_SIZE;
                break;
            case LEFT:
                lastSprite = 0;
                lastFlip = NO;
                tailSprite = 2;
                tailOffsetX = +OBJECT_SIZE;
                break;
            case NONE:
                numFrames = 0;
                break;
                
                
        }
        int x = obj->getPosition().x;
        int y = obj->getPosition().y;
        int speed = obj->getSpeed();
        sprites.at(lastSprite)->draw(x, y, dt, numFrames, lastFlip);
        if(length*speed >= 1*OBJECT_SIZE) sprites.at(tailSprite)->draw(x+tailOffsetX, y+tailOffsetY);
        if(length*speed >= 2*OBJECT_SIZE) sprites.at(tailSprite)->draw(x+tailOffsetX*2, y+tailOffsetY*2);
        if(length*speed >= 3*OBJECT_SIZE) sprites.at(tailSprite)->draw(x+tailOffsetX*3, y+tailOffsetY*3);
        
    }
}

void HarpoonGraphicsComponent:: reset()
{
    length = 0;
    lastSprite = 0;
    tailSprite = 0;
    tailOffsetY = 0;
    tailOffsetX = 0;
    lastFlip = NO;
}

void HarpoonGraphicsComponent:: onNotify(Event event)
{
    switch(event)
    {
        case FLYING:
            length++;
            break;
        case RESETED:
            length = 0;
            tailOffsetX = 0;
            tailOffsetY = 0;
            break;
        default:
            break;
    }
}