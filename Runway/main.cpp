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

    game.init("JollyRunning", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, true);
    
    while (game.running())
    {
        game.handleEvents();
        game.timers();
        game.update();
        game.render();
    }
    game.clean();
}
