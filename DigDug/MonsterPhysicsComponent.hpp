//
//  MonsterPhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 02/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef MonsterPhysicsComponent_hpp
#define MonsterPhysicsComponent_hpp


#include "EntityBehaviourComponent.hpp"
class MonsterPhysicsComponent : public EntityBehaviourComponent{
public:
    MonsterPhysicsComponent(Object* obj):EntityBehaviourComponent(obj){}
    void update(float dt)override;
    virtual void reset()override;
    Entity getType()override;
    
    void receive(Message message)override;
    void receive(Message message, Object& other, Entity type)override;
    
    void onNotify(Entity entity, Position pos)override;
    void onNotify(Event event, Position pos)override;
    void onNotify(Event event, Entity entity, Position pos)override;
    
    
protected:
    virtual bool specialBehaviour();
    
    void tryTowardsTarget();
    bool headingTowardsTarget();
    void chasePlayer();
    void ghostBehaviour();
    void handleHarpooned();
    
    bool dead = false;
    bool ghost = false;
    bool stunned = false;
    bool exploaded = false;
    bool harpooned = false;
    bool hunting = false;
    bool scared = false;
    bool performingSpecial = false;
    bool insideTunnel = false;
    bool lastMonster = false;
    
    int dt = 0;
    
    int diedFor = 0;
    int anger = 0;
    int ghostSpeed = 1;
    int forcedSpeed = 0;
    int harpoonedFor = 0;
    
    
    
    Direction lastDirection = NONE;
    Direction forcedDirection = NONE;
    Position targetPosition;
};

#endif /* MonsterPhysicsComponent_hpp */
