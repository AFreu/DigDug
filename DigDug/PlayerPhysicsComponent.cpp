//
//  PlayerPhysicsComponent->cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17->
//  Copyright © 2017 Anton Freudenthaler-> All rights reserved->
//

#include "PlayerPhysicsComponent.hpp"


void PlayerPhysicsComponent:: update(float dt)
{
    if(!obj->isActive()) return;
    
    target = obj->closestTile(obj->getPosition());
    notify(PLAYER, obj->getPosition());
    
    if(!moving) obj->setDirection(NONE);
    
    if(!decoy_used) updateUsable(1, obj->getPosition(), obj->getDirection(), false);
    
    if(!harpooning) updateUsable(0, obj->getPosition(), obj->getDirection(), false);

    
    if(forcedDirection != NONE){
        obj->move(dt, forcedDirection, forcedSpeed);
    }
    
    
    
    if(dead) dying ++;
    if(dying == 80){ obj->deactivate(); notify(DEACTIVATED, PLAYER); }
    
    if(!dead)
    {
        if(canMove)
        {
            obj->move(dt);
        }
        else
        {
            obj->move(dt, obj->decideDirection(target, obj->getDirection()), 1);
        }
        
    }
    
    harpooning = false;
    moving = false;
    canMove = false;
    
    forcedDirection = NONE;
    forcedSpeed = 0;

}

void PlayerPhysicsComponent:: reset()
{
    dead = false;
    dying = 0;
    forcedDirection = NONE;
    forcedSpeed = 0;
    decoy_used = false;
    harpooning = false;
    moving = false;
    updateUsables(false);
    obj->activate();
    EntityBehaviourComponent::reset();
}

void PlayerPhysicsComponent:: onNotify(Event event)
{
    if(event == KEY_LEFT) { obj->setDirection(LEFT); moving = true; }
    if(event == KEY_RIGHT) { obj->setDirection(RIGHT); moving = true; };
    if(event == KEY_UP) { obj->setDirection(UP); moving = true; };
    if(event == KEY_DOWN) { obj->setDirection(DOWN); moving = true; };
    
    
    if(event == KEY_SPACE && !moving) {
        notify(HARPOONING);
        harpooning = true;
        obj->setDirection(NONE);
        updateUsable(0, obj->getPosition(), obj->getDirection(), true);
    }
    
    if(event == KEY_LSHIFT && !decoy_used){
        notify(DECOY_USED);
        updateUsable(1, obj->getPosition(), obj->getDirection(), true);
        decoy_used = true;
    }
}


void PlayerPhysicsComponent:: receive(Message message, Object& other, Entity type)
{
    if(message == COLLISION){
    switch(type)
    {
        case MONSTER:
        case GHOST_MONSTER:
        case FIRE:
            if(!dead) notify(KILLED);
            dead = true;
            break;
        case ROCK:
        case FALLING_ROCK:
            if(!dead) notify(CRUSHED);
            dead = true;
            forcedSpeed = other.getSpeed();
            forcedDirection = other.getDirection();
            break;
        default:
            break;
    }
    }

}


Entity PlayerPhysicsComponent:: getType()
{
    if(dead) return DEAD_PLAYER;
    return PLAYER;
}
