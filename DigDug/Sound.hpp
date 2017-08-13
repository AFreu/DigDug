//
//  Sound.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 08/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Sound_hpp
#define Sound_hpp

#include "SDL2_mixer/SDL_mixer.h"


/* Sound and Music are simple wrapper classes of SDL_mixer funtionalities */

class Sound{
    
    Mix_Chunk * chunk;
    
public:
    Sound(Mix_Chunk* chunk):chunk(chunk){}
    void play(int channel, int loops){Mix_PlayChannel(channel, chunk, loops);}
    void volume(int strength){Mix_VolumeChunk(chunk, strength);}
    bool playing(int channel){return Mix_Playing(channel);}
    void destroy(){Mix_FreeChunk(chunk);}
};

class Music{
    
    Mix_Music * music;
    
public:
    Music(Mix_Music* music):music(music){}
    void play(int loops){Mix_PlayMusic(music, loops);}
    void pause(){Mix_PauseMusic();}
    void halt(){Mix_HaltMusic();}
    void resume(){Mix_ResumeMusic();}
    void volume(int strength){Mix_VolumeMusic(strength);}
    void destroy(){Mix_FreeMusic(music);}
};

#endif /* Sound_hpp */
