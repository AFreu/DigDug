//
//  VeggieFactory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 20/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef VeggieFactory_hpp
#define VeggieFactory_hpp

#include "Factory.hpp"

class VeggieFactory: public Factory{
public:
    VeggieFactory(){}
    VeggieFactory(AvancezLib& lib);
    void produce(int quantity)override;
    
private:
    std::vector<Sprite> scoreSprites;
};

#endif /* VeggieFactory_hpp */
