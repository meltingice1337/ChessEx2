/*#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//Screen dimension constants
const int WIDTH = 800;
const int HEIGHT = 600;*/
#include "ChessEx2Game.h"

int main()
{
    std::unique_ptr<ChessEx2Game> game(new ChessEx2Game("The real cool game", 800, 600));
    game->Run();
    return 0;
}
