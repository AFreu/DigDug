//
//  EntityBehaviourComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef EntityBehaviourComponent_hpp
#define EntityBehaviourComponent_hpp

//#include "Physics.hpp"
#include "Component.hpp"
#include "User.hpp"


enum Message {
    COLLISION,
    CAN_MOVE,
    INSIDE_TUNNEL,
};

class EntityBehaviourComponent : public Component, public Usable, public User
{
public:
    EntityBehaviourComponent(Object* obj): obj(obj){}
    virtual ~EntityBehaviourComponent(){}
    virtual void update(float dt) = 0;
    virtual void reset()
    {
        obj->reset();
    };
    
    virtual void onNotify(Event event){}
    
    
    virtual Entity getType() = 0;
    
    Object& getObject()
    {
        return *obj;
    }
    
    virtual void receive(Message message){
        if(message == CAN_MOVE) canMove = true;
    }
    virtual void receive(Message message, Object& other, Entity type){}
    
protected:
    bool canMove = false;
    Object * obj;
};


#endif /* BehaviourComponent_hpp */
