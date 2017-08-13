//
//  AudioComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 06/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef AudioComponent_hpp
#define AudioComponent_hpp

#include "Component.hpp"
#include "AvancezLib.hpp"

class AudioComponent: public Component{
public:
    AudioComponent(AvancezLib& lib);

    void update(float dt)override;
    void reset()override;
    
    virtual void onNotify(Event event)override;
private:
    void destroy();
    
    Music * music;
    Music * music_lastMonster;
    Sound * pop;
    Sound * fire;
    Sound * harpoon;
    Sound * killed;
    Sound * clear;
    Sound * rock;
    Sound * taken;
    
    bool lastMonster = false;
    
};

#endif /* AudioSystem_hpp */
