//
//  DecoyPhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 24/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef DecoyPhysicsComponent_hpp
#define DecoyPhysicsComponent_hpp

#include "EntityBehaviourComponent.hpp"

class DecoyPhysicsComponent : public EntityBehaviourComponent{
public:
    DecoyPhysicsComponent(Object* obj) : EntityBehaviourComponent(obj) {}
    void update(float dt)override;
    void reset()override;
    
    Entity getType()override{return DECOY;}
    
    virtual void receive(Message message, Object& other, Entity type)override;
    
    virtual void onNotify(Entity entity, Position pos)override;
    
    
private:
    Direction forcedDirection = NONE;

    void tryAwayFromTarget();
    
    bool dead = false;
    bool triggered = false;
    bool targeting = false;
    
    int dying = 0;
    int forcedSpeed = 0;
    
    Direction lastDirection;
    Position target;
    
};


#endif /* DecoyPhysicsComponent_hpp */
