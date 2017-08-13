     //
//  DigDug.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 27/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "DigDug.hpp"

DigDug:: DigDug(AvancezLib& lib) :lib(lib)
{
    
    /* Create initial gamestate */
    gamestate.lives = 3;
    gamestate.level = 1;
    lastState.copy(gamestate);
    
    /* Create Level */
    level = new Level(lib, gamestate);
}

void DigDug:: init()
{
    /* Clear list of components */
    components.clear();
    
    /* Load current level */
    level->load(gamestate.level);
    
    /* Get the components */
    components = level->getComponents();
    
    lastTime = lib.getElapsedTime();
}

bool DigDug:: update()
{
    bool go_on = true;
    
    elapsed = lib.getElapsedTime() - lastTime;
    lastTime = lib.getElapsedTime();

    for(auto component: components) component->update(elapsed);
    
    go_on &= lib.update();
    lib.render();
    
    go_on &= handleGamestate();
    
    return go_on;
}


bool DigDug:: handleGamestate()
{
    /* Check game ending conditions */
    bool gameover = gamestate.lives < 0 || gamestate.level > MAX_LEVEL;
    
    /* Quit the game loop if conditions hold */
    if(gameover) return false;
    
    
    /* Check if a life has been lost */
    if(lastState.lives > gamestate.lives)
    {
        std::cout<<"Lost life";
        /* Reset and update the components */
        reset();
        updateComponents();
        
        /* Render and delay before starting */
        lib.render();
        lib.delay(2000);
        lastTime += 2000;
    }
    
    /* Check if the playing field has been cleared */
    if(lastState.level < gamestate.level)
    {
        std::cout<<"Next level";
        
        /* Reset the old components */
        reset();
        
        /* Reinitialise with the new game state */
        init();
        
        /* Reset and update the new components */
        reset(); //TODO all components doesn't seem to reset properly
        updateComponents();
        
        /* Render and delay before starting */
        lib.render();
        lib.delay(3500);
        lastTime += 3500;
    }
    
    /* Save gamestate for comparison */
    lastState.copy(gamestate);
    return true;
        
}

std::string DigDug:: getResult()
{
    std::ostringstream oss;
    oss << "Result: " << " Lives " << gamestate.lives  << " Level " << gamestate.level;
    std::string s = oss.str();
    return s;
    
}

void DigDug:: updateComponents()
{
    for(auto component: components) component->update(0);
}

void DigDug:: reset()
{
    for(auto component: components) component->reset();
}

void DigDug:: destroy()
{
    components.clear();
    level->destroy();
    delete level;
}


