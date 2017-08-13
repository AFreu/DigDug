//
//  Level.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 06/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp

const static float SPEED_OF_PLAYERS = 3;
const static float SPEED_OF_HARPOONS = 3;
const static float SPEED_OF_POOKAS = 1;
const static float SPEED_OF_ROCKS = 32;
const static float SPEED_OF_FYGAR = 1;
const static float SPEED_OF_VEGGIES = 0;
const static float SPEED_OF_FIRE = 1;
const static float SPEED_OF_DECOY = 1;


#include <iostream>
#include <string>
#include <fstream>

#include <sstream>

#include "MonsterFactory.hpp"
#include "RockFactory.hpp"
#include "PlayerFactory.hpp"
#include "HarpoonFactory.hpp"
#include "FygarFactory.hpp"
#include "VeggieFactory.hpp"
#include "FireFactory.hpp"
#include "DecoyFactory.hpp"

#include "Tunnels.hpp"

#include "AvancezLib.hpp"


#include "InputComponent.hpp"
#include "EntityBehaviourComponent.hpp"
#include "EntityRenderComponent.hpp"
#include "PlayerInputComponent.hpp"

#include "ScoreComponent.hpp"
#include "AudioComponent.hpp"
#include "CollisionComponent.hpp"
#include "GamestateComponent.hpp"
#include "GamestateRenderComponent.hpp"
#include "PhysicsComponent.hpp"


class Level {
public:
    Level(AvancezLib& lib, Gamestate& gamestate);
    void load(int level);
    void destroy();
    
    int getAmountOfObjects();
    
    std::vector<std::shared_ptr<EntityBehaviourComponent>>& getBehaviourComponents();
    std::vector<std::shared_ptr<EntityRenderComponent>>& getRenderComponents();
    std::shared_ptr<Tunnels>& getTunnels();
    
    std::vector<std::shared_ptr<Component>>& getComponents();

    
private:
    
    void loadTunnels();
    void bindComponents();
    void pushComponents();
    
    int numOfObjects = 0;
    
    std::shared_ptr<Tunnels> tunnels;
    
    
    std::shared_ptr<EntityBehaviourComponent> playerPhysics;
    
    std::shared_ptr<InputComponent> inputComponent;
    std::shared_ptr<AudioComponent> audioComponent;
    std::shared_ptr<ScoreComponent> scoreComponent;
    std::shared_ptr<PhysicsComponent> physicsComponent;
    std::shared_ptr<CollisionComponent> collisionComponent;
    
    std::shared_ptr<GamestateComponent> gamestateComponent;
    std::shared_ptr<GamestateRenderComponent> gamestaterenderComponent;
    
    
    std::vector<std::shared_ptr<Component>> components;
    
    std::vector<std::shared_ptr<EntityBehaviourComponent>> behaviourComponents;
    std::vector<std::shared_ptr<EntityRenderComponent>> renderComponents;
    
    MonsterFactory monsterFactory;
    RockFactory rockFactory;
    PlayerFactory playerFactory;
    HarpoonFactory harpoonFactory;
    FygarFactory fygarFactory;
    VeggieFactory veggieFactory;
    FireFactory fireFactory;
    DecoyFactory decoyFactory;

    
};


#endif /* Level_hpp */
