#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "WindowFunctions.h"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "ScrollingBackground.hpp"
#include "Hindrances.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

Game game;

int main (int argc, const char* argv[])
{
    srand((int)time(0));
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    
    Uint32 frameStart;
    int frameTime;

    game.init("RUNWAY", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, true);
    
    while (game.running())
    {
        frameStart = SDL_GetTicks();
        
        game.handleEvents();
        game.update();
        game.render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay-frameTime);
        }
    }
    game.clean();
}
