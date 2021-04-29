#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include "Game.hpp"
struct GameObject
{
    GameObject();
    GameObject(const char* texturesheet, SDL_Renderer* ren);
    ~GameObject();
    
    SDL_Renderer* renderer;
    SDL_Texture *charText;
    SDL_Rect charRect;
    SDL_Rect charPosition;
    int frameWidth, frameHeight;
    int textureWidth, textureHeight;
    int velocity = 0;
    int frameTime = 0;
    
    void stay();
    void goLeft();
    void goRight();
    void Animation();
    
    void renderCopy();
};

#endif
