//
//  Observer.h
//  DigDug
//
//  Created by Anton Freudenthaler on 30/01/17.
//  Copyright © 2017 Anton Freudenthaler. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include "position.h"

enum Event{
    CHANGED,    DELETE,         FLYING,         FALLING,        SPREAD_FIRE,
    DESTROYED,  DECOY_USED,     KILLED,         CRUSHED,        RESETED,
    HARPOONED,  HARPOONING,     EXPLOAD,        INFLATED,       INFLATE,
    DEFLATE,    GHOST,          NOT_GHOST,      SCORE,          STUNNED,
    LEVEL_UP,   TAKEN,          ACTIVE,         ACTIVATED,      DEACTIVATED,
    KEY_SPACE,  KEY_LSHIFT,     KEY_RIGHT,      KEY_LEFT,       KEY_UP,
    KEY_DOWN,   LAST_MONSTER,   NOT_STUNNED,    NOT_HARPOONED
};

enum Entity{
    DEAD_PLAYER,    FALLING_ROCK,       DECOY,      FIRE,
    HARPOON,        GHOST_MONSTER,      MONSTER,    PLAYER,
    ROCK,           STUNNED_MONSTER,    VEGGIE,     NOTHING
};


class Observer
{
public:
    virtual ~Observer() {}
    virtual void onNotify(Event event) = 0;
    virtual void onNotify(Event event, Entity entity){}
    virtual void onNotify(Event event, Position pos){}
    virtual void onNotify(Event event, Entity entity, Position pos){}
    virtual void onNotify(Event event, int value){}
    virtual void onNotify(Event event, Position pos, int value){}
    virtual void onNotify(Entity entity, Position pos){}
};

#endif /* Observer_h */
