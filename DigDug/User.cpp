//
//  User.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 26/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "User.hpp"
void User:: addUsable(const std::shared_ptr<Usable>& usable)
{
    for(int i = 0; i < numUsables; i++)
    {
        if(usables[i] == usable) return; //If observer already exists in the list do not add it
    }
    
    if(numUsables < MAX_USABLES)
    {
        usables[numUsables] = usable;
        numUsables++;
    }
}
void User:: removeUsable(std::shared_ptr<Usable>& usable)
{
    for(int i = 0; i < numUsables; i++)
    {
        if(usables[i] == usable)
        {
            numUsables--;
            usables[i] = usables[numUsables]; //Replace removed usable with the last usable in the list
            
        }
    }
}


void User:: updateUsables(Position pos, Direction dir, bool inUse)
{
    for (int i = 0; i < numUsables; i++)
    {
        usables[i]->onNotify(pos, dir, inUse);
    }
}

void User:: updateUsable(int index, Position pos, Direction dir, bool inUse)
{
    if(index >= numUsables) return;
    usables[index]->onNotify(pos, dir, inUse);
}

void User:: updateUsables(bool inUse)
{
    for (int i = 0; i < numUsables; i++)
    {
        usables[i]->onNotify(false);
    }
}
