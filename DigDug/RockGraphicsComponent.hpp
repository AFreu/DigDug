//
//  RockGraphicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 30/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef RockGraphicsComponent_hpp
#define RockGraphicsComponent_hpp

#include "EntityRenderComponent.hpp"
class RockGraphicsComponent : public EntityRenderComponent{
public:
    RockGraphicsComponent(Object* obj, std::vector<Sprite*> sprites) : EntityRenderComponent(obj, sprites){}
    void update(float dt)override;
    void reset()override;
    void onNotify(Event event)override;
    void onNotify(Event event, Entity entity)override;
    
private:
    bool destroyed = false;
    bool falling = false;
    int lastElapsed = 0;
    int fallingFor = 0;
    
};

#endif /* RockGraphicsComponent_hpp */
