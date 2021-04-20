#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <iostream>
#include "Game.hpp"
#include "WindowFunctions.h"

struct TextureManager
{
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
};
#endif
