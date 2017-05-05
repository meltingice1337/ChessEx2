//
//  Sprite.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/4/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h

#include "Graphics.h"
#include <memory>
#include <iostream>

class Sprite
{
public:
    Sprite(std::string fileName);
    Sprite();
    ~Sprite();
    void LoadFromFile(std::string fileName);
    void Render(std::shared_ptr<Graphics> graphics, int x, int y);
    void SetClip(int x, int y, int width, int height);
    void SetWidth(int width, int height);
private:
    std::unique_ptr<SDL_Surface, SDL_Deleter> surface;
    std::unique_ptr<SDL_Texture, SDL_Deleter> texture;
    std::unique_ptr<SDL_Rect> clip;
    int width, height;
};

#endif /* Sprite_h */
