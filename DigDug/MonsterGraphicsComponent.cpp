//
//  MonsterGraphicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 05/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "MonsterGraphicsComponent.hpp"

//MonsterGraphicsComponent:: MonsterGraphicsComponent(std::vector<Sprite*> sprites)
//{
//    this->sprites = sprites;
//}

void MonsterGraphicsComponent:: update(float dt)
{
    if(!obj->isActive()) return;
    int sprite = 0;
    int numFrames = 2;
    counter++;
    
    inflated = false;
    if(inflate >= 0) inflated = true;
    
    if(ghost) sprite = 1;
    if(stunned) sprite = 3;
    if(inflated) sprite = 4+inflate;
    if(crushed) sprite = 2;
    if(stunned || inflated || crushed) numFrames = 1;
    
    switch(obj->getDirection())
    {
        case LEFT:
            lastFlip = NO;
            break;
        case RIGHT:
            lastFlip = HORIZONTAL;
            break;
        case UP:
        case DOWN:
        case NONE:
            break;
    }
    
    sprites.at(sprite)->draw(obj->getPosition().x, obj->getPosition().y, counter*obj->getSpeed(), numFrames, lastFlip);
}

void MonsterGraphicsComponent:: reset()
{
    crushed = false;
    stunned = false;
    ghost = false;
    
    inflate = -1;
    inflated = false;
    
    lastSprite = 0;
    lastFlip = NO;
}

void MonsterGraphicsComponent:: onNotify(Event event)
{
    switch(event)
    {
        case NOT_GHOST:
            ghost = false;
            break;
        case GHOST:
            ghost = true;
            break;
        case CRUSHED:
            crushed = true;
            break;
        case INFLATE:
            inflate = 0;
            break;
        case INFLATED:
            inflate = 1;
            break;
        case EXPLOAD:
            inflate = 2;
            break;
        case DEFLATE:
            inflate = -1;
            break;
        case STUNNED:
            stunned = true;
            break;
        case NOT_STUNNED:
            stunned = false;
            break;
        default:
            break;
    }
}
