//
//  EntityRenderComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef EntityRenderComponent_hpp
#define EntityRenderComponent_hpp

#include <vector>
#include "Component.hpp"
#include "Sprite.hpp"


class EntityRenderComponent : public Component
{
public:
    EntityRenderComponent(Object* obj, std::vector<Sprite*> sprites): obj(obj), sprites(sprites){}
    virtual ~EntityRenderComponent(){}
    virtual void update(float dt) = 0;
    virtual void reset()=0;
    virtual void onNotify(Event event) = 0;
protected:
    Object * obj;
    std::vector<Sprite *> sprites;
    
    Flip lastFlip = NO;
    
    int lastSprite = 0;
    int counter = 0;
};

#endif /* GraphicsComponent_hpp */
