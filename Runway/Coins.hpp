#ifndef Coins_hpp
#define Coins_hpp

#include <stdio.h>
#include "TextureManager.hpp"
#include "Player.hpp"

struct Coins
{
    Coins();
    Coins (SDL_Texture *Coin, SDL_Renderer *rend, int randLine);
    
    SDL_Renderer *renderer;
    SDL_Texture *TCoins;
    SDL_Rect CoinRect, CoinPos;
    int frameWidth, frameHeight;
    int textureWidth, textureHeight;
    int frameTime = 0;
    
    void Appear(int &velocity);
    void Animation();
    bool checkCollision(GameObject &Character);
    void renderCopyCoin();
    void destroyCoin();
};

#endif
