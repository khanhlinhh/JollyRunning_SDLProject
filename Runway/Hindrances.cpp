#include "Hindrances.hpp"
#include "TextureManager.hpp"
#include "WindowFunctions.h"
#include "Game.hpp"
#include <vector>
#include <iostream>

using namespace std;

Animals::Animals(){}
Animals::~Animals(){}

Animals::Animals(SDL_Renderer* ren, SDL_Texture* Texture, int randAnimal): renderer(ren), animalText(Texture)
{
    int randLine = rand() % numLine;
//    renderer = ren;
//    animalText = Texture;
    SDL_QueryTexture(animalText, NULL, NULL, &textureWidth, &textureHeight);
    animalClipsRect.w = textureWidth;
    animalClipsRect.h = textureHeight;
    animalClipsPos.w = animalWidth[randAnimal];
    animalClipsPos.h = animalHeight[randAnimal];
    animalClipsPos.x = Line[randLine];
    animalClipsPos.y = -textureHeight;
}

void Animals::Appear()
{
    velocity = 2 ;
    animalClipsPos.y += velocity;
}

int Animals::GetY ()
{
    return animalClipsPos.y;
}

void Animals::render_Copy()
{
    SDL_RenderCopy(renderer,animalText, &animalClipsRect, &animalClipsPos);
}
