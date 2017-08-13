//
//  PlayerFactory.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 10/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//


#include "PlayerFactory.hpp"
#include "PlayerInputComponent.hpp"
#include "PlayerPhysicsComponent.hpp"
#include "PlayerGraphicsComponent.hpp"

#include "GamestateRenderComponent.hpp"

PlayerFactory:: PlayerFactory(AvancezLib& lib)
{
    
    Sprite * left = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/digdug_right.png");
    Sprite * down = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/digdug_down.png");
    Sprite * crushedR = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/digdug_crushed_right.png");
    Sprite * crushedU = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/digdug_crushed_up.png");
    Sprite * killedL = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/digdug_death.png");
    Sprite * killedD = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/digdug_death_down.png");
    Sprite * pumpR = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pump_right.png");
    Sprite * pumpD = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pump_down.png");
    
    sprites.push_back(left);
    sprites.push_back(down);
    sprites.push_back(crushedR);
    sprites.push_back(crushedU);
    sprites.push_back(killedL);
    sprites.push_back(killedD);
    sprites.push_back(pumpR);
    sprites.push_back(pumpD);
}


void  PlayerFactory:: produce(int quantity)
{
    for(int i = 0; i < quantity; i++)
    {
        Factory::produce();
        physicsComponents.push_back(std::make_shared<PlayerPhysicsComponent>(objects.at(i)));
        graphicsComponents.push_back(std::make_shared<PlayerGraphicsComponent>(objects.at(i), sprites));
    }
    
}
