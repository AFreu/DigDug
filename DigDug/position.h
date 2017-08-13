//
//  position.h
//  DigDug
//
//  Created by Anton Freudenthaler on 20/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef position_h
#define position_h

#include <cmath>
#include <stdlib.h>

const int GAME_WIDTH = 14*32;
const int GAME_HEIGHT = 16*32;
const int HEIGHT_OFFSET = 32;
const int WIDTH_OFFSET = 2*32;

enum Direction {RIGHT, LEFT, UP, DOWN, NONE};

class Position{
public:
    int x;
    int y;
    
    bool operator==(const Position& rhs) const
    {
        return  ( (x== rhs.x)&&(y == rhs.y) );
    }
    
    bool operator < (const Position& rhs) const
    {
        return ((x < rhs.x) || (y < rhs.y)); //Might need more proper evaluation
    }
    
    void setxy(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    int distance(Position pos)
    {
        int distance = 0;
        distance = sqrt((x-pos.x)*(x-pos.x) + (y-pos.y)*(y-pos.y));
        return distance;
    }
    
    
};


#endif /* position_h */
