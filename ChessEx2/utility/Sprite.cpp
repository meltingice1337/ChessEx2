//
//  Sprite.cpp
//  ChessEx2
//
//  Created by Darius Costolas on 5/4/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite(std::string fileName)
{
    LoadFromFile(fileName);
}

Sprite::~Sprite()
{
    SDL_FreeSurface(surface.get());
    SDL_DestroyTexture(texture.get());
}

void Sprite::LoadFromFile(std::string fileName)
{
    if(!surface)
        surface = std::unique_ptr<SDL_Surface, SDL_Deleter>(IMG_Load(fileName.c_str()), SDL_Deleter());
    width = surface->w;
    height = surface->h;
}

void Sprite::Render(std::shared_ptr<Graphics> graphics, int x, int y)
{
    if(!texture)
        texture = std::unique_ptr<SDL_Texture, SDL_Deleter>(graphics->GetTextureFromSurface(*surface), SDL_Deleter());
    if(clip)
        graphics->Draw(*texture,x,y, width, height, *clip);
    else
        graphics->Draw(*texture, x, y, width, height);
}

void Sprite::SetClip(int x, int y, int width, int height)
{
    if(!clip)
        clip = std::unique_ptr<SDL_Rect>(new SDL_Rect());
    clip->x = x;
    clip->y = y;
    clip->w = width;
    clip->h = height;
    
    this->width = width;
    this->height = height;
}

void Sprite::SetWidth(int width, int height)
{
    this->width = width;
    this->height = height;
}
