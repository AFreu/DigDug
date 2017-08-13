//
//  HarpoonFactory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 11/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef HarpoonFactory_hpp
#define HarpoonFactory_hpp

#include "Factory.hpp"


class HarpoonFactory: public Factory{
public:
    HarpoonFactory(){}
    HarpoonFactory(AvancezLib& lib);
    void produce(int quantity)override;
    
};

#endif /* HarpoonFactory_hpp */
