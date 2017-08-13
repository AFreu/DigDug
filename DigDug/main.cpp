//
//  main.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 20/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>


#include "DigDug.hpp"


int main(int argc, const char * argv[]) {
    int fps = 60, mspf = 1000/fps;
    
    int width = 18*32, height = 18*32;
    
    AvancezLib lib = AvancezLib();
    lib.init(width, height);
    Sprite * menu_background = lib.createSprite("/Users/Libra/Documents/Xcode/DigDug/Resources/header.png");

    AvancezLib::KeyStatus key;
    
    DigDug digdug = DigDug(lib);
    
    int currentTime = lib.getElapsedTime();
    bool show = true;
    int timer = 1*700;
    
    while(lib.update()){
        lib.getKeyStatus(key);
        lib.render();
        
        int elapsed = lib.getElapsedTime() - currentTime; //Calculate elapsed time
        timer -= elapsed;
        if(timer <= 0){
            timer = 700;
            show = !show;
        }
        currentTime = lib.getElapsedTime();
        
        menu_background->drawf(0,0,width,height);
        if(show) lib.drawText(240,500,"Press space to start dig dug");
        lib.drawText(8, 190, "Dig dug general sprites ripped by Jdaster64" );
        lib.drawText(100,480, digdug.getResult().c_str());
        lib.setRenderColor(0x00, 0x00, 0x00, 0x00);
        
        if(key.space) //start digdug
        {
            lib.clearKeyStatus();
            lib.setRenderColor(0x67, 0x35, 0x10, 0xFF);
            digdug.init();
            
            while (digdug.update()) //Update game
            {
                
                elapsed = lib.getElapsedTime() - currentTime; //Calculate elapsed time
                
                if(mspf - elapsed >= 0) lib.delay(mspf - elapsed); //Delay so that each frame takes 16ms
                
                elapsed = lib.getElapsedTime() - currentTime; //Calculate elapsed time after delay
                
                lib.drawFPS(elapsed); //Print the fps to screen
                
                currentTime = lib.getElapsedTime(); //Store current time before updating
                
            }
            
        }
        
    }
    digdug.destroy();
    menu_background->destroy();

    lib.destroy();
    
    
    return 0;
}


