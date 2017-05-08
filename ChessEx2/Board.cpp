//
//  Board.cpp
//  ChessEx2
//
//  Created by Darius Costolas on 5/8/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include "Board.h"


Board::Board(int width, int height)
{
    this->width = width;
    this->height = height;
    
    this->GenerateBoard();
}


void Board::GenerateBoard()
{
    int current = 0;
    std::string spriteName;

    for(int i = 0 ; i < 64 ; i++)
    {
        // check if the current tile should be white or black
        if(i % 2 == current)
            spriteName = "whiteBoardTile";
        else
            spriteName = "blackBoardTile";
        
        // create new a boardtile with the specific color
        this->boardTiles.push_back(std::unique_ptr<BoardTile>(new BoardTile(SpriteManager().GetInstance().GetSprite(spriteName))));

        // the first tile should be at (0,0)
        if(i > 0)
        {
            // move every tile with 1/8 * width on the Ox axis
            this->boardTiles[i]->x = this->boardTiles[i - 1]->x + (this->width / 8);
            this->boardTiles[i]->y = this->boardTiles[i - 1]->y;

            // if we arrive at the end of the window, move subsequently tiles
            // with 1/8 * height on the Oy axis, the first one is at X = 0
            if(this->boardTiles[i]->x >= this->width)
            {
                this->boardTiles[i]->x = 0;
                this->boardTiles[i]->y += (this->height / 8);
            }
        }
        else
        {
            this->boardTiles[0]->SetPosition(0, 0);
        }
        
        // every 8 tiles created, change the color and switch rows, remembering that the first color
        // of the new row is the same ast the last color of the current row
        current = (i+1) % 8 == 0 ? current ^ 1 : current;
    }
}

void Board::Render(std::shared_ptr<Graphics> graphics)
{
    for(int i = 0; i < boardTiles.size(); i++)
    {
        boardTiles[i]->Render(graphics);
    }
}
