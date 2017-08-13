//
//  FygarFactory.hpp
//  DigDug
//
//  Created by Anton Freudenthaler on 13/02/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef FygarFactory_hpp
#define FygarFactory_hpp

#include "Factory.hpp"

class FygarFactory: public Factory{
public:
    FygarFactory(){}
    FygarFactory(AvancezLib& lib);
    void produce(int quantity)override;
private:
    std::vector<Sprite> scoreSprites;
};

#endif /* FygarFactory_hpp */
