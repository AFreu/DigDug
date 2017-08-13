           //
//  PlayerInputComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 25/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "PlayerInputComponent.hpp"


void PlayerInputComponent:: update(float dt){
    AvancezLib::KeyStatus keys;
    lib.getKeyStatus(keys);

    
    if(keys.down) notify(KEY_DOWN);
    if(keys.up) notify(KEY_UP);
    if(keys.left) notify(KEY_LEFT);
    if(keys.right) notify(KEY_RIGHT);
    if(keys.lshift) notify(KEY_LSHIFT);
    if(keys.space) notify(KEY_SPACE);

}

void PlayerInputComponent:: reset()
{

}
