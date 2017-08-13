//
//  PlayerInputComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef PlayerInputComponent_hpp
#define PlayerInputComponent_hpp

#include "InputComponent.hpp"


class PlayerInputComponent : public InputComponent{
public:
    PlayerInputComponent(AvancezLib& lib): InputComponent(lib){}
    void update(float dt)override;
    void reset()override;
};

#endif /* PlayerInputComponent_hpp */
