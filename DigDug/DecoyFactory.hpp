//
//  DecoyFactory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 01/03/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef DecoyFactory_hpp
#define DecoyFactory_hpp

#include "Factory.hpp"

class DecoyFactory: public Factory{
public:
    DecoyFactory(){}
    DecoyFactory(AvancezLib& lib);
    void produce(int quantity)override;
};


#endif /* DecoyFactory_hpp */
