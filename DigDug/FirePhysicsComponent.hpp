//
//  FirePhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 17/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef FirePhysicsComponent_hpp
#define FirePhysicsComponent_hpp

#include "EntityBehaviourComponent.hpp"


class FirePhysicsComponent : public EntityBehaviourComponent{
public:
    FirePhysicsComponent(Object* obj):EntityBehaviourComponent(obj){}
    void update(float dt)override;
    void reset()override;
    Entity getType()override{return FIRE;}
    
private:
    void updateLength(Position pos, Direction dir);
    
    
    int lastLength = 0;
    int length = 0;
    int counter = 0;
};

#endif /* FirePhysicsComponent_hpp */
