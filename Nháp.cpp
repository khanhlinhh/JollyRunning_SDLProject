#include "Hindrances.hpp"
#include "TextureManager.hpp"
#include "WindowFunctions.h"
#include "Game.hpp"
#include <vector>
#include <iostream>

using namespace std;

Animals::Animals(){}
Animals::~Animals(){}

Animals::Animals(SDL_Renderer* ren)
{
    const char* texturesheet;
    int randAnimal = rand() % animalNumbers;
    int randLine = rand() % numLine;
    renderer = ren;
    switch (randAnimal)
    {
        case 0:
            texturesheet = texturesheet1;
            break;
            
        case 1:
            texturesheet = texturesheet2;
            break;
            
        case 2:
            texturesheet = texturesheet3;
            break;
            
        case 3:
            texturesheet = texturesheet4;
            break;
            
        case 4:
            texturesheet = texturesheet5;
            break;
            
        case 5:
            texturesheet = texturesheet6;
            break;
            
        case 6:
            texturesheet = texturesheet7;
            break;
            
        case 7:
            texturesheet = texturesheet8;
            break;
            
        case 8:
            texturesheet = texturesheet9;
            break;
    }
    animalText = TextureManager::LoadTexture(texturesheet, ren);
    SDL_QueryTexture(animalText, NULL, NULL, &textureWidth, &textureHeight);
    frameWidth = textureWidth;
    frameHeight = textureHeight;
    animalClipsRect.w = frameWidth;
    animalClipsRect.h = frameHeight;
    animalClipsPos.w = animalWidth[randAnimal];
    animalClipsPos.h = animalHeight[randAnimal];
    animalClipsPos.x = Line[randLine];
    animalClipsPos.y = -frameHeight;
}

void Animals::Appear()
{
    velocity = 1;
    animalClipsPos.y += velocity;
}

int Animals::GetY ()
{
    return animalClipsPos.y;
}

void Animals::renderCopy()
{
    SDL_RenderCopy(renderer,animalText, &animalClipsRect, &animalClipsPos);
}
