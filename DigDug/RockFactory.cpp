   //
//  RockFactory.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 09/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "RockFactory.hpp"
#include "RockPhysicsComponent.hpp"
#include "RockGraphicsComponent.hpp"

#include "GamestateRenderComponent.hpp"

RockFactory:: RockFactory(AvancezLib& lib)
{
    Sprite * r = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/rock.png");
    
    sprites.push_back(r);
}

void RockFactory:: produce(int quantity)
{
    for(int i = 0; i < quantity; i++)
    {
        Factory::produce();
        physicsComponents.push_back(std::make_shared<RockPhysicsComponent>(objects.at(i)));
        graphicsComponents.push_back(std::make_shared<RockGraphicsComponent>(objects.at(i), sprites));
        
    }
}



