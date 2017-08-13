//
//  RockFactory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 09/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef RockFactory_hpp
#define RockFactory_hpp


#include "Factory.hpp"


class RockFactory: public Factory{
public:
    RockFactory(){}
    RockFactory(AvancezLib& lib);
    void produce(int quantity)override;
    
};

#endif /* RockFactory_hpp */
