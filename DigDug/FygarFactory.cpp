//
//  FygarFactory.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 13/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "FygarFactory.hpp"
#include "MonsterGraphicsComponent.hpp"
#include "FygarPhysicsComponent.hpp"

#include "GamestateRenderComponent.hpp"


FygarFactory:: FygarFactory(AvancezLib& lib){
    int size = 24;
    
    Sprite * fGhost = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fygar_ghost.png");
    Sprite * fLeft = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fygar.png");
    Sprite * fStun = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fygar_stun.png");
    Sprite * fCrushed = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fygar_crushed.png");
    Sprite * fI = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fygar_inflate1.png", size);
    Sprite * fIn = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fygar_inflate2.png", size);
    Sprite * fInf = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fygar_inflate3.png", size);
    
    sprites.push_back(fLeft);
    sprites.push_back(fGhost);
    sprites.push_back(fCrushed);
    sprites.push_back(fStun);
    sprites.push_back(fI);
    sprites.push_back(fIn);
    sprites.push_back(fInf);
    
}

void FygarFactory:: produce(int quantity)
{
    
    for(int i = 0; i < quantity; i++)
    {
        Factory::produce();
        physicsComponents.push_back(std::make_shared<FygarPhysicsComponent>(objects.at(i)));
        graphicsComponents.push_back(std::make_shared<MonsterGraphicsComponent>(objects.at(i), sprites));
        
    }
}

