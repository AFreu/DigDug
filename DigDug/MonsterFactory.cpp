//
//  MonsterFactory.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 09/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "MonsterFactory.hpp"
#include "MonsterGraphicsComponent.hpp"
#include "MonsterPhysicsComponent.hpp"

#include "GamestateRenderComponent.hpp"

MonsterFactory:: MonsterFactory(AvancezLib& lib)
{
    
    int size = 24;
    
    Sprite * pGhost = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pookas_ghost.png");
    Sprite * pLeft = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pookas.png");
    Sprite * pStun = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pookas_stun.png");
    Sprite * pCrushed = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pookas_crushed.png");
    Sprite * pI = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pookas_inflate1.png", size);
    Sprite * pIn = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pookas_inflate2.png", size);
    Sprite * pInf = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/pookas_inflate3.png", size);
    
    sprites.push_back(pLeft);
    sprites.push_back(pGhost);
    sprites.push_back(pCrushed);
    sprites.push_back(pStun);
    sprites.push_back(pI);
    sprites.push_back(pIn);
    sprites.push_back(pInf);

}

void MonsterFactory:: produce(int quantity)
{
    
    for(int i = 0; i < 10; i++)
    {
        Factory::produce();
        physicsComponents.push_back(std::make_shared<MonsterPhysicsComponent>(objects.at(i)));
        graphicsComponents.push_back(std::make_shared<MonsterGraphicsComponent>(objects.at(i), sprites));
        
    }
}
