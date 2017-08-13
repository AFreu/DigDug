//
//  Factory.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 13/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "Factory.hpp"
#include "GamestateRenderComponent.hpp"
#include "Sprite.hpp"
#include "object.hpp"
#include "InputComponent.hpp"
#include "EntityBehaviourComponent.hpp"
#include "EntityRenderComponent.hpp"


void Factory:: create(std::shared_ptr<EntityBehaviourComponent>& physics, std::shared_ptr<EntityRenderComponent>& graphics, Position startPos, Direction startDir, int startSpeed)
{
    
    //Look for the first inactive object
    unsigned long firstInactive = objects.size();
    for(int i = 0; i < objects.size(); i++)
    {
        if(!objects.at(i)->isActive()){ //Found an inactive object
            firstInactive = i;
            break;
        }
    }
    
    /**************************************************************/
    /* This should be avoided by producing more on instansiation */
    if(firstInactive == objects.size()){
        produce(1); //Add another object if the current ones are all active
    }
    /**************************************************************/

    /* Initiate object */
    objects.at(firstInactive)->activate();
    objects.at(firstInactive)->setStartValues(startPos, startDir, startSpeed);
    
    //Return the corresponding components
    physics = physicsComponents.at(firstInactive);
    graphics = graphicsComponents.at(firstInactive);
    
    physics->reset();
    graphics->reset();
    
    //Connect subjects and observers
    physics->addObserver(graphics);
    
    
}

void Factory:: produce(){
    objects.push_back(new Object());
}


void Factory:: destroy()
{
    for(Sprite * sprite : sprites)
    {
        sprite->destroy();
        delete sprite;
    }
    for(Object* object: objects)
    {
        delete object;
    }
}

void Factory:: recycle()
{
    for(Object* object : objects)
    {
        object->deactivate();
    }
}
