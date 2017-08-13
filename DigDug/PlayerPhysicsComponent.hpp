//
//  PlayerPhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef PlayerPhysicsComponent_hpp
#define PlayerPhysicsComponent_hpp

#include "EntityBehaviourComponent.hpp"
#include "SDL2/SDL.h"

#include <iostream>

class PlayerPhysicsComponent : public EntityBehaviourComponent{
public:
    PlayerPhysicsComponent(Object* obj):EntityBehaviourComponent(obj){}
    void update(float dt)override;
    void reset()override;
    
    void onNotify(Event event)override;
    
    Entity getType()override;
    
    virtual void receive(Message message, Object& other, Entity type)override;
    
private:
    Direction forcedDirection = NONE;
    
    bool dead = false;
    bool decoy_used = false;
    bool harpooning = false;
    bool moving = false;
    
    int dying = 0;
    int forcedSpeed = 0;
    
    Position target;
};

#endif /* PlayerPhysicsComponent_hpp */
