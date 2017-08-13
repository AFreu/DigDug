//
//  GamestateComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 14/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "GamestateComponent.hpp"
#include "gamestate.h"



void GamestateComponent:: update(float dt)
{
    if(dt <= 0) return;
    
    if(numActiveMonsters <= 0)
    {
        notify(LEVEL_UP);
        gamestate.level++; //Careful
    }
    
    notify(LEVEL_UP, gamestate.level);
    
    if(numActiveMonsters == 1)
    {
        notify(LAST_MONSTER);
        
        Position pos;
        pos.setxy(-3*OBJECT_SIZE, HEIGHT_OFFSET);
        notify(LAST_MONSTER, pos);
    }
    
    numActiveMonsters = 0;
}

void GamestateComponent:: onNotify(Event event, Entity entity)
{
    if(event == DEACTIVATED && entity == PLAYER) gamestate.lives--;
    if(event == ACTIVE && entity == MONSTER) numActiveMonsters++;
}

void GamestateComponent:: reset()
{
    
}
