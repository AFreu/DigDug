//
//  GamestateRenderComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 27/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef GamestateRenderComponent_hpp
#define GamestateRenderComponent_hpp

static const int WIDTH = 14;
static const int HEIGHT = 15;


#include "Component.hpp"
#include "gamestate.h"

#include "Sprite.hpp"
#include "Tunnels.hpp"
#include "object.hpp"
#include "AvancezLib.hpp"


class GamestateRenderComponent: public Component{
public:

    GamestateRenderComponent(AvancezLib& lib, std::shared_ptr<Tunnels>& tunnels, Gamestate& state);
    virtual ~GamestateRenderComponent(){}
    void update(float dt)override;
    void reset()override;
    void onNotify(Event event)override;
    
private:
    
    void destroy();
    
    void drawDirt(int width, int height);
    
    void draw(int score, Position pos);
    
    void drawTunnel(Position pos);
    
    void drawFlowers(int level);
    
    void drawLives(int lives);
    
    void drawControls();

    
    std::shared_ptr<Tunnels>& tunnels;
    Gamestate& gamestate;
    
    std::vector<Sprite *> sprites;
    
    int numberOfObjects = 0;
    

};

#endif /* GraphicsController_hpp */
