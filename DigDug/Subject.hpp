//
//  Subject.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 30/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Subject_hpp
#define Subject_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include "Observer.h"

class Subject
{
public:
    void addObserver(const std::shared_ptr<Observer>& observer);
    void removeObserver(std::shared_ptr<Observer>& observer);
    void removeObservers();
    
private:
    std::set<std::shared_ptr<Observer>> observers;
protected:
    void notify(Event event);
    void notify(Event event, Entity entity);
    void notify(Event event, Position pos);
    void notify(Event event, Entity entity, Position pos);
    void notify(Event event, int value);
    void notify(Event event, Position position, int value);
    void notify(Entity entity, Position pos);
};

#endif /* Subject_hpp */
