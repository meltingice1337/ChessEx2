//
//  Graphics.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef Graphics_h
#define Graphics_h

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct SDL_Deleter {
    void operator()(SDL_Surface*  ptr) { if (ptr) SDL_FreeSurface(ptr); }
    void operator()(SDL_Texture*  ptr) { if (ptr) SDL_DestroyTexture(ptr); }
    void operator()(SDL_Renderer* ptr) { if (ptr) SDL_DestroyRenderer(ptr); }
    void operator()(SDL_Window*   ptr) { if (ptr) SDL_DestroyWindow(ptr); }
    void operator()(SDL_RWops*    ptr) { if (ptr) SDL_RWclose(ptr); }
};

class Graphics
{
public:
    Graphics(SDL_Window& window);
    void Draw(SDL_Texture& texture, int x, int y, int w, int h);
    void Draw(SDL_Texture& texture, int x, int y, int w, int h, SDL_Rect& clip);
    void ClearScreen();
    SDL_Texture *GetTextureFromSurface(SDL_Surface& surface);
private:
    std::unique_ptr<SDL_Renderer, SDL_Deleter> renderer;
    SDL_Window& window;
    
};
#endif /* Graphics_h */
