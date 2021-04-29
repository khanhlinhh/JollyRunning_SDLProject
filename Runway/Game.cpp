#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "WindowFunctions.h"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "ScrollingBackground.hpp"
#include "Hindrances.hpp"
#include "MenuGame.hpp"
#include "Score.hpp"

using namespace std;

Background TBackground;
GameObject TCharacter;
Menu menuGame;

vector<Animals> TAnimal;
SDL_Texture *Animal1, *Animal2, *Animal3, *Animal4, *Animal5, *Animal6, *Animal7, *Animal8, *Animal9;

Score score;

int randAnimal;

Game::Game()
{}
Game::~Game()
{}

void Game::init (const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (TTF_Init() < 0)
    {
        cout << "Error init TTF: " << TTF_GetError() << endl;
    }
    
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

    TBackground = Background("/Users/timmy/Desktop/Runway/Image/background.png", renderer);
    menuGame = Menu(renderer);
    TCharacter = GameObject("/Users/timmy/Desktop/Runway/Image/character.png", renderer);
    Animal1 = TextureManager::LoadTexture(texturesheet1, renderer);
    Animal2 = TextureManager::LoadTexture(texturesheet2, renderer);
    Animal3 = TextureManager::LoadTexture(texturesheet3, renderer);
    Animal4 = TextureManager::LoadTexture(texturesheet4, renderer);
    Animal5 = TextureManager::LoadTexture(texturesheet5, renderer);
    Animal6 = TextureManager::LoadTexture(texturesheet6, renderer);
    Animal7 = TextureManager::LoadTexture(texturesheet7, renderer);
    Animal8 = TextureManager::LoadTexture(texturesheet8, renderer);
    Animal9 = TextureManager::LoadTexture(texturesheet9, renderer);
    
    menuGame.RenderMenu();
    score = Score(renderer);
}

void Game::Timers()
{
    frameTime = SDL_GetTicks() - frameStart;
            
    if (frameDelay > frameTime)
    {
        SDL_Delay(frameDelay-frameTime);
    }
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
    if (keyState[SDL_SCANCODE_S])
    {
        startGame = true;
    }
    if (keyState[SDL_SCANCODE_LEFT])
    {
        TCharacter.goLeft();
    }
    else
    {
        if (keyState[SDL_SCANCODE_RIGHT])
        {
            TCharacter.goRight();
        }
        else
        {
            TCharacter.stay();
        }
    }
    TCharacter.Animation();
}

void Game::update()
{
    if (startGame && gameOver == false)
    {
        menuGame.destroyStart();
        count++;
        if (count == mark)
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
                    ani = Animals(renderer, Animal8, randAnimal);
                    break;
                case 8:
                    ani = Animals(renderer, Animal9, randAnimal);
                    break;
            }
            TAnimal.push_back(ani);
            count = 0;
            level++;
        }
        if (level == temp)
        {
            mark--;
            if (mark < 40) mark = 40;
            level = 1;
            TBackground.velocityBackground++;
            if (TBackground.velocityBackground == maxSpeed)
            {
                TBackground.velocityBackground = maxSpeed;
            }
        }
        
        for (int i = 0 ; i < TAnimal.size(); i++)
        {
            //TAnimal[i].Appear(TBackground.velocityBackground);
            TAnimal[i].Appear(TBackground.velocityBackground);
            if(TAnimal[i].checkCollision(TCharacter))
            {
                score.scoregame -= scorelost;
                score.GetCurrentLives();
                if (score.lives < 0)
                {
                    gameOver = true;
                }
            }
        }
        if (count % 2 == 0 && gameOver == false)
        {
            score.scoregame++;
            score.GetCurrentScore(renderer);
        }
        if (!TAnimal.empty() && TAnimal[0].animalClipsPos.y > SCREEN_HEIGHT)
        {
            TAnimal.erase(TAnimal.begin());
        }
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    TBackground.scrollingBackground(renderer, NULL);
    if (!TAnimal.empty())
    {
        for (int i = 0 ; i < TAnimal.size(); i++)
        {
            TAnimal[i].render_Copy();
        }
    }
    TCharacter.renderCopy();
    menuGame.RenderMenu();
    if (gameOver == true)
    {
        menuGame.RenderGameOver();
    }
    score.renderCopyText();
    score.RenderCopyScore();
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;
    TTF_Quit();
    SDL_Quit();
    cout << "Game cleaned!" << endl;
}


