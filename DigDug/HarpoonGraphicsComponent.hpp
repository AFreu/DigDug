//
//  HarpoonGraphicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 26/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef HarpoonGraphicsComponent_hpp
#define HarpoonGraphicsComponent_hpp

#include <vector>
#include "EntityRenderComponent.hpp"

class HarpoonGraphicsComponent : public EntityRenderComponent{
public:
    HarpoonGraphicsComponent(Object* obj, std::vector<Sprite*> sprites) : EntityRenderComponent(obj,sprites){}
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
#endif /* HarpoonGraphicsComponent_hpp */
