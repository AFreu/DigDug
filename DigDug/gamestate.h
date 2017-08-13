//
//  gamestate.h
//  DigDug
//
//  Created by Anton Freudenthaler on 08/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef gamestate_h
#define gamestate_h

struct Gamestate
{
    int lives = 3;
    int level = 1;
    void copy(Gamestate state)
    {
        lives = state.lives;
        level = state.level;
    }
};

#endif /* gamestate_h */
