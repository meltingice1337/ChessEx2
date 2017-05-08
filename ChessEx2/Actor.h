//
//  Actor.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/8/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef Actor_h
#define Actor_h

#include "utility/Graphics.h"
#include "utility/Sprite.h"

class Actor
{
public:
    Actor(std::shared_ptr<Sprite> sprite);
    Actor();
    void Render(std::shared_ptr<Graphics> graphics);
    void SetPosition(int x, int y);
    int x,y;
private:
    std::shared_ptr<Sprite> sprite;
};

#endif /* Actor_h */
