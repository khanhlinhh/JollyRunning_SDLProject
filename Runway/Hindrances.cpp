#include "Hindrances.hpp"
#include "ScrollingBackground.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "WindowFunctions.h"
#include "Game.hpp"
#include <vector>
#include <iostream>

using namespace std;

Animals::Animals(){}
Animals::~Animals(){}

Animals::Animals(SDL_Renderer* ren, SDL_Texture* Texture, int randAnimal):renderer(ren), animalText(Texture)
{
    int randLine = rand() % numLine;
    SDL_QueryTexture(animalText, NULL, NULL, &animalClipsPos.w, &animalClipsPos.h);
    animalClipsPos.x = Line[randLine];
    animalClipsPos.y = -animalClipsPos.h;
}

void Animals::Appear(int &velocity)
{
    animalClipsPos.y += velocity;
}

bool Animals::checkCollision(GameObject &Character)
{
    if (animalClipsPos.y == Character.charPosition.y)
    {
        if (animalClipsPos.x >= Character.charPosition.x && animalClipsPos.x <= Character.charPosition.x + SIZE_CHARACTER)
        {
            cout << "Oops" << endl;
            return true;
        }
        else if (animalClipsPos.x + animalClipsPos.w <= Character.charPosition.x + SIZE_CHARACTER && animalClipsPos.x + animalClipsPos.w >= Character.charPosition.x)
        {
            
            cout << "Oops" << endl;
            return true;
        }
    }

    return false;
}

void Animals::render_Copy()
{
    SDL_RenderCopy(renderer,animalText, NULL, &animalClipsPos);
}

void Animals::destroyAnimals()
{
    SDL_DestroyTexture(animalText);
}
