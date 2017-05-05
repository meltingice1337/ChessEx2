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
std::shared_ptr <Sprite> sprite1;
std::shared_ptr <Sprite> sprite2;
int pos[64][2];
void World::Initialize(uint32_t width, uint32_t height)
{
    sprite1 = std::make_shared<Sprite>("/Users/dariuscostolas/workspace/ChessEx2/ChessEx2/assets/tileset.png");
    sprite1->SetClip(0, 0, 100, 75);
    sprite2 = std::make_shared<Sprite>("/Users/dariuscostolas/workspace/ChessEx2/ChessEx2/assets/tileset.png");
    sprite2->SetClip(128, 0, 100, 75);

    for(int i=0;i<64;i++)
    {
        if(i > 0)
        {
            pos[i][0] = pos[i-1][0] + 100;
            pos[i][1] = pos[i-1][1];
            if(pos[i][0] >= 800)
            {
                pos[i][0] = 0;
                pos[i][1]+= 75;
            }
        }
        else
        {
            pos[i][0]= pos[i][1] = 0;
        }
    }
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
    int current = 0;
    for(int i=0;i<64;i++)
    {
        if(i % 2 == current)
            sprite1->Render(graphics, pos[i][0], pos[i][1]);
        else
            sprite2->Render(graphics, pos[i][0], pos[i][1]);

        current = (i+1) % 8 == 0 ? current ^ 1 : current;
    }
    graphics->ClearScreen();
}
