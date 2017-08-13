//
//  object.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 23/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "object.hpp"

bool Object:: isActive()
{
    return active;
}

void Object:: activate()
{
    active = true;
}

void Object:: deactivate()
{
    active = false;
}

Position Object:: getPosition()
{
    return pos;
}

Direction Object:: getDirection()
{
    return dir;
}

Direction Object:: getOppositeDirection()
{
    
    Direction opposite = NONE;
    switch(dir)
    {
        case UP:
            opposite = DOWN;
            break;
        case DOWN:
            opposite = UP;
            break;
        case LEFT:
            opposite = RIGHT;
            break;
        case RIGHT:
            opposite = LEFT;
            break;
        case NONE:
            break;
    
    }
    return opposite;
   
}

void Object:: setStartValues(Position pos, Direction dir, int speed)
{
    /* Save start values */
    startPos = pos;
    startDir = dir;
    startSpeed = speed;
    
    /* Initiate start values */
    setPosition(pos);
    setDirection(dir);
    setSpeed(speed);
}

void Object:: switchDirection()
{
    switch(getDirection())
    {
        case UP:
            setDirection(LEFT);
            break;
        case DOWN:
            setDirection(RIGHT);
            break;
        case LEFT:
            setDirection(DOWN);
            break;
        case RIGHT:
            setDirection(UP);
            break;
        case NONE:
            break;
    }
}

int Object:: getSpeed()
{
    return speed;
}


void Object:: setDirection(Direction direction)
{
    dir = direction;
}

void Object:: setPosition(Position position)
{
    pos.setxy(position.x, position.y);
}

void Object:: setSpeed(int speed)
{
    this->speed = speed;
}

void Object:: move(float dt)
{
    move(dt, getDirection());
    
}
void Object:: move(float dt, Direction direction)
{
    move(dt, direction, getSpeed());
}

void Object:: move(float dt, Direction direction, int speed){
    /* Have to change parameter if the loop is not delayed */
    int distance = dt*speed*SLEEP_SPEED;
    
    switch(direction)
    {
        case LEFT:
            pos.x-= distance;
            break;
        case RIGHT:
            pos.x+= distance;
            break;
        case UP:
            pos.y-= distance;
            break;
        case DOWN:
            pos.y+= distance;
            break;
        case NONE:
            break;
    }
}

void Object:: movepx(int px, Direction dir)
{
    switch(dir)
    {
        case LEFT:
            pos.x-= px;
            break;
        case RIGHT:
            pos.x+= px;
            break;
        case UP:
            pos.y-= px;
            break;
        case DOWN:
            pos.y+= px;
            break;
        case NONE:
            break;
    }
}

/*
 Gives the direction towards the given position
 Will not return opposite direction
 */
Direction Object:: decideDirection(Position pos, Direction dir)
{
    if(getPosition() == pos) return NONE;
    switch(dir)
    {
        case UP:
        case DOWN:
            if(getPosition().x > pos.x) return LEFT;
            return RIGHT;
            break;
        case LEFT:
        case RIGHT:
            if(getPosition().y > pos.y) return UP;
            return DOWN;
            break;
        case NONE:
            return NONE;
            break;
    }
}

Position Object:: closestTile(Position pos)
{
    Position position;
    int distX = pos.x % OBJECT_SIZE;
    int distY = pos.y % OBJECT_SIZE;
    
    Position posL;
    posL.setxy(pos.x - distX, pos.y);
    Position posR;
    posR.setxy(pos.x + (OBJECT_SIZE - distX), pos.y);
    Position posU;
    posU.setxy(pos.x, pos.y - distY);
    Position posD;
    posD.setxy(pos.x, pos.y + (OBJECT_SIZE - distY));
    
    switch(dir)
    {
        case UP:
        case DOWN:
            if(distX < OBJECT_SIZE/2) position = posL;
            else position = posR;
            break;
        case LEFT:
        case RIGHT:
            if(distY < OBJECT_SIZE/2) position = posU;
            else position = posD;
            break;
        case NONE:
            position = pos;
            break;
    }
    
    return position;
}

bool Object:: equal(Object& obj){
    return false; //TODO
}

void Object:: reset()
{
    setPosition(startPos);
    setDirection(startDir);
    setSpeed(startSpeed);
}


