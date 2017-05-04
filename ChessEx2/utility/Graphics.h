//
//  Graphics.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef Graphics_h
#define Graphics_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Graphics
{
public:
    Graphics(SDL_Window *window);
    void Draw(SDL_Texture *texture, int x, int y, int w, int h);
    SDL_Texture *GetTextureFromSurface(SDL_Surface *surface);
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
};
#endif /* Graphics_h */
