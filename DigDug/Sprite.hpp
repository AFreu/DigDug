//
//  Sprite.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 27/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "SDL2/SDL.h"

enum Flip {
    HORIZONTAL,
    VERTICAL,
    NO
};

class Sprite
{
    SDL_Renderer * renderer;
    SDL_Texture * texture;
    int frameDimension = 16;

    
    
public:
    
    Sprite(SDL_Renderer * renderer, SDL_Texture * texture, int frameDimension);
    
    void destroy();
    
    void draw(int x, int y);
    
    void draw(int x, int y, Flip flip);
    
    void draw(int x, int y, int elapsed, int frame, Flip flip);
    
    void drawf(int x, int y, int w, int h);
    
    void drawf(int x, int y, int w, int h, int width, int height);
    
private:
    
    SDL_RendererFlip translateFlip(Flip flip){
        SDL_RendererFlip temp;
        switch(flip)
        {
            case HORIZONTAL:
                temp = SDL_FLIP_HORIZONTAL;
                break;
            case VERTICAL:
                temp = SDL_FLIP_VERTICAL;
                break;
            default:
                temp = SDL_FLIP_NONE;
                break;
        }
        return temp;    }
    
};

#endif /* Sprite_hpp */
