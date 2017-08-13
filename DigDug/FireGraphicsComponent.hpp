//
//  FireGraphicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 17/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef FireGraphicsComponent_hpp
#define FireGraphicsComponent_hpp

#include <vector>
#include "EntityRenderComponent.hpp"

class FireGraphicsComponent : public EntityRenderComponent{
public:
    FireGraphicsComponent(Object* obj, std::vector<Sprite*> sprites) : EntityRenderComponent(obj,sprites){}
    void update(float dt)override;
    void reset()override;
    void onNotify(Event event)override;
    
    
private:
    Position start;
    int length = 0;
    int tailSprite = 0;
    int tailOffsetY = 0;
    int tailOffsetX = 0;
};

#endif /* FireGraphicsComponent_hpp */
