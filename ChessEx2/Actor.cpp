//
//  Actor.cpp
//  ChessEx2
//
//  Created by Darius Costolas on 5/8/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include "Actor.h"

Actor::Actor(std::shared_ptr<Sprite> sprite)
{
    this->sprite = sprite;
    
    // first position of the actor should be (0,0)
    x = 0;
    y = 0;
}

void Actor::Render(std::shared_ptr<Graphics> graphics)
{
    this->sprite->Render(graphics, x, y);
}

void Actor::SetPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}
