//
//  ScoreController.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 07/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef ScoreComponent_hpp
#define ScoreComponent_hpp

#include <vector>

#include "Component.hpp"
#include "AvancezLib.hpp"
#include "Tunnels.hpp"
#include "ScoreRenderComponent.hpp"

static const int TUNNEL_WORTH = 10;

class ScoreComponent: public Component{
public:
    ScoreComponent(AvancezLib& lib, std::shared_ptr<Tunnels>& tunnels);
    
    void update(float dt)override;
    void reset()override;
    
    
    virtual void onNotify(Event event)override;
    virtual void onNotify(Event event, int value)override;
    virtual void onNotify(Event event, Position pos)override;
    virtual void onNotify(Event event, Position pos, int value)override;
    
    
    
private:
    void destroy();
    
    AvancezLib& lib;
    
    int calculateScore(Event event, Position pos, int value);
    int choseIndex(int score);
    int getActive();
    
    std::shared_ptr<Tunnels>& tunnels;
    
    std::vector<std::shared_ptr<ScoreRenderComponent>> scoreRenderComponents;
    std::vector<Sprite*> sprites;
    
    int level = 0;
    int firstActive = 0;
    int newScore = 0;
    int totalScore = 0;
    unsigned long numOfTunnels = 0;
    
};

#endif /* ScoreController_hpp */
