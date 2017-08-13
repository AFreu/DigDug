  //
//  RockPhysicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 30/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "RockPhysicsComponent.hpp"

void RockPhysicsComponent:: update(float dt)
{
    if(!obj->isActive()) return;
    
    if(counter > crushedMonsters) crushedMonsters = counter;
    
    if(canMove && !destroyed)
    {
        if(!falling) aboutToFall = true; //Cause I am freeeee, freeeee faalling!
        notify(FALLING, ROCK, obj->getPosition());
        notify(FALLING, ROCK);
    }
    else if(falling) //Not allowed to move while falling, must have hit something;
    {
        falling = false;
        timer = 80;
        destroyed = true;
        notify(DESTROYED, ROCK);
    }
    
    if(falling && timer < 0) {
        obj->move(dt);
    }
    
    if(aboutToFall || destroyed){
        timer--;
    }
    if(aboutToFall && timer < 0)
    {
        falling = true;
        aboutToFall = false;
        obj->movepx(32, DOWN);
        obj->setSpeed(5);
    }
    
    if(destroyed && timer < 0)
    {
        obj->deactivate();
        notify(DEACTIVATED, ROCK);
        notify(CRUSHED, obj->getPosition(), crushedMonsters);
        
    }
    
    counter = 0;
    canMove = false;
    
}

void RockPhysicsComponent:: receive(Message message, Object &other, Entity type)
{
    if(type == MONSTER) if(falling) counter++;
}

void RockPhysicsComponent:: reset()
{
    destroyed = false;
    falling = false;
    aboutToFall = false;
    timer = 120;
    counter = 0;
    crushedMonsters = 0;
    EntityBehaviourComponent::reset();
}

Entity RockPhysicsComponent:: getType()
{
    if(falling) return FALLING_ROCK;
    return ROCK;
}