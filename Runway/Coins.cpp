#include "Coins.hpp"
#include "TextureManager.hpp"
#include "WindowFunctions.h"
#include "Game.hpp"
#include "Player.hpp"

Coins::Coins(){}

Coins::Coins(SDL_Texture *Coin, SDL_Renderer *ren, int randLine):renderer(ren), TCoins(Coin)
{
    SDL_QueryTexture(TCoins, NULL, NULL, &textureWidth, &textureHeight);
    frameWidth = textureWidth/6;
    frameHeight = textureHeight;
    
    CoinPos.y = -textureHeight;
    CoinPos.x = LineCoin[randLine];
    CoinPos.w = frameWidth;
    CoinPos.h = frameHeight;
    CoinRect.x = CoinRect.y = textureWidth/6;
    CoinRect.w = frameWidth;
    CoinRect.h = frameHeight;
}

void Coins::Appear(int &velocity)
{
    CoinPos.y += velocity;
}

bool Coins::checkCollision(GameObject &Character)
{
    if (CoinPos.y == Character.charPosition.y && CoinPos.x >= Character.charPosition.x && CoinPos.x <= Character.charPosition.x + SIZE_CHARACTER)
    {
        cout << "Yay" << endl;
        return true;
    }
    if (CoinPos.y == Character.charPosition.y && CoinPos.x + CoinPos.w <= Character.charPosition.x + SIZE_CHARACTER && CoinPos.x + CoinPos.w >= Character.charPosition.x)
    {
        cout << "Yay" << endl;
        return true;
    }
    return false;
}

void Coins::Animation()
{
    frameTime++;
    if (frameTime >= 10)
    {
        frameTime = 0;
        CoinRect.x += frameWidth;
        if (CoinRect.x >= textureWidth)
        {
            CoinRect.x = 0;
        }
    }
}

void Coins::renderCopyCoin()
{
    SDL_RenderCopy(renderer, TCoins, &CoinRect, &CoinPos);
}

void Coins::destroyCoin()
{
    SDL_DestroyTexture(TCoins);
}
