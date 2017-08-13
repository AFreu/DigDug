   //
//  ScoreComponent.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 07/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "ScoreComponent.hpp"
#include "Level.hpp"
ScoreComponent:: ScoreComponent(AvancezLib& lib, std::shared_ptr<Tunnels>& tunnels): lib(lib), tunnels(tunnels)
{
    
    int size = 24;
    
    Sprite * twoH = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_200.png");
    Sprite * threeH = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_300.png");
    Sprite * fourH = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_400.png");
    Sprite * fiveH = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_500.png");
    Sprite * sixH = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_600.png");
    Sprite * eightH = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_600.png");
    Sprite * oneT = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_1000.png", size);
    Sprite * twoTfiveH = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_2500.png", size);
    Sprite * fourT = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_4000.png", size);
    Sprite * sixT = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_6000.png", size);
    Sprite * eightT = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/score_8000.png", size);
    
    sprites.push_back(twoH);
    sprites.push_back(threeH);
    sprites.push_back(fourH);
    sprites.push_back(fiveH);
    sprites.push_back(sixH);
    sprites.push_back(eightH);
    sprites.push_back(oneT);
    sprites.push_back(twoTfiveH);
    sprites.push_back(fourT);
    sprites.push_back(sixT);
    sprites.push_back(eightT);
    
    for(int i = 0; i < 10; i++)
    {
        scoreRenderComponents.push_back(std::make_shared<ScoreRenderComponent>(sprites));
    }
    
}

  
void ScoreComponent:: update(float dt)
{
    
    unsigned long newTunnels = tunnels->getSize() - numOfTunnels;
    newScore += (newTunnels * TUNNEL_WORTH);
    numOfTunnels = tunnels->getSize();
    
    for(int i = 0; i < scoreRenderComponents.size(); i++)
    {
        scoreRenderComponents.at(i)->update(dt);
    }
    
    totalScore += newScore;
    
    notify(SCORE, totalScore);
    
    std::ostringstream os;
    os << totalScore << "points";
    std::string st = os.str();
    char const *ppchar = st.c_str();
    lib.drawText(OBJECT_SIZE * 4 + WIDTH_OFFSET, OBJECT_SIZE * 0.5, ppchar);

    
    newScore = 0;
}



void ScoreComponent:: reset()
{
    newScore = 0;
    numOfTunnels = 0;
    for(int i = 0; i < scoreRenderComponents.size(); i++){
        scoreRenderComponents.at(i)->reset();
    }
}

void ScoreComponent:: onNotify(Event event)
{
    if(event == DELETE) destroy();
}

void ScoreComponent:: onNotify(Event event, int value)
{
    if(event == LEVEL_UP) level = value;
}

void ScoreComponent:: onNotify(Event event, Position pos)
{
    onNotify(event, pos, 0);
}

void ScoreComponent:: onNotify(Event event, Position pos, int value)
{
    int score = calculateScore(event, pos, value);
    
    if(score < 200) return;

    int index = choseIndex(score);
    int duration = 120;
    scoreRenderComponents.at(getActive())-> init(pos, index, duration);
    newScore += score;
}

int ScoreComponent:: calculateScore(Event event, Position pos, int value)
{
    int score = 0;
    if(event == EXPLOAD)
    {
        score = 200;
        if(pos.y/OBJECT_SIZE > DEPTH_ONE) score = 300;
        if(pos.y/OBJECT_SIZE > DEPTH_TWO) score = 400;
        if(pos.y/OBJECT_SIZE > DEPTH_THREE) score = 500;
    }
    if(event == CRUSHED)
    {
        if(value > 0) score += 1000;
        if(value > 1) score += 1500;
        if(value > 2) score += 1500;
        if(value > 3) score += (value - 3) * 2000;
    }
    if(event == TAKEN)
    {
        if(level >= 0) score += 1000;
        if(level >= 1) score += 1500;
        if(level >= 2) score += 1500;
        if(level >= 3) score += (value - 3) * 2000;
    }
    
    return score;
}

int ScoreComponent:: getActive()
{
    int temp = 0;
    if(firstActive < scoreRenderComponents.size()){
        temp = firstActive;
        firstActive++;
    }else{
        firstActive = 0;
    }
    return temp;
}

int ScoreComponent:: choseIndex(int score)
{
    int sprite = 0;
    if(score >= 15000)
    {
        sprite = 17;
    }else if(score >= 12000)
    {
        sprite = 16;
    }else if(score >= 10000)
    {
        sprite = 15;
    }else if(score >= 8000)
    {
        sprite = 14;
    }else if(score >= 7000)
    {
        sprite = 13;
    }else if(score >= 6000)
    {
        sprite = 12;
    }else if(score >= 5000)
    {
        sprite = 11;
    }else if(score >= 4000)
    {
        sprite = 10;
    }else if(score >= 3000)
    {
        sprite = 9;
    }else if(score >= 2500)
    {
        sprite = 8;
    }else if(score >= 2000)
    {
        sprite = 7;
    }else if(score >= 1000)
    {
        sprite = 6;
    }else if(score >= 800)
    {
        sprite = 5;
    }else if(score >= 600)
    {
        sprite = 4;
    }else if(score >= 500)
    {
        sprite = 3;
    }else if(score >= 400)
    {
        sprite = 2;
    }else if(score >= 300)
    {
        sprite = 1;
    }else if(score >= 200)
    {
        sprite = 0;
    }
    return sprite;
}

void ScoreComponent:: destroy()
{
    for(Sprite* sprite : sprites)
    {
        sprite->destroy();
        delete sprite;
    }
}
