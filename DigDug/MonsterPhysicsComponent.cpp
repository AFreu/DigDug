//
//  MonsterPhysicsComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 02/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "MonsterPhysicsComponent.hpp"

void MonsterPhysicsComponent:: update(float dt)
{
    if(!obj->isActive()) return;
    notify(ACTIVE, MONSTER);
    
    this->dt = dt;
    updateUsables(obj->getPosition(), obj->getDirection(), false);
    
    //Something could be forcing the monster to move in a certain direction.
    if(forcedDirection != NONE) obj->move(dt, forcedDirection, forcedSpeed);
    
    //Stun and inflate the monster depending on harpooned-duration
    if(harpooned) harpoonedFor++;
    handleHarpooned();
    
    //Wait a second before deactivating the monster
    if(dead) diedFor++;
    if(diedFor == 60 || (lastMonster && obj->getPosition() == targetPosition))
    {
        obj->deactivate();
        diedFor = 0;
        notify(DEACTIVATED);
        notify(DEACTIVATED, MONSTER);
        if(exploaded) notify(EXPLOAD, obj->getPosition());
    }
    
    //Deflate the monster when not harpooned any more
    if(!dead && !harpooned && stunned) harpoonedFor--;
    
    //Become a ghost depending on anger
    if(anger >= 30) ghost = true;
    
    //Handle ghost state
    if(!dead && !stunned && ghost && !performingSpecial) ghostBehaviour();
    
    //Handle normal state
    if(!dead && !stunned && !ghost) chasePlayer();
    
    //Assume things for next update
    forcedDirection = NONE;
    forcedSpeed = 0;
    harpooned = false;
    canMove = false;
    scared = false;
    insideTunnel = false;
    lastMonster = false;
}

Entity MonsterPhysicsComponent:: getType()
{
    if(stunned) return STUNNED_MONSTER;
    if(ghost) return GHOST_MONSTER;
    return MONSTER;
}

void MonsterPhysicsComponent:: reset()
{
     updateUsables(false);
     dead = false;
     ghost = false;
     stunned = false;
     exploaded = false;
     harpooned = false;
     hunting = false;
     scared = false;
     performingSpecial = false;
     insideTunnel = false;
     lastMonster = false;
    
     diedFor = 0;
     anger = 0;
     ghostSpeed = 1;
     forcedSpeed = 0;
     harpoonedFor = 0;
    
     forcedDirection = NONE;
     EntityBehaviourComponent::reset();
}

void MonsterPhysicsComponent:: receive(Message message)
{
    if(!obj->isActive()) return;
    if(message == INSIDE_TUNNEL) insideTunnel = true;
    if(message == CAN_MOVE) canMove = true;
}


void MonsterPhysicsComponent:: receive(Message message, Object &other, Entity type)
{
    if(!obj->isActive()) return;
    if(message == COLLISION){
        switch(type)
        {
        case ROCK:
                if(ghost) break;
        case FALLING_ROCK:
            notify(CRUSHED);
            dead = true;
            forcedSpeed = other.getSpeed();
            forcedDirection = other.getDirection();
            break;
        case HARPOON:
            harpooned = true;
            stunned = true;
            break;
        default:
            break;
        }
    }

}

void MonsterPhysicsComponent:: onNotify(Event event, Entity entity, Position pos)
{
    if(!obj->isActive()) return;
    if(event == FALLING && entity == ROCK) {
        targetPosition = pos;
        scared = true;
    }
}

void MonsterPhysicsComponent:: onNotify(Entity entity, Position pos)
{
    if(!obj->isActive()) return;
    if(entity == PLAYER && !lastMonster){
        targetPosition = pos;
    }
    
}

void MonsterPhysicsComponent:: onNotify(Event event, Position pos)
{
    if(event == LAST_MONSTER)
    {
        lastMonster = true;
        targetPosition = pos;
    }
}

void MonsterPhysicsComponent:: handleHarpooned()
{
    
    if(harpoonedFor > 90)
    {
        if(!exploaded) notify(EXPLOAD);
        exploaded = true;
        dead = true;
    }
    else if(harpoonedFor > 60)
    {
        notify(INFLATED);
    }
    else if(harpoonedFor > 30)
    {
        notify(INFLATE);
    }
    else if (harpoonedFor > 0)
    {
        notify(DEFLATE);
        notify(STUNNED);
    }else if (harpoonedFor == 0)
    {
        notify(NOT_STUNNED);
        stunned = false;
    }
}

void MonsterPhysicsComponent:: ghostBehaviour()
{
    notify(GHOST);
    anger -= 4;
    if((anger < 0) && insideTunnel)
    {
        ghost = false;
        anger = 0;
        notify(NOT_GHOST);
        return;
    }
    
    if(canMove) obj->move(dt);

    Position mpos = obj->getPosition();
    Position ppos = targetPosition;
    
    int distX = abs(mpos.x - ppos.x);
    int distY = abs(mpos.y - ppos.y);
    
    if(mpos.x < ppos.x) if(distX > distY) obj->setDirection(RIGHT);
    if(mpos.x > ppos.x) if(distX > distY) obj->setDirection(LEFT);
    if(mpos.y < ppos.y) if(distY > distX) obj->setDirection(DOWN);
    if(mpos.y > ppos.y) if(distY > distX) obj->setDirection(UP);
}

void MonsterPhysicsComponent:: chasePlayer()
{
    
    bool moved = false;
    
    
    if(!performingSpecial){
        //Continue ahead
        if(canMove) {obj->move(dt); moved = true; lastDirection = obj->getDirection();}
        if(!canMove){
            if(hunting){
                obj->setDirection(lastDirection); hunting = false;
            }else{
                obj->switchDirection();

            }
        }
        if(!scared && moved && (obj->getPosition().x % OBJECT_SIZE == 0) && (obj->getPosition().y % OBJECT_SIZE == 0)) tryTowardsTarget();
        
        if(scared && headingTowardsTarget()){
            obj->setDirection(obj->getOppositeDirection());
        }

    }else{
        moved = true;
    }
    
    performingSpecial = specialBehaviour();
    
    
    if(!moved) { anger++;}

    
}

void MonsterPhysicsComponent:: tryTowardsTarget()
{
    hunting = true;
    lastDirection = obj->getDirection();
    
    switch(obj->getDirection())
    {
        case UP:
        case DOWN:
            if(obj->
               getPosition().x == targetPosition.x) break;
            if(obj->getPosition().x > targetPosition.x) obj->setDirection(LEFT); else obj->setDirection(RIGHT);
            break;
        case RIGHT:
        case LEFT:
            if(obj->getPosition().y == targetPosition.y) break;
            if(obj->getPosition().y > targetPosition.y) obj->setDirection(UP); else obj->setDirection(DOWN);
            break;
        case NONE:
            break;
    }
}

bool MonsterPhysicsComponent:: headingTowardsTarget()
{
    if(obj->getPosition().distance(targetPosition) > OBJECT_SIZE * 5) return false;
    
    bool headingTowardsTarget = false;
    switch(obj->getDirection())
    {
        case UP:
            if(obj->getPosition().y >= targetPosition.y)  headingTowardsTarget = true;
            break;
        case DOWN:
            if(obj->getPosition().y <= targetPosition.y)  headingTowardsTarget = true;
            break;
        case RIGHT:
            if(obj->getPosition().x <= targetPosition.x) headingTowardsTarget = true;
            break;
        case LEFT:
            if(obj->getPosition().x >= targetPosition.x) headingTowardsTarget = true;
            break;
        case NONE:
            break;
    }
    
    return headingTowardsTarget;
}

bool MonsterPhysicsComponent:: specialBehaviour(){
    
    return false;
}

