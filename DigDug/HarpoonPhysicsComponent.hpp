//
//  HarpoonPhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 28/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef HarpoonPhysicsComponent_hpp
#define HarpoonPhysicsComponent_hpp

#include "EntityBehaviourComponent.hpp"

const int MAX_LENGTH = 3;

class HarpoonPhysicsComponent : public EntityBehaviourComponent{
public:
    HarpoonPhysicsComponent(Object* obj):EntityBehaviourComponent(obj){}
    void update(float dt)override;
    void reset()override;
    Entity getType()override{return HARPOON;}
    
    virtual void receive(Message message, Object& other, Entity type)override;
    void onNotify(Position pos, Direction dir, bool inUse)override;
    
private:
    void updateLength(Position pos, Direction dir);
    
    bool connected = false;
    
    int length = 0;
    int counter = 0;
    int timer = 0;
};
#endif /* HarpoonPhysicsComponent_hpp */
