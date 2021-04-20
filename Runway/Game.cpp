#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "WindowFunctions.h"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "ScrollingBackground.hpp"
#include "Hindrances.hpp"

using namespace std;

Background* TBackground;
GameObject* TCharacter;

//Animals *animal1, *animal2, *animal3, *animal4, *animal5, *animal6, *animal7, *animal8, *animal9;
SDL_Texture *Animal1, *Animal2, *Animal3, *Animal4, *Animal5, *Animal6, *Animal7, *Animal8, *Animal9;
int randAnimal;

int frameTime = 0;

Game::Game()
{}
Game::~Game()
{}

void Game::init (const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_SHOWN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    }
     else
     {
        isRunning = false;
     }

    TBackground = new Background("/Users/timmy/Desktop/Runway/Image/background.png", renderer);
    TCharacter = new GameObject("/Users/timmy/Desktop/Runway/Image/character.png", renderer);
    Animal1 = TextureManager::LoadTexture(texturesheet1, renderer);
    Animal2 = TextureManager::LoadTexture(texturesheet2, renderer);
    Animal3 = TextureManager::LoadTexture(texturesheet3, renderer);
    Animal4 = TextureManager::LoadTexture(texturesheet4, renderer);
    Animal5 = TextureManager::LoadTexture(texturesheet5, renderer);
    Animal6 = TextureManager::LoadTexture(texturesheet6, renderer);
    Animal7 = TextureManager::LoadTexture(texturesheet7, renderer);
    Animal8 = TextureManager::LoadTexture(texturesheet8, renderer);
    Animal9 = TextureManager::LoadTexture(texturesheet9, renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
    }
    if (keyState[SDL_SCANCODE_LEFT])
    {
            TCharacter->goLeft();
    }
    else
    {
        if (keyState[SDL_SCANCODE_RIGHT])
        {
            TCharacter->goRight();
        }
        else
        {
            TCharacter->stay();
        }
    }
    TCharacter->Animation(frameTime);
}
vector<Animals> TAnimal;

void Game::update()
{
    count++;
    if (count == 120)
    {
        Animals ani;
        randAnimal = rand() % animalNumbers;
        switch (randAnimal)
        {
            case 0:
                ani = Animals(renderer, Animal1, randAnimal);
                break;
            case 1:
                ani = Animals(renderer, Animal2, randAnimal);
                break;
            case 2:
                ani = Animals(renderer, Animal3, randAnimal);
                break;
            case 3:
                ani = Animals(renderer, Animal4, randAnimal);
                break;
            case 4:
                ani = Animals(renderer, Animal5, randAnimal);
                break;
            case 5:
                ani = Animals(renderer, Animal6, randAnimal);
                break;
            case 6:
                ani = Animals(renderer, Animal7, randAnimal);
                break;
            case 7:
                ani =  Animals(renderer, Animal8, randAnimal);
                break;
            case 8:
                ani = Animals(renderer, Animal9, randAnimal);
                break;
        }
        TAnimal.push_back(ani);
        count = 0;
    }
        //TAnimal->Appear();
    for (int i = 0 ; i < TAnimal.size(); i++)
    {
        TAnimal[i].Appear();
        TAnimal[i].GetY();
    }
    cout << TAnimal.size() << endl;
    if (!TAnimal.empty() && TAnimal[0].GetY() > SCREEN_HEIGHT)
    {
        TAnimal.erase(TAnimal.begin());
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    TBackground->scrollingBackground(renderer, NULL);
    TCharacter->renderCopy();
    for (int i = 0 ; i < TAnimal.size(); i++)
    {
        auto temp  = TAnimal[i];
        temp.render_Copy();
    }
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned!" << endl;
}


