//
//  CollisionComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 09/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef CollisionComponent_hpp
#define CollisionComponent_hpp

#include <vector>
#include "EntityBehaviourComponent.hpp"
#include "Physics.hpp"

class CollisionComponent: public Component{
public:
    CollisionComponent(std::vector<std::shared_ptr<EntityBehaviourComponent>>& components): components(components){}
    
    virtual ~CollisionComponent(){}
    virtual void update(float dt)override;
    virtual void reset()override;
    
    virtual void onNotify(Event event)override{}
    
private:
    std::vector<std::shared_ptr<EntityBehaviourComponent>>& components;
};

#endif /* CollisionComponent_hpp */
