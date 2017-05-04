//
//  ChessEx2Game.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef ChessEx2Game_h
#define ChessEx2Game_h

#include <iostream>
#include "utility/Game.h"
#include "utility/Graphics.h"
#include "World.h"

class ChessEx2Game : public Game
{
public:
    ChessEx2Game(const std::string &title, uint32_t width, uint32_t height);
    ~ChessEx2Game();
    
    virtual void OnInit();
    virtual void OnKeyDown(SDL_KeyboardEvent& event);
    virtual void OnKeyUp(SDL_KeyboardEvent& event);
    virtual void OnUpdate();
    virtual void OnRender(Graphics *graphics);
};
#endif /* ChessEx2Game_h */
