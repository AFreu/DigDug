//
//  Subject.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 30/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "Subject.hpp"
void Subject:: addObserver(const std::shared_ptr<Observer>& observer)
{
    observers.insert(observer);
}

void Subject:: removeObserver(std::shared_ptr<Observer>& observer)
{
    if(observer != nullptr){
        observers.erase(observer);
    }
}

void Subject:: removeObservers()
{
    observers.clear();
}


void Subject:: notify(Event event)
{
    for(std::shared_ptr<Observer> observer: observers) observer->onNotify(event);
}

void Subject:: notify(Event event, Entity entity)
{
    for(std::shared_ptr<Observer> observer: observers) observer->onNotify(event, entity);
    
}

void Subject:: notify(Event event, Position pos)
{
    for(std::shared_ptr<Observer> observer: observers) observer->onNotify(event, pos);
}

void Subject:: notify(Event event, Entity entity, Position pos)
{
     for(std::shared_ptr<Observer> observer: observers) observer->onNotify(event, entity, pos);
}

void Subject:: notify(Event event, int value)
{
    for(std::shared_ptr<Observer> observer: observers) observer->onNotify(event, value);
}

void Subject:: notify(Event event, Position pos, int value)
{
    for(std::shared_ptr<Observer> observer: observers) observer->onNotify(event, pos, value);
}

void Subject:: notify(Entity entity, Position pos)
{
    for(std::shared_ptr<Observer> observer: observers) observer->onNotify(entity, pos);
}




