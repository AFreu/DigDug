//
//  Tunnels.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 02/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Tunnels_hpp
#define Tunnels_hpp


#include <iostream>
#include <stdio.h>
#include "position.h"
#include <vector>
#include <set>

const int TUNNEL_SIZE = 32;

class Tunnels{
public:
    Tunnels(std::set<Position> positions): tunnels(positions){std::cout << "Tunnels created...";}
    void addTunnel(Position pos);
    void addTunnel(Position pos, Direction dir, int length);
    bool insideTunnel(Position pos);
    bool insideTunnel(int x, int y);
    std::set<Position> getTunnelPositions();
    unsigned long getSize();
    void clear();
private:
    std::set<Position> tunnels;
    
};

#endif /* Tunnels_hpp */
