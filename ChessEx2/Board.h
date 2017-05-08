//
//  Board.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/8/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include "Actor.h"
#include "BoardTile.h"
#include "SpriteManager.h"
#include <vector>

class Board
{
public:
    Board(int width, int height);
    void Render(std::shared_ptr<Graphics> graphics);
private:
    std::vector<std::unique_ptr<BoardTile>> boardTiles;
    void GenerateBoard();
    int width, height;
};

#endif /* Board_h */
