#ifndef Hindrances_hpp
#define Hindrances_hpp
#include "Game.hpp"
#include "WindowFunctions.h"
#include "ScrollingBackground.hpp"
#include "Player.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Animals
{
public:
    Animals();
    Animals(SDL_Renderer* ren, SDL_Texture* Texture, int randAnimal);
    ~Animals();

    SDL_Renderer *renderer;
    SDL_Texture *animalText;
    SDL_Rect animalClipsPos;
    
    void Appear(int &velocity);
    bool checkCollision(GameObject &Character);
    void render_Copy();
    void destroyAnimals();
};
#endif
