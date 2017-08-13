//
//  PlayerGraphicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "PlayerGraphicsComponent.hpp"

void PlayerGraphicsComponent:: update(float dt)
{
    if(obj->isActive())
    {
        counter++;
        renderNormal();
        
        if(harpooning) renderHarpooning();
        if(killed) renderKilled();
        if(crushed) renderCrushed();
        
        sprites.at(lastSprite)->draw(obj->getPosition().x, obj->getPosition().y, counter*obj->getSpeed(),  numOfFrames, lastFlip);
        
        harpooning = false;
    }
}

void PlayerGraphicsComponent:: reset()
{
    lastSprite = 0;
    lastFlip = NO;
    crushed = false;
    killed = false;
    harpooning = false;
}

void PlayerGraphicsComponent:: onNotify(Event event)
{
    switch(event)
    {
        case CRUSHED:
            crushed = true;
            break;
        case KILLED:
            killed = true;
            counter = 0;
            break;
        case HARPOONING:
            harpooning = true;
            break;
        default:
            break;
    }
}

void PlayerGraphicsComponent:: renderCrushed()
{
    numOfFrames = 1;
    switch(obj->getDirection()){
        case UP:
            lastSprite = 3;
            lastFlip = NO;
            break;
        case DOWN:
            lastSprite = 3;
            lastFlip = VERTICAL;
            break;
        case LEFT:
        case RIGHT:
            lastSprite = 2;
            lastFlip = NO;
            break;
        case NONE:
            lastSprite = 2;
            lastFlip = NO;
            break;
    }
    

}

void PlayerGraphicsComponent:: renderKilled()
{
    numOfFrames = 4;
    switch(obj->getDirection())
    {
        case UP:
            lastSprite = 5;
            lastFlip = NO;
            break;
        case DOWN:
            lastSprite = 5;
            lastFlip = VERTICAL;
            break;
        case LEFT:
        case RIGHT:
            lastSprite = 4;
            lastFlip = NO;
            break;
        case NONE:
            lastSprite = 4;
            break;
    }
    
}

void PlayerGraphicsComponent:: renderHarpooning()
{
    if(lastSprite == 0) lastSprite = 6;
    if(lastSprite == 1) lastSprite = 7;
    numOfFrames = 2;
}

void PlayerGraphicsComponent:: renderNormal()
{
    numOfFrames = 2;
    switch(obj->getDirection())
    {
        case UP:
            lastSprite = 1;
            lastFlip = VERTICAL;
            break;
        case DOWN:
            lastSprite = 1;
            lastFlip = NO;
            break;
        case LEFT:
            lastSprite = 0;
            lastFlip = HORIZONTAL;
            break;
        case RIGHT:
            lastSprite = 0;
            lastFlip = NO;
            break;
        case NONE:
            numOfFrames = 0;
            break;
    }
}

