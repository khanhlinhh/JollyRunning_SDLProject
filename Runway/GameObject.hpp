#ifndef GameObject_hpp
#define GameObject_hpp

#include <iostream>
#include "Game.hpp"
struct GameObject
{
    GameObject(const char* texturesheet, SDL_Renderer* ren);
    ~GameObject();
    
    SDL_Renderer* renderer;
    SDL_Texture *charText;
    SDL_Rect charRect;
    SDL_Rect charPosition;
    int frameWidth, frameHeight;
    int textureWidth, textureHeight;
    int frameTime = 0;
    int velocity = 0;
    
    void stay();
    void goLeft();
    void goRight();
    void Animation(int &frameTime);
    
    void renderCopy();
};

#endif
