//
//  ChessEx2Game.cpp
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include "ChessEx2Game.h"

ChessEx2Game::ChessEx2Game(const std::string &title, uint32_t width, uint32_t height)
: Game(title, width, height)
{
    
}


ChessEx2Game::~ChessEx2Game()
{
    
}

void ChessEx2Game::OnKeyDown(SDL_KeyboardEvent& event)
{
    
    World::GetInstance().OnKeyDown(event.keysym.sym);
}

void ChessEx2Game::OnKeyUp(SDL_KeyboardEvent& event)
{
    World::GetInstance().OnKeyUp(event.keysym.sym);
}

void ChessEx2Game::OnUpdate()
{
    World::GetInstance().OnUpdate();
}

void ChessEx2Game::OnRender(Graphics *graphics)
{
    World::GetInstance().OnRender(graphics);
}

void ChessEx2Game::OnInit()
{
    World::GetInstance().Initialize(m_width, m_height);
}
