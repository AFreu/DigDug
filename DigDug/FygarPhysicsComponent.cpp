//
//  FygarPhysicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 16/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "FygarPhysicsComponent.hpp"

/*
 Fygars have a special behaviour to breath fire
 The fire breath has a cooldown and a duration.
*/
bool FygarPhysicsComponent:: specialBehaviour()
{
    bool breathingFire = false;
    if(special != FIRE_BREATH_COOLDOWN) special++;
    if(special == FIRE_BREATH_COOLDOWN) {
        //If there's no cooldown the fygar will breath fire once it is facing left or right
        if(canMove && (obj->getPosition().y % OBJECT_SIZE == 0) && (obj->getDirection() == RIGHT || obj->getDirection() == LEFT))
        {
            currentDirection = obj->getDirection(); //Save direction since it will be set to none during the behaviour.
            firing++;
        }
    }
    
    //Let there be flames!
    if(firing > 0)
    {
        //Freeze!
        obj->setDirection(NONE);
        
        //Let the acquired usable(s) know they are in use
        updateUsables(obj->getPosition(), currentDirection, true);
        
        breathingFire = true;
        firing++;
    }
    
    //No more flames
    if(firing >= FIRE_BREATH_DURATION)
    {
        special = 0;
        firing = 0;
        breathingFire = false;
        obj->setDirection(currentDirection);
    }
    
    return breathingFire; //Let the parent class know so it can adapt to the behaviour
}

void FygarPhysicsComponent:: reset()
{
    special = 0;
    firing = 0;
    MonsterPhysicsComponent::reset();
}