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
std::vector<std::shared_ptr <Sprite> > sprites;
int pos[10][2];
void World::Initialize(uint32_t width, uint32_t height)
{
    for(int i=0;i<10;i++)
    {
        std::shared_ptr<Sprite> sprite(new Sprite("/Users/dariuscostolas/workspace/ChessEx2/ChessEx2/assets/tileset.png"));
        sprite->SetClip(0, 0, 128, 128);
        sprites.push_back(sprite);
        if(i > 0)
        {
            pos[i][0] = pos[i-1][0] + 122;
            if(pos[i][0] > 800)
            {
                pos[i][0] = 0;
                pos[i][1]+= 128;
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
    for(int i=0;i<10;i++)
    {
        sprites[i]->Render(graphics, pos[i][0], pos[i][1]);
        
    }
    graphics->ClearScreen();
}
