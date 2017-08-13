//
//  CollisionComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 09/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "CollisionComponent.hpp"

void CollisionComponent:: update(float dt)
{
    if(dt <= 0) return;
    
    unsigned long size = components.size();
    
    for(int i = 0; i < size; i++)
    {
        Object& obj1 = components.at(i)->getObject();
        for(int j = i+1; j < size && i < size-1; j++)
        {
            Object& obj2 = components.at(j)->getObject();
            if(Physics::collision(obj1, obj2))
            {
                components.at(i)->receive(COLLISION, obj2, components.at(j)->getType());
                components.at(j)->receive(COLLISION, obj1, components.at(i)->getType());
            }
            
        }
    }
}

void CollisionComponent:: reset()
{
    
}


