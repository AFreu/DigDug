//
//  VeggieFactory.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 20/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "VeggieFactory.hpp"

#include "VeggiePhysicsComponent.hpp"
#include "VeggieGraphicsComponent.hpp"

#include "GamestateRenderComponent.hpp"

VeggieFactory:: VeggieFactory(AvancezLib& lib)
{
    Sprite * veg = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg.png");
    Sprite * veg2 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg2.png");
    Sprite * veg3 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg3.png");
    Sprite * veg4 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg4.png");
    Sprite * veg5 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg5.png");
    Sprite * veg6 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg6.png");
    Sprite * veg7 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg7.png");
    Sprite * veg8 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg8.png");
    Sprite * veg9 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg9.png");
    Sprite * veg10 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/veg10.png");

    
    sprites.push_back(veg);
    sprites.push_back(veg2);
    sprites.push_back(veg3);
    sprites.push_back(veg4);
    sprites.push_back(veg5);
    sprites.push_back(veg6);
    sprites.push_back(veg7);
    sprites.push_back(veg8);
    sprites.push_back(veg9);
    sprites.push_back(veg10);
}

void VeggieFactory:: produce(int quantity)
{
    for(int i = 0; i < quantity; i++)
    {
        Factory::produce();
        physicsComponents.push_back(std::make_shared<VeggiePhysicsComponent>(objects.at(i)));
        graphicsComponents.push_back(std::make_shared<VeggieGraphicsComponent>(objects.at(i), sprites));
     
        
    }
}