//
//  AudioComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 06/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "AudioComponent.hpp"

AudioComponent:: AudioComponent(AvancezLib& lib)
{
    //Load the music
    music = lib.createMusic( "/Users/Libra/Documents/Xcode/DigDug/Sounds/music.wav" );
    music_lastMonster = lib.createMusic("/Users/Libra/Documents/Xcode/DigDug/Sounds/lastmonster.wav");
    
    //Load the sounds
    pop = lib.createSound("/Users/Libra/Documents/Xcode/DigDug/Sounds/enemy_pop.wav");
    fire = lib.createSound("/Users/Libra/Documents/Xcode/DigDug/Sounds/fygar_fire.wav");
    harpoon = lib.createSound("/Users/Libra/Documents/Xcode/DigDug/Sounds/harpoon.wav");
    clear = lib.createSound("/Users/Libra/Documents/Xcode/DigDug/Sounds/clear.wav");
    killed = lib.createSound("/Users/Libra/Documents/Xcode/DigDug/Sounds/killed.wav");
    rock = lib.createSound("/Users/Libra/Documents/Xcode/DigDug/Sounds/rock_thud.wav");
    taken = lib.createSound("/Users/Libra/Documents/Xcode/DigDug/Sounds/extra_life.wav");
    
    music_lastMonster->halt();
    music->play(-1);
    music->volume(15);
    harpoon->volume(25);
    fire->volume(25);
    music->pause();
}

void AudioComponent:: update(float dt)
{
    if(dt <= 0) return;
    music->resume();
}

void AudioComponent:: reset()
{
    lastMonster = false;
    music_lastMonster->halt();
    music->play(-1);
    music->pause();
}

void AudioComponent:: destroy()
{
    taken->destroy();
    delete taken;
    rock->destroy();
    delete rock;
    clear->destroy();
    delete clear;
    killed->destroy();
    delete killed;
    fire->destroy();
    delete fire;
    harpoon->destroy();
    delete harpoon;
    pop->destroy();
    delete pop;
    music->destroy();
    delete music;
    music_lastMonster->destroy();
    delete music_lastMonster;
}

void AudioComponent:: onNotify(Event event)
{
    if(event == SPREAD_FIRE) fire->play(-1, 0);
    if(event == EXPLOAD) pop->play(-1, 0);
    if(event == HARPOONING){ if(!harpoon->playing(2)) harpoon->play(2, 0);}
    if(event == KILLED){ if(!killed->playing(5))killed->play(5, 0);}
    if(event == CRUSHED){if(!rock->playing(6))rock->play(6, 0);}
    if(event == TAKEN){taken->play(-1, 0);}
    if(event == LAST_MONSTER && !lastMonster)
    {
        lastMonster = true;
        music->halt();
        music_lastMonster->play(-1);
    }
    if(event == LEVEL_UP)
    {
       if(!clear->playing(1))clear->play(1, 0);
    }
    
    if(event == DELETE) destroy();
}



