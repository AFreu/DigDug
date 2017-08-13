   //
//  Level.cpp
//  DigDug
//
//  Created by Anton Freudenthaler on 06/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#include "Level.hpp"



const static int NUM_OF_PLAYERS = 1;
const static int NUM_OF_HARPOONS = 5;
const static int NUM_OF_POOKAS = 10;
const static int NUM_OF_ROCKS = 12;
const static int NUM_OF_FYGAR = 10;
const static int NUM_OF_VEGGIES = 1;
const static int NUM_OF_FIRE = 2;
const static int NUM_OF_DECOY = 1;

const static int MONSTER_TUNNEL_LENGTH = 4;


Level:: Level(AvancezLib& lib, Gamestate& gamestate)
{
    /* Create tunnels */
   std::set<Position> positions;
   this->tunnels = std::make_shared<Tunnels>(positions);
    
    /* Create entities with their components */
    playerFactory = PlayerFactory(lib);
    playerFactory.produce(NUM_OF_PLAYERS);
    harpoonFactory = HarpoonFactory(lib);
    harpoonFactory.produce(NUM_OF_HARPOONS);
    monsterFactory = MonsterFactory(lib);
    monsterFactory.produce(NUM_OF_POOKAS);
    rockFactory = RockFactory(lib);
    rockFactory.produce(NUM_OF_ROCKS);
    fygarFactory = FygarFactory(lib);
    fygarFactory.produce(NUM_OF_FYGAR);
    veggieFactory = VeggieFactory(lib);
    veggieFactory.produce(NUM_OF_VEGGIES);
    fireFactory = FireFactory(lib);
    fireFactory.produce(NUM_OF_FIRE);
    decoyFactory = DecoyFactory(lib);
    decoyFactory.produce(NUM_OF_DECOY);
    
    
    /* Create Components */
    this->inputComponent = std::make_shared<PlayerInputComponent>(lib);
    
    this->physicsComponent = std::make_shared<PhysicsComponent>(getBehaviourComponents(), getTunnels());
    
    this->gamestateComponent = std::make_shared<GamestateComponent>(gamestate);
    
    this->audioComponent = std::make_shared<AudioComponent>(lib);
    
    this->scoreComponent = std::make_shared<ScoreComponent>(lib, getTunnels());
    
    this->collisionComponent = std::make_shared<CollisionComponent>(getBehaviourComponents());
    
    this->gamestaterenderComponent = std::make_shared<GamestateRenderComponent>(lib, getTunnels(), gamestate);
    
    
    
}

int Level:: getAmountOfObjects()
{
    return numOfObjects;
}

std::vector<std::shared_ptr<Component>>&  Level:: getComponents()
{
    return components;
}


std::vector<std::shared_ptr<EntityBehaviourComponent>>& Level:: getBehaviourComponents()
{
    return behaviourComponents;
}

std::vector<std::shared_ptr<EntityRenderComponent>>& Level:: getRenderComponents()
{
    return renderComponents;
}

std::shared_ptr<Tunnels>& Level:: getTunnels()
{
    return this->tunnels;
}

/* Load the level according to text file*/
void Level:: load(int level)
{
    numOfObjects = 0;
    tunnels->clear();
    behaviourComponents.clear();
    renderComponents.clear();
    for(auto component: components) component->removeObservers();
    components.clear();
    
    monsterFactory.recycle();
    rockFactory.recycle();
    playerFactory.recycle();
    harpoonFactory.recycle();
    fygarFactory.recycle();
    veggieFactory.recycle();
    fireFactory.recycle();
    decoyFactory.recycle();
    
    
    std::stringstream ss;
    ss << level;
    std::string filename="/Users/Libra/Documents/Xcode/DigDug/Resources/Level"+ss.str()+".txt";
    std::ifstream levelfile(filename);
    std::string line;
    if(levelfile.is_open())
    {
        SDL_Log("Reading levelfile");
        
        int x, y;
        char type, direction;
        while(levelfile >> type >> x >> y >> direction)
        {
            
            std::shared_ptr<EntityBehaviourComponent> physics;
            std::shared_ptr<EntityRenderComponent> graphics;
            
            
            std::shared_ptr<EntityBehaviourComponent> usablePhysics;
            std::shared_ptr<EntityRenderComponent> usableGraphics;
            
            Position startPos;
            startPos.x = x*OBJECT_SIZE + WIDTH_OFFSET;
            startPos.y = y*OBJECT_SIZE + HEIGHT_OFFSET;
            Direction startDir = NONE;
            if(direction == 'D') startDir = DOWN;
            if(direction == 'U') startDir = UP;
            if(direction == 'L') startDir = LEFT;
            if(direction == 'R') startDir = RIGHT;
            if(type == 'C'){
                    /* Load digdug with harpoon */
                harpoonFactory.create(usablePhysics, usableGraphics, startPos, startDir, SPEED_OF_HARPOONS);

                numOfObjects++;
                behaviourComponents.push_back(usablePhysics);
                renderComponents.push_back(usableGraphics);

                playerFactory.create(playerPhysics, graphics, startPos, startDir, SPEED_OF_PLAYERS);
                
                inputComponent->addObserver(playerPhysics); //Adding behaviour as observer
                playerPhysics->addUsable(usablePhysics);

            }
            if(type == 'D'){
                    /* Load Decoy and its four harpoons */
                decoyFactory.create(physics, graphics, startPos, startDir, SPEED_OF_DECOY);
                
                playerPhysics->addUsable(physics); //Add decoy to player
                
                for(int i = 0; i < 4; i++){
                    harpoonFactory.create(usablePhysics, usableGraphics, startPos, startDir, SPEED_OF_HARPOONS);
                    numOfObjects++;
                    behaviourComponents.push_back(usablePhysics);
                    renderComponents.push_back(usableGraphics);
                    physics->addUsable(usablePhysics);
                }
                
            }
            if(type == 'V'){
                    /* Load Veggie */
                veggieFactory.create(physics, graphics, startPos, startDir, SPEED_OF_VEGGIES);
            
            }
            if(type == 'P'){
                    /* Load Pooka */
                monsterFactory.create(physics, graphics, startPos, startDir, SPEED_OF_POOKAS);
                tunnels->addTunnel(startPos, startDir , MONSTER_TUNNEL_LENGTH);
            }
            if(type == 'F'){
                    /* Load Fygar with fire */
                fireFactory.create(usablePhysics, usableGraphics, startPos, startDir, SPEED_OF_FIRE);
                numOfObjects++;
                behaviourComponents.push_back(usablePhysics);
                renderComponents.push_back(usableGraphics);
                
                fygarFactory.create(physics, graphics, startPos, startDir, SPEED_OF_FYGAR);
                tunnels->addTunnel(startPos, startDir , MONSTER_TUNNEL_LENGTH);
                physics->addUsable(usablePhysics);
                
            }
            if(type == 'R'){
                    /* Load Rock */
                rockFactory.create(physics, graphics, startPos, startDir, SPEED_OF_ROCKS);
            }
            
            if(type == 'C'){
                behaviourComponents.push_back(playerPhysics);
            }else{
                behaviourComponents.push_back(physics);
            }
            renderComponents.push_back(graphics);
            numOfObjects++;
        }
        
        loadTunnels();
        bindComponents();
        pushComponents();
        
        levelfile.close();
    }

}

void Level:: loadTunnels()
{
    Position origin;
    origin.setxy(WIDTH_OFFSET,HEIGHT_OFFSET);
    tunnels->addTunnel(origin, RIGHT, 13);
    origin.setxy(6*OBJECT_SIZE + WIDTH_OFFSET, HEIGHT_OFFSET);
    tunnels->addTunnel(origin, DOWN, 7);
    origin.setxy(5*OBJECT_SIZE + WIDTH_OFFSET, 7*OBJECT_SIZE + HEIGHT_OFFSET);
    tunnels->addTunnel(origin, RIGHT, 2);

}

void Level:: bindComponents()
{
    inputComponent->addObserver(audioComponent);
    gamestateComponent->addObserver(physicsComponent);
    gamestateComponent->addObserver(audioComponent);
    
    for(auto component: behaviourComponents)
    {
        Object& obj = component->getObject();
        Entity type = component->getType();
        
        /* Score, audio and tha gamestate listens to behaviour components */
        component->addObserver(scoreComponent);
        component->addObserver(audioComponent);
        component->addObserver(gamestateComponent);
        
        
        /* Monsters observes the player and the DECOY */
        if(type == PLAYER || type == DECOY){
            for(auto component2 : behaviourComponents){
                if(component2->getType() == MONSTER){
                    component->addObserver(component2);
                }
            }
        }
        
        
        
        /* Monsters and veggies are interested in the gamestate */
        if(type == MONSTER || type == VEGGIE)
        {
            gamestateComponent->addObserver(component);
        }
        
        /* Initiate some things deactivated */
        if(type == HARPOON || type == FIRE || type == DECOY || type == VEGGIE){
            obj.deactivate();
        }
        
        /* Monsters and Veggies observes Rocks */
        if(type == ROCK){
            for(auto component2 : behaviourComponents){
                Entity type2 = component2->getType();
                if(type2 == MONSTER || type2 == VEGGIE){
                    component->addObserver(component2);
                }
            }
        }
    }
}

void Level:: pushComponents()
{
    /* Add input components to the list */
    components.push_back(inputComponent);
    
    /* Add components to the list */
    components.push_back(audioComponent);
    components.push_back(physicsComponent);
    components.push_back(gamestateComponent);
    components.push_back(collisionComponent);
    components.push_back(gamestaterenderComponent);
    components.push_back(scoreComponent);
    
    /* Add behaviour components to the list */
    for(std::shared_ptr<Component> component: getBehaviourComponents()){
        components.push_back(component);
    }
    
    /* Add render components to the list */
    for(std::shared_ptr<Component> component: getRenderComponents()){
        components.push_back(component);
    }
}

void Level:: destroy()
{
    for(auto component: components) component->onNotify(DELETE);
    components.clear();
    behaviourComponents.clear();
    renderComponents.clear();
    
    monsterFactory.destroy();
    rockFactory.destroy();
    playerFactory.destroy();
    harpoonFactory.destroy();
    fygarFactory.destroy();
    veggieFactory.destroy();
    fireFactory.destroy();
    decoyFactory.destroy();
    
}



