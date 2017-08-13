//
//  PhysicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 13/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "PhysicsComponent.hpp"

void PhysicsComponent:: update(float dt)
{
    if(dt <= 0) return;
    
    unsigned long size = components.size();
    
    for(int i = 0; i < size; i++)
    {
        Entity type = components.at(i)->getType();
        
        if(canMove(i, dt))
        {
            components.at(i)->receive(CAN_MOVE);
        }
        
        if(type == GHOST_MONSTER){
            if(insideTunnel(components.at(i)->getObject().getPosition()))
            {
                components.at(i)->receive(INSIDE_TUNNEL);
            }
        }
        
        if(type == PLAYER)
        {
            makeTunnel(components.at(i)->getObject().getPosition());

        }
    }
}

void PhysicsComponent:: reset()
{
    lastMonster = false;
}

void PhysicsComponent:: onNotify(Event event)
{
    if(event == LAST_MONSTER) lastMonster = true;
}



bool PhysicsComponent:: canMove(int index, float dt)
{
    Entity type = components.at(index)->getType();
    Object obj = components.at(index)->getObject();
    Direction direction = components.at(index)->getObject().getDirection();
    
    
    bool canMove = true;
    if(type == GHOST_MONSTER) return true;
    
    if(type == ROCK){
        obj.movepx(32, DOWN);
    }
    else{
        obj.move(dt, direction);
    }
    
    if(!Physics::insideGameArea(obj))   canMove = false;
    
    
    if(!Physics::onTile(obj.getPosition()))     canMove = false;
    
    
    if(type != PLAYER)
    {
        if(!insideTunnel(obj.getPosition()))    canMove = false;
    }
    
    if(!(type == GHOST_MONSTER  || type == FALLING_ROCK))
    {
        for(int i = 0; i < components.size(); i++)
        {
            Entity type = components.at(i)->getType();
            if(type == ROCK || type == FALLING_ROCK){
                if(Physics::collision(obj, components.at(i)->getObject())){
                    canMove = false;
                }
            }
        }
    }
    
    if(type == ROCK){
        obj.movepx(-32, DOWN);
    }
    else{
        obj.move(-dt, direction);
    }
    
    
    if((type == MONSTER && lastMonster && obj.getPosition().y == HEIGHT_OFFSET && obj.getPosition().x < GAME_WIDTH))  canMove = true;
    
    
    return canMove;
}

bool PhysicsComponent:: insideTunnel(Position pos)
{
    return Physics::onTile(pos) && tunnels->insideTunnel(pos.x, pos.y);
}

void PhysicsComponent:: makeTunnel(Position pos)
{
    if((pos.x % 2 == 0) && (pos.y % 2 == 0)) tunnels->addTunnel(pos);
}

