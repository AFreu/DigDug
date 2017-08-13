//
//  FygarPhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 16/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef FygarPhysicsComponent_hpp
#define FygarPhysicsComponent_hpp

static const int FIRE_BREATH_DURATION = 120;
static const int FIRE_BREATH_COOLDOWN = 600;


#include "MonsterPhysicsComponent.hpp"
class FygarPhysicsComponent : public MonsterPhysicsComponent{
public:
    FygarPhysicsComponent(Object* obj):MonsterPhysicsComponent(obj){}
private:
    virtual bool specialBehaviour()override;
    virtual void reset()override;

    int special = 0;
    int firing = 0;
    Direction currentDirection = NONE;
};


#endif /* FygarPhysicsComponent_hpp */
