//
//  object.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 23/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef object_hpp
#define object_hpp

class InputComponent;
class PhysicsComponent;
class EntityRenderComponent;
class ScoreComponent;

#include "position.h"

static const int OBJECT_SIZE = 32;
static const int COLLISION_MARGIN = 4;
static const int DEPTH_ONE = 4;
static const int DEPTH_TWO = 8;
static const int DEPTH_THREE = 12;
const static float SPEED = 0.18f; //Used when the update loop is not delayed
const static float SLEEP_SPEED = 0.06f; //Used when the update loop is delayed

class Object{
public:
    Object(){}
    ~Object(){}
    
    void activate();
    void deactivate();
    bool isActive();
    bool equal(Object& obj); //TODO
    
    Position getPosition();
    Position closestTile(Position position);
    Direction getDirection();
    Direction getOppositeDirection();
    Direction decideDirection(Position position, Direction direction);
    
    int getSpeed();
    
    void setPosition(Position position);
    void setDirection(Direction direction);
    void setSpeed(int speed);
    void switchDirection();
    void setStartValues(Position pos, Direction dir, int speed);
    
    void movepx(int px, Direction direction);
    void move(float dt);
    void move(float dt, Direction direction);
    void move(float dt, Direction direction, int speed);
    
    void reset();
    
private:
    bool active = false;
    Position pos;
    Position startPos;
    Direction dir;
    Direction startDir;
    int speed = 0;
    int startSpeed;
};

#endif /* object_hpp */
