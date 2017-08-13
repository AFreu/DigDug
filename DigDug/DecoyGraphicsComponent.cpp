//
//  DecoyGraphicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 01/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "DecoyGraphicsComponent.hpp"

void DecoyGraphicsComponent:: update(float dt)
{
    if(!obj->isActive()) return;
    counter++;
    dir = obj->getDirection();
        
    renderNormal();
        
    if(harpooning) { renderHarpooning();}
    if(killed) { renderKilled();}
    if(crushed) { renderCrushed();}
        
    sprites.at(lastSprite)->draw(obj->getPosition().x, obj->getPosition().y, counter*obj->getSpeed(), numOfFrames, lastFlip);
        
    harpooning = false;
}

void DecoyGraphicsComponent:: reset()
{
    lastSprite = 0;
    numOfFrames = 0;
    lastFlip = NO;
    crushed = false;
    killed = false;
    harpooning = false;
}

void DecoyGraphicsComponent:: onNotify(Event event)
{
    switch(event)
    {
        case CRUSHED:
            crushed = true;
            break;
        case DESTROYED:
            killed = true;
            break;
        case HARPOONING:
            harpooning = true;
            break;
        default:
            break;
    }
}

void DecoyGraphicsComponent:: renderCrushed()
{
    lastSprite = 2;
    numOfFrames = 0;
    lastFlip = NO;
}

void DecoyGraphicsComponent:: renderKilled()
{
    lastSprite = 4;
    numOfFrames = 4;
    lastFlip = NO;
}

void DecoyGraphicsComponent:: renderHarpooning()
{
    lastSprite = 6;
    numOfFrames = 2;
    if(dir == LEFT) lastFlip = HORIZONTAL;
    if(dir == RIGHT) lastFlip = NO;
}

void DecoyGraphicsComponent:: renderNormal()
{
    lastSprite = 0;
    numOfFrames = 2;
    if(dir == LEFT) lastFlip = HORIZONTAL;
    if(dir == RIGHT) lastFlip = NO;
}



