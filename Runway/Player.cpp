#include "Player.hpp"
#include "TextureManager.hpp"
#include "WindowFunctions.h"
#include "Game.hpp"

using namespace std;

GameObject::GameObject(){}
GameObject::~GameObject(){}

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren)
{
    renderer = ren;
    charText = TextureManager::LoadTexture(texturesheet, ren);
    SDL_QueryTexture(charText, NULL, NULL, &textureWidth, &textureHeight);
    frameWidth = textureWidth/3;
    frameHeight = textureHeight/3;
    
    charPosition.y = STARTING_POINT;
    charPosition.w = charPosition.h = SIZE_CHARACTER;
    charPosition.x = (SCREEN_WIDTH - charPosition.w)/2;
    charRect.x = charRect.y = GO_STRAIGHT;
    charRect.w = frameWidth;
    charRect.h = frameHeight;
}

void GameObject::stay()
{
    velocity = 0;
    charRect.y = GO_STRAIGHT;
}

void GameObject::goLeft()
{
    velocity = -5;
    charRect.y = GO_LEFT;
    charPosition.x += velocity;
    if (charPosition.x < 50)
    {
        charPosition.x = 50;
    }
}

void GameObject::goRight()
{
    velocity = 5;
    charRect.y = GO_RIGHT;
    charPosition.x += velocity;
    if (charPosition.x > 230)
    {
        charPosition.x = 230;
    }
    
}

void GameObject::Animation()
{
    frameTime++;
    if (frameTime >= 10)
    {
        frameTime = 0;
        charRect.x += frameWidth;
        if (charRect.x >= textureWidth)
        {
            charRect.x = 0;
        }
    }
}

void GameObject::renderCopy()
{
    SDL_RenderCopy(renderer, charText, &charRect, &charPosition);
}

