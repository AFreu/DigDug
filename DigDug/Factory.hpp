//
//  Factory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 13/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//


#ifndef Factory_hpp
#define Factory_hpp

#include <vector>

#include "position.h"
#include "Sprite.hpp"
#include "AvancezLib.hpp"

class InputComponent;
class EntityRenderComponent;
class EntityBehaviourComponent;
class GamestateRenderComponent;
class Object;


class Factory{
public:
    Factory(){}
    virtual ~Factory(){}
    virtual void produce(int quantity) = 0;
    
    void destroy();
    void recycle();
    
    void create(std::shared_ptr<EntityBehaviourComponent>& physics, std::shared_ptr<EntityRenderComponent>& graphics, Position startPos, Direction startDirection, int startSpeed);
    
protected:
    virtual void produce();
    
    std::vector<Sprite * > sprites;
    std::vector<Object * > objects;
    std::vector<std::shared_ptr<EntityBehaviourComponent>> physicsComponents;
    std::vector<std::shared_ptr<EntityRenderComponent>> graphicsComponents;
private:
    int firstInactive();
};

#endif /* Factory_hpp */
