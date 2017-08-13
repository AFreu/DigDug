//
//  InputComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef InputComponent_hpp
#define InputComponent_hpp


#include "AvancezLib.hpp"
#include "Component.hpp"



class InputComponent: public Component{
public:
    InputComponent(AvancezLib& lib): lib(lib){}
    virtual ~InputComponent(){}
    virtual void update(float dt) = 0;
    virtual void reset() = 0;
    virtual void onNotify(Event event){}
protected:
    AvancezLib& lib;
};


#endif /* InputComponent_hpp */
