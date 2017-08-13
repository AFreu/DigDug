//
//  DigDug.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 27/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef DigDug_hpp
#define DigDug_hpp

#include <iostream>
#include <string>
#include <fstream>

#include "AvancezLib.hpp"

#include "gamestate.h"

#include "Level.hpp"

static const int MAX_LEVEL = 4;


class DigDug {
public:

    DigDug(AvancezLib& lib);
    
    void init();
    void reset();
    
    bool update();
    void destroy();
    
    std::string getResult();
    
private:
    void updateComponents();
    bool handleGamestate();

    int lastTime = 0;
    int elapsed = 0;
    
    AvancezLib& lib;
    
    Level * level;
    
    Gamestate gamestate;
    Gamestate lastState;
    
    std::vector<std::shared_ptr<Component>> components;
};

#endif /* DigDug_hpp */
