//
//  PlayerGraphicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef PlayerGraphicsComponent_hpp
#define PlayerGraphicsComponent_hpp

#include <vector>
#include "EntityRenderComponent.hpp"


class PlayerGraphicsComponent : public EntityRenderComponent{
public:
    PlayerGraphicsComponent(Object* obj, std::vector<Sprite*> sprites) : EntityRenderComponent(obj,sprites){}
    
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
};

#endif /* PlayerGraphicsComponent_hpp */
