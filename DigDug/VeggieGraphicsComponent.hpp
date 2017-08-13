//
//  VeggieGraphicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 20/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef VeggieGraphicsComponent_hpp
#define VeggieGraphicsComponent_hpp

#include <vector>
#include "EntityRenderComponent.hpp"

class VeggieGraphicsComponent : public EntityRenderComponent{
public:
    VeggieGraphicsComponent(Object* obj, std::vector<Sprite*> sprites) : EntityRenderComponent(obj,sprites){}
    
    void update(float dt)override;
    void reset()override;
    void onNotify(Event event)override;
    void onNotify(Event event, int value)override;
    
private:
    int level = 1;
};


#endif /* VeggieGraphicsComponent_hpp */
