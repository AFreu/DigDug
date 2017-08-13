//
//  HarpoonFactory.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 11/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "HarpoonFactory.hpp"
#include "HarpoonGraphicsComponent.hpp"
#include "HarpoonPhysicsComponent.hpp"

#include "GamestateRenderComponent.hpp"

HarpoonFactory:: HarpoonFactory(AvancezLib& lib){
    Sprite * hDown = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/harpoon_down.png");
    Sprite * hLeft = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/harpoon_left.png");
    Sprite * hoseDown = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/hose_down.png");
    Sprite * hoseLeft = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/hose_left.png");
    
    sprites.push_back(hLeft);
    sprites.push_back(hDown);
    sprites.push_back(hoseLeft);
    sprites.push_back(hoseDown);
}

void  HarpoonFactory:: produce(int quantity)
{
    for(int i = 0; i < quantity; i++)
    {
        Factory::produce();
        physicsComponents.push_back(std::make_shared<HarpoonPhysicsComponent>(objects.at(i)));
        graphicsComponents.push_back(std::make_shared<HarpoonGraphicsComponent>(objects.at(i), sprites));
    }
}
