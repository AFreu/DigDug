 //
//  ScoreRenderComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 23/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "ScoreRenderComponent.hpp"
ScoreRenderComponent:: ScoreRenderComponent(std::vector<Sprite *> sprites)
{
    this->sprites = sprites;
}

void ScoreRenderComponent:: init(Position pos, int index, int duration)
{
    this->timeLeft = duration;
    this->position = pos;
    this->index = index;
    if(index >= 0) active = true;
}

void ScoreRenderComponent:: reset()
{
    active = false;
    timeLeft = 0;
}

void ScoreRenderComponent:: update(float dt)
{
    if(active && timeLeft > 0){
        timeLeft--;
        draw();
    }else{
        active = false;
    }
}

void ScoreRenderComponent:: draw()
{
        sprites.at(index)->draw(position.x, position.y);
}