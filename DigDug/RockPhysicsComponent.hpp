//
//  RockPhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 30/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef RockPhysicsComponent_hpp
#define RockPhysicsComponent_hpp

#include "EntityBehaviourComponent.hpp"

class RockPhysicsComponent : public EntityBehaviourComponent{
public:
    RockPhysicsComponent(Object* obj):EntityBehaviourComponent(obj){}
    void update(float dt)override;
    void reset()override;
    Entity getType()override;

    virtual void receive(Message message, Object& other, Entity type)override;
    
private:
    bool falling = false;
    bool destroyed = false;
    bool aboutToFall = false;
    
    int timer = 120;
    int crushedMonsters = 0;
    int counter = 0;    
};

#endif /* RockPhysicsComponent_hpp */
