//
//  DecoyPhysicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 24/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "DecoyPhysicsComponent.hpp"


void DecoyPhysicsComponent:: update(float dt)
{
    if(inUse) obj->activate();
    if(!inUse) obj->deactivate();
    
    if(!obj->isActive()){
        reset();
        obj->setPosition(userPosition);
        obj->setDirection(userDirection);
        return;
    }
    
    notify(PLAYER, obj->getPosition());
    
    if(dead) dying++;
    if(dying >= 120) {obj->deactivate(); inUse = false; return; }
    
    updateUsable(0, obj->getPosition(), RIGHT, false);
    updateUsable(1, obj->getPosition(), LEFT, false);
    updateUsable(2, obj->getPosition(), UP, false);
    updateUsable(3, obj->getPosition(), DOWN, false);
    
    bool moved = false;
    
    if(forcedDirection != NONE){
        obj->move(dt, forcedDirection, forcedSpeed);
    }
    
    if(triggered)
    {

        updateUsable(0, obj->getPosition(), RIGHT, true);
        updateUsable(1, obj->getPosition(), LEFT, true);
        updateUsable(2, obj->getPosition(), UP, true);
        updateUsable(3, obj->getPosition(), DOWN, true);
        
    }

    
    if(!dead)
    {
        if(canMove)
        {
            obj->move(dt);
            moved = true;
            targeting = false;
        }
        else
        {
            if(targeting){
                obj->setDirection(lastDirection);
                targeting = false;
            }else{
                obj->switchDirection();
            }
            
        }
    }
    
    
    if(moved && (obj->getPosition().x % OBJECT_SIZE == 0) && (obj->getPosition().y % OBJECT_SIZE == 0)) tryAwayFromTarget();
    
    forcedDirection = NONE;
    forcedSpeed = 0;
    canMove = false;
}

void DecoyPhysicsComponent:: reset()
{
    dead = false;
    dying = 0;
    forcedDirection = NONE;
    forcedSpeed = 0;
    triggered = false;
    updateUsables(false);
    EntityBehaviourComponent::reset();
}


void DecoyPhysicsComponent:: receive(Message message, Object& other, Entity type)
{
    if(message == COLLISION){
        switch(type)
        {
            case MONSTER:
                triggered = true;
                dead = true;
                break;
            case FIRE:
                notify(DESTROYED);
                dead = true;
                break;
            case ROCK:
                break;
            case FALLING_ROCK:
                notify(CRUSHED);
                dead = true;
                forcedSpeed = other.getSpeed();
                forcedDirection = other.getDirection();
                break;
            default:
                break;
        }
    }
    
}

void DecoyPhysicsComponent:: onNotify(Entity entity, Position pos){
    if(entity == PLAYER) target = pos;
}


void DecoyPhysicsComponent:: tryAwayFromTarget()
{
    lastDirection = obj->getDirection();
    targeting = true;
    
    
    switch(obj->getDirection())
    {
        case UP:
        case DOWN:
            if(obj->getPosition().x > target.x) obj->setDirection(RIGHT); else obj->setDirection(LEFT);
            break;
        case RIGHT:
        case LEFT:
            if(obj->getPosition().y > target.y) obj->setDirection(DOWN); else obj->setDirection(UP);
            break;
        case NONE:
            break;
    }
    
}



