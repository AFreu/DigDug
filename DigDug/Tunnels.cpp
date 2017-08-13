//
//  Tunnels.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 02/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "Tunnels.hpp"

void Tunnels:: addTunnel(Position pos)
{
    tunnels.insert(pos);
}

void Tunnels:: addTunnel(Position pos, Direction dir, int length)
{
    addTunnel(pos);
    
    for(int i = 0; i < 4*length; i++)
    {
        switch(dir)
        {
            case UP:
                pos.y -= TUNNEL_SIZE/4;
                break;
            case DOWN:
                pos.y += TUNNEL_SIZE/4;
                break;
            case LEFT:
                pos.x -= TUNNEL_SIZE/4;
                break;
            case RIGHT:
                pos.x += TUNNEL_SIZE/4;
            case NONE:
                break;
        }

        addTunnel(pos);
    }
}

//bool Tunnels:: insideTunnel(Position pos)
//{
//    bool ulc = false;
//    bool brc = false;
//    for(Position p : tunnels){
//        if(pos.x >= p.x && pos.x < p.x + TUNNEL_SIZE && pos.y >= p.y && pos.y < p.y + TUNNEL_SIZE) ulc = true;
//        if(pos.x + TUNNEL_SIZE > p.x && pos.x + TUNNEL_SIZE <= p.x + TUNNEL_SIZE && pos.y + TUNNEL_SIZE > p.y && pos.y + TUNNEL_SIZE <= p.y + TUNNEL_SIZE) brc = true;
//        if(ulc && brc) return true;
//    }
//    return ulc && brc;
//}

bool Tunnels:: insideTunnel(int x, int y)
{
    bool ulc = false;
    bool brc = false;
    
    if(x % 32 == 0){
        for(Position p : tunnels){
            if(x == p.x && y == p.y) return true;
            if(x == p.x && y >= p.y && y < p.y + 16) ulc = true;
            if(x == p.x && y < p.y && y >= p.y - 16) brc = true;
        }
    }
    if(y % 32 == 0){
        for(Position p : tunnels){
            if(x == p.x && y == p.y) return true;
            if(y == p.y && x >= p.x && x < p.x + 16) ulc = true;
            if(y == p.y && x < p.x && x >= p.x - 16) brc = true;
        }
    }
    
    
    
    
    //bool inside = false;
    /*for(Position p : tunnels){
        if(x >= p.x + 10 && x < p.x + TUNNEL_SIZE - 10 && y >= p.y + 15 && y < p.y + TUNNEL_SIZE - 15) return true;
        
        
        if(x >= p.x + 15 && x < p.x + TUNNEL_SIZE - 15 && y >= p.y + 10 && y < p.y + TUNNEL_SIZE - 10) return true;
    }
    
    return false;*/
    
    
    
    /*int rhsx = x + 4 ;
    int rhsxo = x + 32 - 4;
    int rhsy = y + 4;
    int rhsyo = y + 32 - 4;
    
    for(Position p : tunnels){
        
        int lhsx = p.x + 4;
        int lhsxo = p.x + 32 - 4;
        int lhsy = p.y + 4;
        int lhsyo = p.y + 32 - 4;
        
        if(rhsx < lhsxo && rhsxo > lhsx && rhsy < lhsyo && rhsyo > lhsy) return true;

        
    }
    
    
    return false;*/
    return ulc && brc;
    }

std::set<Position> Tunnels:: getTunnelPositions()
{
    return tunnels;
}

unsigned long Tunnels:: getSize()
{
    return tunnels.size();
}

void Tunnels:: clear()
{
    if(getSize() > 0) tunnels.clear();
    
}
