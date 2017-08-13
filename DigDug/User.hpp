//
//  User.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 26/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <vector>
#include "Usable.hpp"

class User
{
public:
    public : void addUsable(const std::shared_ptr<Usable>& usable);
    public : void removeUsable(std::shared_ptr<Usable>& usable);
private:
    static int const MAX_USABLES = 5;
    std::shared_ptr<Usable> usables[MAX_USABLES];
    int numUsables = 0;
protected:
    virtual void updateUsables(Position pos, Direction dir, bool inUse);
    virtual void updateUsable(int index, Position pos, Direction dir, bool inUse);
    virtual void updateUsables(bool inUse);
};

#endif /* User_hpp */
