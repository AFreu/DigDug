//
//  AvancezLib.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 08/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef AvancezLib_hpp
#define AvancezLib_hpp


#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"

#include "Sprite.hpp"
#include "Sound.hpp"


class AvancezLib
{
public:
    // Destroys the avancez library instance
    void destroy();
    
    // Creates the main window. Returns true on success.
    bool init(int width, int height);
    
   
    // If update returns false, the application should terminate.
    bool update();
    // Clears the screen and draws all sprites and texts which have been drawn
    // since the last update call.
    void render();
    
    void setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    
    // Create a sprite given a string.
    // All sprites are 32*32 pixels.
    Sprite * createSprite(const char* name);
    Sprite * createSprite(const char* name, int frameDimension);
    
    //Create sound given a path.
    Sound * createSound(const char* name);
    Music * createMusic(const char* name);
    
    // Draws the given text.
    void drawText(int x, int y, const char* msg);
    void drawFPS(int elapsed);
    
    // Return the total time spent in the game, in milliseconds.
    float getElapsedTime();
    
    void delay(int delay);
    
    struct KeyStatus
    {
        bool space = false; // space
        bool lshift = false; //left shift
        bool left = false; // left arrow
        bool right = false; // right arrow
        bool up = false;    // up arrow
        bool down = false;  // down arrow
        bool q = false;
        bool escape = false;
        
    };

    
    // Returns the keyboard status. If a flag is set, the corresponding key is being held down.
    void getKeyStatus(KeyStatus& keys);
    void clearKeyStatus();
    
private:
    SDL_Window * window;
    SDL_Renderer * renderer;
    
    TTF_Font* font;
    
    KeyStatus key;
    
};

#endif /* AvancezLib_hpp */
