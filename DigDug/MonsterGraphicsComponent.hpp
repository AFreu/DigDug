//
//  MonsterGraphicsComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 05/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef MonsterGraphicsComponent_hpp
#define MonsterGraphicsComponent_hpp

#include <vector>
#include "EntityRenderComponent.hpp"


class MonsterGraphicsComponent : public EntityRenderComponent{
public:
    MonsterGraphicsComponent(Object* obj, std::vector<Sprite*> sprites) : EntityRenderComponent(obj,sprites){}
    
    void update(float dt)override;
    void reset()override;
    void onNotify(Event event)override;
    
private:
        
    bool crushed = false;
    bool stunned = false;
    bool ghost = false;
    
    int inflate = -1;
    bool inflated = false;
    
    
    
};

#endif /* MonsterGraphicsComponent_hpp */
