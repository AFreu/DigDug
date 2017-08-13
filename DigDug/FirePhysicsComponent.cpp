//
//  FirePhysicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 17/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "FirePhysicsComponent.hpp"


void FirePhysicsComponent:: update(float dt)
{
    if(inUse) obj->activate();
    if(!inUse){
      reset();
      obj->deactivate();
      obj->setPosition(userPosition);
      obj->setDirection(userDirection);
        
    }
    if(!obj->isActive()){ return; }
    
    
    
    if(length < 3 && canMove)
    {
        obj->move(dt);
        updateLength(obj->getPosition(), obj->getDirection());
    }
    
    
    inUse = false;
    canMove = false;
}

void FirePhysicsComponent:: reset()
{
    lastLength = 0;
    length = 0;
    counter = 0;
    notify(RESETED);
    EntityBehaviourComponent::reset();
    
}


void FirePhysicsComponent:: updateLength(Position pos, Direction dir)
{
    switch(dir)
    {
        case UP:
            //length = userPosition.y - pos.y;
            break;
        case DOWN:
            //length = pos.y - userPosition.y;
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
    if(lastLength < length) notify(SPREAD_FIRE);
    lastLength = length;
    
}

