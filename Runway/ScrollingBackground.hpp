#ifndef ScrollingBackground_hpp
#define ScrollingBackground_hpp

#include <iostream>
#include "TextureManager.hpp"

struct Background
{
    Background();
    Background(const char* texturesheet, SDL_Renderer* ren);
    
    ~Background();
    
    SDL_Renderer* renderer;
    SDL_Texture *TBackground;
    SDL_Rect Texture = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect* clip = NULL;
    int velocityBackground = 2;
    
    void scrollingBackground(SDL_Renderer* ren, SDL_Rect* clip);
};

#endif 
