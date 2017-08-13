//
//  GamestateComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 14/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef GamestateComponent_hpp
#define GamestateComponent_hpp

#include <vector>
#include "Component.hpp"
#include "gamestate.h"

class GamestateComponent: public Component{
public:
    GamestateComponent(Gamestate& gamestate): gamestate(gamestate){}
    
    virtual ~GamestateComponent(){}
    virtual void update(float dt)override;
    virtual void reset()override;

    virtual void onNotify(Event event)override{};
    virtual void onNotify(Event event, Entity entity)override;
    
private:
    Gamestate& gamestate;
    int numActiveMonsters = 10;
    
};

#endif /* GamestateComponent_hpp */
