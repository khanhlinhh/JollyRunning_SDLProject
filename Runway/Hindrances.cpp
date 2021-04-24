#include "Hindrances.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
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
    animalClipsPos.y += velocity;
}

/*int Animals::GetAnimalY ()
{
    return animalClipsPos.y;
}*/

bool Animals::checkCollision(GameObject &Character)
{
    if (animalClipsPos.y == Character.charPosition.y && (Character.charPosition.x + SIZE_CHARACTER > animalClipsPos.x || Character.charPosition.x < animalClipsPos.x + textureWidth))
    {
        cout << "Oops" << endl;
        return true;
    }
    return false;
}

void Animals::render_Copy()
{
    SDL_RenderCopy(renderer,animalText, &animalClipsRect, &animalClipsPos);
}
