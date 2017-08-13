//
//  DecoyGraphicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 01/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef DecoyGraphicsComponent_hpp
#define DecoyGraphicsComponent_hpp

#include <vector>
#include "EntityRenderComponent.hpp"


class DecoyGraphicsComponent : public EntityRenderComponent{
public:
    DecoyGraphicsComponent(Object* obj, std::vector<Sprite*> sprites) : EntityRenderComponent(obj,sprites){}
    
    void update(float dt)override;
    void reset()override;
    
    void onNotify(Event event)override;
    
private:
    void renderCrushed();
    void renderKilled();
    void renderHarpooning();
    void renderNormal();
    
    bool crushed = false;
    bool killed = false;
    bool harpooning = false;
    
    int numOfFrames = 0;
    
    Direction dir = NONE;
    
};
#endif /* DecoyGraphicsComponent_hpp */
