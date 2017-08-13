//
//  Physics.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 13/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Physics_hpp
#define Physics_hpp

#include "object.hpp"

class Physics
{
public:
    static bool collision(Object rhs, Object lhs);
    static bool insideGameArea(Object obj);
    static bool insideGameArea(Position pos);
    static bool onTile(Position pos);
};


#endif /* Physics_hpp */
