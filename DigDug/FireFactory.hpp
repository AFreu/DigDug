//
//  FireFactory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 23/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef FireFactory_hpp
#define FireFactory_hpp

#include "Factory.hpp"


class FireFactory: public Factory{
public:
    FireFactory(){}
    FireFactory(AvancezLib& lib);
    void produce(int quantity)override;
    
};

#endif /* FireFactory_hpp */
