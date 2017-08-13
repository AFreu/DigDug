//
//  FireFactory.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 23/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "FireFactory.hpp"
#include "FireGraphicsComponent.hpp"
#include "FirePhysicsComponent.hpp"

#include "GamestateRenderComponent.hpp"

FireFactory:: FireFactory(AvancezLib& lib){
    Sprite * sFire = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/spread_fire.png");
    Sprite * sFire2 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/spread_fire2.png");
    Sprite * sFire3 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/spread_fire3.png");
    Sprite * fire = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fire.png");
    Sprite * fire2 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/fire2.png");
    
    
    
    sprites.push_back(sFire);
    sprites.push_back(sFire2);
    sprites.push_back(fire);
    sprites.push_back(sFire3);
    sprites.push_back(fire2);

}

void  FireFactory:: produce(int quantity)
{
    for(int i = 0; i < quantity; i++)
    {
        Factory::produce();
        physicsComponents.push_back(std::make_shared<FirePhysicsComponent>(objects.at(i)));
        graphicsComponents.push_back(std::make_shared<FireGraphicsComponent>(objects.at(i), sprites));
    }
}