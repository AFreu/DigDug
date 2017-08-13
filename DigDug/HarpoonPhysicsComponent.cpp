//
//  HarpoonPhysicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 28/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "HarpoonPhysicsComponent.hpp"


void HarpoonPhysicsComponent:: update(float dt)
{
    if(inUse) {
        obj->activate();
        timer++;
        if(timer > 20) { obj->deactivate(); inUse = false; timer = 0;}
    }
    if(!inUse) obj->deactivate();
    if(!obj->isActive()){
        reset();
        obj->setPosition(userPosition);
        obj->setDirection(userDirection);
        return;
    }
    
    
    if(!connected)
    {
        if(length < MAX_LENGTH && canMove)
        {
            obj->move(dt);
            updateLength(obj->getPosition(), obj->getDirection());
            notify(FLYING);

        }else
        {
            reset();
            obj->setPosition(userPosition);
            obj->setDirection(userDirection);
            obj->deactivate();
            
        }
    }
    
    connected = false;
    canMove = false;
}

void HarpoonPhysicsComponent:: reset()
{
    connected = false;
    length = 0;
    notify(RESETED);
    EntityBehaviourComponent::reset();

}

void HarpoonPhysicsComponent:: receive(Message message, Object &other, Entity type)
{
    switch(type)
    {
        case MONSTER:
        case STUNNED_MONSTER:
        case GHOST_MONSTER:
            connected = true;
            break;
        case ROCK:
            length = 0;
            notify(RESETED);
            break;
        default:
            break;
    }
}


void HarpoonPhysicsComponent:: updateLength(Position pos, Direction dir)
{
    switch(dir)
    {
        case UP:
            length = userPosition.y - pos.y;
            break;
        case DOWN:
            length = pos.y - userPosition.y;
            break;
        case LEFT:
            length = userPosition.x - pos.x;
            break;
        case RIGHT:
            length = pos.x - userPosition.x;
            break;
        case NONE:
            break;
    }
    length = length / OBJECT_SIZE;
    

}


void HarpoonPhysicsComponent:: onNotify(Position pos, Direction dir, bool inUse)
{
    if(inUse) timer = 0;
    Usable::onNotify(pos, dir, inUse);
}