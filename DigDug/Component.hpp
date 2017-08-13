//
//  Component.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 06/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include "object.hpp"
#include "Subject.hpp"

class Component: public Subject, public Observer{
public:
    virtual ~Component(){}
    virtual void update(float dt) = 0;
    virtual void reset() = 0;
    
    virtual void onNotify(Event event) = 0;
};


#endif /* Component_hpp */
