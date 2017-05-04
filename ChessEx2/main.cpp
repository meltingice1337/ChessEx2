/*#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//Screen dimension constants
const int WIDTH = 800;
const int HEIGHT = 600;*/
#include "ChessEx2Game.h"

int main()
{
    /*
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDl could not initialize" << SDL_GetError() << std::endl;
    }
    
    SDL_Window *window = SDL_CreateWindow("sdl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    
    if( window == NULL)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    
    SDL_Event windowEvent;
    
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = IMG_Load("/Users/dariuscostolas/Desktop/ChessEx2/ChessEx2/assets/tileset.png");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Rect texr; texr.x = 0; texr.y = 0; texr.w = 128; texr.h = 128;
    while(true)
    {
        if( SDL_PollEvent(&windowEvent))
        {
            if(SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }
        SDL_RenderCopy(renderer, texture, &texr, &texr);
        SDL_RenderPresent(renderer);
    }
    
    // cleanup
    
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();*/
    std::shared_ptr<ChessEx2Game> game(new ChessEx2Game("SAH", 400, 400));
    game->Run();
    return 0;
}
