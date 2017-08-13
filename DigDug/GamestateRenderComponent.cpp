//
//  GamestateRenderComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 27/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "GamestateRenderComponent.hpp"
#include "EntityRenderComponent.hpp"
#include "Level.hpp"
#include "gamestate.h"

GamestateRenderComponent:: GamestateRenderComponent(AvancezLib& lib, std::shared_ptr<Tunnels>& tunnels, Gamestate& state): tunnels(tunnels), gamestate(state){
    
    Sprite * tunnel = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/tunnel_copy.png");
    Sprite * dirt0 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/dirt.png");
    Sprite * dirt1 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/dirt2.png");
    Sprite * dirt2 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/dirt3.png");
    Sprite * dirt3 = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/dirt4.png");
    
    Sprite * player = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/digdug_right.png");
    Sprite * flower = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/flower.png");
    Sprite * controls = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/controls.png");
    
    
    sprites.push_back(player);
    sprites.push_back(flower);
    sprites.push_back(tunnel);
    sprites.push_back(dirt0);
    sprites.push_back(dirt1);
    sprites.push_back(dirt2);
    sprites.push_back(dirt3);
    sprites.push_back(controls);
}


void GamestateRenderComponent:: update(float dt)
{
    
    drawDirt(WIDTH, HEIGHT);
    drawLives(gamestate.lives);
    drawControls();
    
    
    for(auto pos : tunnels->getTunnelPositions())
    {
        drawTunnel(pos);
    }
    
    drawFlowers(gamestate.level);
}


void GamestateRenderComponent:: reset()
{

}

void GamestateRenderComponent:: onNotify(Event event)
{
    if(event == DELETE) destroy();

}


void GamestateRenderComponent:: destroy()
{
    for(Sprite * sprite : sprites)
    {
        sprite->destroy();
        delete sprite;
    }
}

void GamestateRenderComponent:: drawFlowers(int level)
{
    for(int i = 0; i < level; i++){
        sprites.at(1)->draw(OBJECT_SIZE * ((WIDTH-1)-i) + WIDTH_OFFSET, HEIGHT_OFFSET);
    }
}

void GamestateRenderComponent:: drawLives(int lives)
{
    if(lives > 2) sprites.at(0)->draw(OBJECT_SIZE*2+WIDTH_OFFSET, 0);
    if(lives > 1) sprites.at(0)->draw(OBJECT_SIZE*1+WIDTH_OFFSET, 0);
    if(lives > 0) sprites.at(0)->draw(WIDTH_OFFSET, 0);
}


void GamestateRenderComponent:: drawDirt(int width, int height)
{
    int heightoffset = HEIGHT_OFFSET/OBJECT_SIZE + 1;
    int first = DEPTH_ONE + heightoffset;
    int second = DEPTH_TWO + heightoffset;
    int third = DEPTH_THREE + heightoffset;
    
    for(int w = WIDTH_OFFSET/OBJECT_SIZE; w < width + WIDTH_OFFSET/OBJECT_SIZE; w++)
    {
        for(int h = heightoffset; h < first; h++)
        {
            sprites.at(3)->draw(w*OBJECT_SIZE, h*OBJECT_SIZE);
        }
        for(int h = first ; h < second; h++)
        {
            sprites.at(3+1)->draw(w*OBJECT_SIZE, h*OBJECT_SIZE);
        }
        for(int h = second; h < third; h++)
        {
            sprites.at(3+2)->draw(w*OBJECT_SIZE, h*OBJECT_SIZE);

        }
        for(int h = third; h < height + heightoffset; h++)
        {
            sprites.at(3+3)->draw(w*OBJECT_SIZE, h*OBJECT_SIZE);
        }
        
    }
}

void GamestateRenderComponent:: drawTunnel(Position pos){
    sprites.at(2)->draw(pos.x,pos.y);
}


void GamestateRenderComponent:: drawControls()
{
    sprites.at(7)->drawf(GAME_WIDTH + WIDTH_OFFSET, GAME_HEIGHT/2, WIDTH_OFFSET, 120, 96, 181);
}





