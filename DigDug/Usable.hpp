//
//  Usable.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 26/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Usable_hpp
#define Usable_hpp

#include "position.h"

/*  A usable that is being used by a user.
    A usable constantly wants to know its users position and direction,
    and whether it is currently being used or not.
 */
class Usable
{
public:
    virtual ~Usable() {}
    virtual void onNotify(Position pos, Direction dir, bool inUse)
    {
        //Set usables direction & position to the users last direction & position
        if(dir != NONE) userDirection = dir;
        userPosition = pos;
        this->inUse = inUse;
    };
    virtual void onNotify(bool inUse)
    {
        this->inUse = inUse;
    }
protected:
    Position userPosition;
    Direction userDirection;
    bool inUse = false;
};

#endif /* Usable_hpp */
