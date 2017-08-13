//
//  PlayerFactory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 10/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef PlayerFactory_hpp
#define PlayerFactory_hpp


#include "Factory.hpp"

class PlayerFactory: public Factory{
public:
    PlayerFactory(){}
    PlayerFactory(AvancezLib& lib);
    void produce(int quantity)override;
};


#endif /* PlayerFactory_hpp */
