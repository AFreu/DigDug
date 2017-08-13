//
//  VeggiePhysicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 20/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "VeggiePhysicsComponent.hpp"


void VeggiePhysicsComponent:: update(float dt)
{
    if(!obj->isActive()) return;
    if(taken){ notify(TAKEN, obj->getPosition()); }
    if(taken || timer <= 0){ obj->deactivate(); notify(DEACTIVATED);}
    timer--;
}

void VeggiePhysicsComponent:: receive(Message message, Object &other, Entity type)
{
    if(message == COLLISION && type == PLAYER) {
        taken = true;
        notify(TAKEN);
    }
}

void VeggiePhysicsComponent:: onNotify(Event event, Entity entity)
{
    if(entity == ROCK && event == DEACTIVATED){
        deactivatedRocks++;
        if(deactivatedRocks == 2) obj->activate();
    }
}

void VeggiePhysicsComponent:: onNotify(Event event, int value)
{
    notify(event, value); //Pass along to graphics
}

void VeggiePhysicsComponent:: reset()
{
    taken = false;
    timer = 240;
    deactivatedRocks = 0;
    EntityBehaviourComponent::reset();
}
