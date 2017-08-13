//
//  MonsterFactory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 09/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef MonsterFactory_hpp
#define MonsterFactory_hpp


#include "Factory.hpp"


class MonsterFactory: public Factory{
public:
    MonsterFactory(){}
    MonsterFactory(AvancezLib& lib);
    void produce(int quantity);
};

#endif /* MonsterFactory_hpp */
