//
//  World.cpp
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include "World.h"
#include <iostream>

World::~World()
{
#ifdef _DEBUG
    std::cout << "Destroying the World" << std::endl;
#endif

}
SDL_Texture *texture;
SDL_Surface *image;
void World::Initialize(uint32_t width, uint32_t height)
{
    image = IMG_Load("/Users/dariuscostolas/Desktop/ChessEx2/ChessEx2/assets/tileset.png");
    m_width = width;
    m_height = height;
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

void World::OnRender(Graphics *graphics)
{
    if(!texture)
       texture = graphics->GetTextureFromSurface(image);
    graphics->Draw(texture, 0, 0, 128, 128);
}
