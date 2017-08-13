//
//  ScoreRenderComponent.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 08/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef ScoreRenderComponent_hpp
#define ScoreRenderComponent_hpp

#include "position.h"
#include <vector>
#include "Component.hpp"
#include "Sprite.hpp"

class ScoreRenderComponent: public Component {
public:
    ScoreRenderComponent(std::vector<Sprite * > sprites);
    virtual ~ScoreRenderComponent(){}
    virtual void update(float dt);
    virtual void reset();
    
    virtual void onNotify(Event event){}
    
    void init(Position pos, int index, int duration);
    
private:
    void draw();
    int index = 0;
    int timeLeft = 120;
    
    bool active = false;
    
    Position position;
    std::vector<Sprite *> sprites;
};


#endif /* ScoreRenderComponent_hpp */
