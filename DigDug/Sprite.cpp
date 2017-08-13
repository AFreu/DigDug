//
//  Sprite.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 27/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "Sprite.hpp"

////////////////////////////////////////////////////////////
////////////////////// SPRITE //////////////////////////////
////////////////////////////////////////////////////////////

Sprite:: Sprite(SDL_Renderer * render, SDL_Texture * text, int frameDimension){
    this->renderer = render;
    this->texture = text;
    if(frameDimension > 16) this->frameDimension = 24;
    else this->frameDimension = 16;
}

// Destroys the sprite instance
void Sprite:: destroy(){
   
    SDL_DestroyTexture(texture);
}

// Draw the sprite at the given position.
// Valid coordinates are between (0,0) (upper left) and (width-32, height-32) (lower right).
void Sprite:: draw(int x, int y)
{
    draw(x, y, NO);
}

void Sprite:: draw(int x, int y,  const Flip flip)
{
    draw(x,y, 0, 1, flip);
}

void Sprite:: draw(int x, int y, int elapsed, int numFrames, Flip flip)
{
    //frame has to be a positive number
    if(numFrames < 1) numFrames = 1;
        
    //Sprites bigger than the normal size need to be positioned differently
    int offset = 0;
    if(frameDimension > 16) offset = 16; // Very specific for 24x24 textures.
    
    //The position and dimensions of the texture to draw
    SDL_Rect texture_rect;
    texture_rect.x = x;
    texture_rect.y = y - offset;
    texture_rect.w = frameDimension * 2;
    texture_rect.h = frameDimension * 2;
    
    //Animation done by looping over frames in the same sprite
    int frame = (int)((elapsed/60)%numFrames);
    
    //The position and dimensions of the frame within the sprite
    SDL_Rect srcrect = { frame * frameDimension, 0, frameDimension, frameDimension};
    
    //Place on the renderer
    SDL_RenderCopyEx(renderer, texture, &srcrect , &texture_rect, 0, NULL, translateFlip(flip));
    
}


void Sprite:: drawf(int x, int y, int w, int h)
{
    drawf(x,y,w,h,w,h);
}

void Sprite:: drawf(int x, int y, int w, int h, int width, int height)
{
    SDL_Rect texture_rect = {x, y, w, h};
    SDL_Rect srcrect = {0, 0, width, height};
    SDL_RenderCopy(renderer, texture, &srcrect, &texture_rect);
}
