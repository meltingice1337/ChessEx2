//
//  Graphics.cpp
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include "Graphics.h"

Graphics::Graphics(SDL_Window& window)
:window(window)
{
    this->renderer = RendererPtr(SDL_CreateRenderer(&window, -1, 0));
}

SDL_Texture *Graphics::GetTextureFromSurface(SDL_Surface& surface)
{
    return SDL_CreateTextureFromSurface(renderer.get(), &surface);
}


void Graphics::Draw(SDL_Texture &texture, int x, int y, int w, int h)
{
    SDL_Rect textureRectangle;
    textureRectangle.x = x;
    textureRectangle.y = y;
    textureRectangle.w = w;
    textureRectangle.h = h;
    
    SDL_RenderCopy(renderer.get(), &texture, NULL, &textureRectangle);
    SDL_RenderPresent(renderer.get());
}

void Graphics::Draw(SDL_Texture &texture, int x, int y, int w, int h, SDL_Rect& clip)
{
    SDL_Rect textureRectangle;
    textureRectangle.x = x;
    textureRectangle.y = y;
    textureRectangle.w = w;
    textureRectangle.h = h;
    
    SDL_RenderCopy(renderer.get(), &texture, &clip, &textureRectangle);
}

void Graphics::ClearScreen()
{
    SDL_RenderPresent(renderer.get());
}
