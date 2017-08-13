//
//  VeggiePhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 20/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef VeggiePhysicsComponent_hpp
#define VeggiePhysicsComponent_hpp

#include "EntityBehaviourComponent.hpp"

class VeggiePhysicsComponent : public EntityBehaviourComponent{
public:
    VeggiePhysicsComponent(Object* obj):EntityBehaviourComponent(obj){}
    void update(float dt)override;
    void reset()override;
    Entity getType()override{return VEGGIE;}
    
    virtual void receive(Message message, Object& other, Entity type)override;
    
    virtual void onNotify(Event event, Entity entity)override;
    virtual void onNotify(Event event, int value)override;
    
private:
    int timer = 240;
    int deactivatedRocks = 0;
    bool taken = false;
};

#endif /* VeggiePhysicsComponent_hpp */
