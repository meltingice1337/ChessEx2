//
//  BoardTile.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/8/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef BoardTile_h
#define BoardTile_h

#include "Actor.h"

class BoardTile : public Actor
{
public:
    BoardTile(std::shared_ptr<Sprite> sprite);
};

#endif /* BoardTile_h */
