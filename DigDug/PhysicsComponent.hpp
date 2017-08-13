//
//  PhysicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 13/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef PhysicsComponent_hpp
#define PhysicsComponent_hpp

#include <vector>
#include "EntityBehaviourComponent.hpp"
#include "Tunnels.hpp"
#include "Physics.hpp"

class PhysicsComponent: public Component{
public:
    PhysicsComponent(std::vector<std::shared_ptr<EntityBehaviourComponent>>& components, std::shared_ptr<Tunnels>& tunnels): components(components), tunnels(tunnels){}
    
    virtual ~PhysicsComponent(){}
    virtual void update(float dt)override;
    virtual void reset()override;
    
    virtual void onNotify(Event event)override;
    
private:
    bool lastMonster = false;
    
    bool canMove(int index, float dt);
    bool insideTunnel(Position pos);
    void makeTunnel(Position pos);
    
    std::vector<std::shared_ptr<EntityBehaviourComponent>>& components;
    std::shared_ptr<Tunnels>& tunnels;
};

#endif /* PhysicsComponent_hpp */
