//
//  Physics.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 13/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "Physics.hpp"



bool Physics:: collision(Object rhs, Object lhs)
{
    if(!rhs .isActive() || !lhs .isActive()) return false;
    
    int rhsx = rhs.getPosition().x + COLLISION_MARGIN;
    int rhsxo = rhs.getPosition().x + OBJECT_SIZE - COLLISION_MARGIN;
    int rhsy = rhs.getPosition().y + COLLISION_MARGIN;
    int rhsyo = rhs.getPosition().y + OBJECT_SIZE - COLLISION_MARGIN;
    
    int lhsx = lhs.getPosition().x + COLLISION_MARGIN;
    int lhsxo = lhs.getPosition().x + OBJECT_SIZE - COLLISION_MARGIN;
    int lhsy = lhs.getPosition().y + COLLISION_MARGIN;
    int lhsyo = lhs.getPosition().y + OBJECT_SIZE - COLLISION_MARGIN;
    
    
    
    return(rhsx < lhsxo
           
           && rhsxo > lhsx
           
           && rhsy < lhsyo
           
           && rhsyo > lhsy);
    
}

bool Physics:: insideGameArea(Object obj)
{
    return insideGameArea(obj.getPosition());
}

bool Physics:: insideGameArea(Position pos)
{
    bool inside = true;
    if(pos.x < WIDTH_OFFSET) inside = false;
    if(pos.y < HEIGHT_OFFSET) inside = false;
    if(pos.y + OBJECT_SIZE > GAME_HEIGHT+HEIGHT_OFFSET) inside = false;
    if(pos.x + OBJECT_SIZE > GAME_WIDTH+WIDTH_OFFSET) inside = false;
    return inside;
}

bool Physics:: onTile(Position pos)
{
    return ((pos.x + WIDTH_OFFSET) % OBJECT_SIZE == 0) || ((pos.y + HEIGHT_OFFSET) % OBJECT_SIZE == 0);
}




