//
//  World.cpp
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include "World.h"
#include <vector>

World::~World()
{
#ifdef _DEBUG
    std::cout << "Destroying the World" << std::endl;
#endif

}

std::unique_ptr<Board> board;
void World::Initialize(uint32_t width, uint32_t height)
{
    std::shared_ptr <Sprite> sprite1;
    std::shared_ptr <Sprite> sprite2;
    sprite1 = std::make_shared<Sprite>("/Users/dariuscostolas/workspace/ChessEx2/ChessEx2/assets/tileset.png");
    sprite1->SetClip(0, 0, 100, 75);
    sprite2 = std::make_shared<Sprite>("/Users/dariuscostolas/workspace/ChessEx2/ChessEx2/assets/tileset.png");
    sprite2->SetClip(128, 0, 100, 75);

    SpriteManager::GetInstance().AddSprite("whiteBoardTile", sprite1);
    SpriteManager::GetInstance().AddSprite("blackBoardTile", sprite2);
    
    board = std::unique_ptr<Board> (new Board(800, 600));

}

void World::OnKeyUp(uint8_t key)
{
    
}

void World::OnKeyDown(uint8_t key)
{
    
}

void World::OnUpdate()
{
    
}

void World::OnRender(std::shared_ptr<Graphics> graphics)
{
    board->Render(graphics);
    graphics->ClearScreen();
}
