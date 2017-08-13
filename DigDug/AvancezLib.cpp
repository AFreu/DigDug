//
//  AvancezLib.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 08/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "AvancezLib.hpp"

// Creates the main window. Returns true on success.
bool AvancezLib::init(int width, int height)
{
    SDL_Log("Initializing the system...\n");
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL failed the initialization: %s\n", SDL_GetError());
        return false;
    }
    
    //Create window
    window = SDL_CreateWindow("aVANCEZ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    
    //Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    
    TTF_Init();
    font = TTF_OpenFont("/Users/Libra/Library/Fonts/space_invaders.ttf", 12); //this opens a font style and sets a size
    if (font == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "font cannot be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    
    //Initialize SDL_mixer
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    
    // initialize the keys
    clearKeyStatus();
    
    //Initialize renderer color
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    
    //Clear screen
    SDL_RenderClear(renderer);
    
    SDL_Log("System up and running...\n");
    return true;
}


// Destroys the avancez library instance
void AvancezLib::destroy()
{
    SDL_Log("Shutting down the system\n");
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    TTF_CloseFont(font);
    Mix_CloseAudio();
    
    TTF_Quit();
    SDL_Quit();
}

bool AvancezLib::update()
{
    bool go_on = true;
    SDL_Event event;
    
    
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            go_on = false;
        }
        
        if (event.type == SDL_KEYDOWN)
        {
            SDL_Keycode keyPressed = event.key.keysym.sym;
            
            switch (keyPressed)
            {
                case SDLK_q:
                case SDLK_ESCAPE:
                    go_on = false;
                    break;
                case SDLK_SPACE:
                    key.space = true;
                    break;
                case SDLK_LSHIFT:
                    key.lshift = true;
                    break;
                case SDLK_LEFT:
                    key.left = true;
                    break;
                case SDLK_RIGHT:
                    key.right = true;
                    break;
                case SDLK_UP:
                    key.up = true;
                    break;
                case SDLK_DOWN:
                    key.down = true;
                    break;
            }
        }
        
        if (event.type == SDL_KEYUP)
        {
            SDL_Keycode keyPressed = event.key.keysym.sym;
            
            switch (keyPressed)
            {
                case SDLK_SPACE:
                    key.space = false;
                    break;
                case SDLK_LSHIFT:
                    key.lshift = false;
                    break;
                case SDLK_LEFT:
                    key.left = false;
                    break;
                case SDLK_RIGHT:
                    key.right = false;
                    break;
                case SDLK_UP:
                    key.up = false;
                    break;
                case SDLK_DOWN:
                    key.down = false;
                    break;
            }
        }
    }
    
    return go_on;
}

void AvancezLib:: render()
{
    //Update screen
    SDL_RenderPresent(renderer);
    
    //Clear screen
    SDL_RenderClear(renderer);
        
}

void AvancezLib:: setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}


// Create a sprite given a path.
// All sprites are 16*16 pixels.
Sprite * AvancezLib:: createSprite(const char *name)
{
    return createSprite(name, 16);
}

Sprite * AvancezLib:: createSprite(const char* name, int frameDimension){
    SDL_Surface* img = IMG_Load(name);
    
    if (img == NULL)
    {
        SDL_Log("Image could not be loaded! SDL Error: %s\n", SDL_GetError());
    }
    
    SDL_SetColorKey(img, 1, SDL_MapRGB(img->format, 255, 255, 255) );
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, img);
    if (texture == NULL)
    {
        SDL_Log("Texture could not be created from surface! SDL Error: %s\n", SDL_GetError());
    }
    
    SDL_FreeSurface(img);
    
    Sprite * sprite = new Sprite(renderer, texture, frameDimension);
    
    return sprite;
}

Sound * AvancezLib:: createSound(const char* name)
{
    //Load the music
    Mix_Chunk * chunk = Mix_LoadWAV(name);
    if (chunk == NULL)
    {
        SDL_Log("Sound could not be loaded from path! SDL Error: %s\n", SDL_GetError());
    }
    Sound * sound = new Sound(chunk);
    return sound ;
}

Music * AvancezLib:: createMusic(const char* name)
{
    //Load the music
    Mix_Music * sound = Mix_LoadMUS(name);
    if (sound == NULL)
    {
        SDL_Log("Music could not be loaded from path! SDL Error: %s\n", SDL_GetError());
    }
    Music * music = new Music(sound);
    return music;
  
}

// Draws the given text.
void AvancezLib:: drawText(int x, int y, const char* msg){
    
    SDL_Color White = {255, 255, 255};
    
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, msg, White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    
    
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);
    
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessage);
}

void AvancezLib:: drawFPS(int elapsed)
{
    char msg[6];
    int fps = 1000/(elapsed);
    sprintf(msg, "%d fps", fps);
    //std::string str = std::to_string(fps) + "fps";
    drawText(0, 0, msg);
}

float AvancezLib:: getElapsedTime(){
    return SDL_GetTicks();
}

void AvancezLib:: delay(int delay)
{
    SDL_Delay(delay);
}

void AvancezLib:: getKeyStatus(KeyStatus& keys)
{
    keys.space = key.space;
    keys.lshift = key.lshift;
    keys.left = key.left;
    keys.right = key.right;
    keys.down = key.down;
    keys.up = key.up;
    keys.q = key.q;
    keys.escape = key.escape;
}

void AvancezLib:: clearKeyStatus()
{
    key.space = false;	key.left = false;	key.right = false;  key.lshift = false;
    key.up = false;     key.down = false;   key.q = false;      key.escape = false;
}
