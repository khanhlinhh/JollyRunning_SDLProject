#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
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
#include "Coins.hpp"

using namespace std;

Background TBackground;
GameObject TCharacter;
Menu menuGame;
vector <Coins> CoinsCollect;

vector<Animals> TAnimal;
SDL_Texture *Animal1, *Animal2, *Animal3, *Animal4, *Animal5, *Animal6, *Animal7, *Animal8, *Animal9;
SDL_Texture *CoinTexture;

Score score;

int randAnimal;
int randLine;

Game::Game()
{}
Game::~Game()
{}

void Game::init (const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
   {
       cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
   }
    
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
    
    CoinTexture = TextureManager::LoadTexture("/Users/timmy/Desktop/Runway/Image/coin.png", renderer);
    score = Score(renderer);
    
    BackgroundSound = Mix_LoadMUS( "/Users/timmy/Desktop/Runway/Sound/background music.wav");
    CoinCollectSound = Mix_LoadWAV("/Users/timmy/Desktop/Runway/Sound/coin-sound-effect.wav");
    CollisionSound = Mix_LoadWAV("/Users/timmy/Desktop/Runway/Sound/roblox-death-sound_1.wav");
    GameOverSound = Mix_LoadWAV("/Users/timmy/Desktop/Runway/Sound/gameover.wav");
    
    if (!Mix_PlayingMusic())
    {
        Mix_PlayMusic(BackgroundSound, -1);
    }
    menuGame.RenderMenu();
}

void Game::timers()
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
    
    if (keyState[SDL_SCANCODE_P] && gameOver)
    {
        ifStartOver = true;
        gameOver = false;
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
    if (!CoinsCollect.empty())
    {
        for (int i = 0; i < CoinsCollect.size(); i++)
        {
            CoinsCollect[i].Animation();
        }
    }
}

void Game::update()
{
    if (ifStartOver)
    {
        menuGame.destroygameStartOver();
        Mix_PlayMusic(BackgroundSound, -1);
        ifStartOver = false;
        score.scoregame = 0;
        score.lives = 3;
        startGame = true;
        SDL_SetTextureColorMod(TCharacter.charText, 255, 255, 255);
        SDL_SetTextureAlphaMod(TCharacter.charText, 250);
        TBackground.velocityBackground = 2;
        count = 0;
        level = 1;
        mark = 150;
        Mix_HaltChannel(-1);
    }
    if (startGame && gameOver == false)
    {
        menuGame.destroyStart();
        score.GetCurrentScore(renderer);
        count++;
        randLine = rand() % numLine;
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
        if (count == mark/2)
        {
            Coins coin;
            coin = Coins(CoinTexture ,renderer, randLine);
            CoinsCollect.push_back(coin);
        }
        
        if (level == temp)
        {
            mark -= 20;
            if (mark < 50)
            {
                mark = 50;
            }
            level = 1;
            TBackground.velocityBackground++;
            if (TBackground.velocityBackground == maxSpeed)
            {
                TBackground.velocityBackground = maxSpeed;
            }
            //test++;
            //cout << test << endl;
        }
        
        if (!CoinsCollect.empty())
        {
            if (CoinsCollect[0].checkCollision(TCharacter))
            {
                Mix_PlayChannel(1, CoinCollectSound, 0);
                score.scoregame++;
                score.GetCurrentScore(renderer);
                CoinsCollect.erase(CoinsCollect.begin());
                
            }
        }
        
        if (!TAnimal.empty())
        {
            if(TAnimal[0].checkCollision(TCharacter) && gameOver == false)
            {
                SDL_SetTextureColorMod(TCharacter.charText, 255, 0, 0);
                SDL_SetTextureAlphaMod(TCharacter.charText, 70);
                SDL_SetTextureAlphaMod(TAnimal[0].animalText, 70);
                Mix_PlayChannel(2, CollisionSound, 0);
                score.scoregame -= scorelost;
                if (score.scoregame <= 0)
                {
                    score.scoregame = 0;
                }
                score.lives--;
                if (score.lives < 0)
                {
                    score.lives = 0;
                    gameOver = true;
                    startGame = false;
                }
            }
            else
            {
                SDL_SetTextureColorMod(TCharacter.charText, 255, 255, 255);
                SDL_SetTextureAlphaMod(TCharacter.charText, 250);
                SDL_SetTextureAlphaMod(TAnimal[0].animalText, 250);
            }
        }
        
        if (!CoinsCollect.empty())
        {
            for (int i = 0; i < CoinsCollect.size(); i++)
            {
                CoinsCollect[i].Appear(TBackground.velocityBackground);
            }
        }
        
        if (!TAnimal.empty())
        {
            for (int i = 0 ; i < TAnimal.size(); i++)
            {
                TAnimal[i].Appear(TBackground.velocityBackground);
            }
        }
        
        if (!TAnimal.empty() && TAnimal[0].animalClipsPos.y > TCharacter.charPosition.y + SIZE_CHARACTER)
        {
            TAnimal.erase(TAnimal.begin());
        }
        if (!CoinsCollect.empty() && CoinsCollect[0].CoinPos.y > TCharacter.charPosition.y + SIZE_CHARACTER)
        {
            CoinsCollect.erase(CoinsCollect.begin());
        }
  
        if (gameOver)
        {
            Mix_HaltMusic();
            score.getHighScore();
            score.printHightScore(renderer);
            TAnimal.clear();
            CoinsCollect.clear();
            Mix_PlayChannel(-1, GameOverSound, 0);
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
    if (!CoinsCollect.empty())
    {
        for (int i = 0; i < CoinsCollect.size(); i++)
        {
            CoinsCollect[i].renderCopyCoin();
        }
    }
    TCharacter.renderCopy();
    menuGame.RenderMenu();
    if (gameOver == true)
    {
        menuGame.RenderGameOver();
        score.RenderHighScore();
        menuGame.RenderGameStartOver();
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
    Mix_FreeMusic(BackgroundSound);
    Mix_FreeChunk(CollisionSound);
    Mix_FreeChunk(CoinCollectSound);
    Mix_FreeChunk(GameOverSound);
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
    cout << "Game cleaned!" << endl;
}


