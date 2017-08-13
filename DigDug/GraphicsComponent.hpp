//
//  GraphicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef GraphicsComponent_hpp
#define GraphicsComponent_hpp

#include <vector>
#include "Component.hpp"
#include "Sprite.hpp"


class RenderComponent : public Component
{
public:
    GraphicsComponent(Object* obj, std::vector<Sprite*> sprites): obj(obj), sprites(sprites){}
    virtual ~GraphicsComponent(){}
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
