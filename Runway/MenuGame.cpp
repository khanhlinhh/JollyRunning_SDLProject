#include "MenuGame.hpp"
#include "TextureManager.hpp"
#include "WindowFunctions.h"


Menu::Menu(){}
Menu::~Menu(){}

Menu::Menu(SDL_Renderer* ren)
{
    renderer = ren;
    const char* logo = "/Users/timmy/Desktop/Runway/Image/logo.png";
    TLogo = TextureManager::LoadTexture(logo, ren);
    
    SDL_QueryTexture(TLogo, NULL, NULL, &textureWidth, &textureHeight);
    
    LogoPos.y = LogoY;
    LogoPos.w = logoSizeWidth;
    LogoPos.h = logoSizeHeight;
    LogoPos.x = (SCREEN_WIDTH - LogoPos.w)/2;
    
    Font = TTF_OpenFont("/Users/timmy/Desktop/Runway/CCOverbyteOff-Regular.ttf", 50);
    Fontsmall = TTF_OpenFont("/Users/timmy/Desktop/Runway/CCOverbyteOff-Regular.ttf", 20);
    
    startGameSurface = TTF_RenderText_Solid(Font, "Jolly Running", color);
    TStartgame = SDL_CreateTextureFromSurface(ren, startGameSurface);
    StartGameRect.y = 330;
    
    pressStartSurface = TTF_RenderText_Solid(Fontsmall, "Press S to start", color);
    TPressStart = SDL_CreateTextureFromSurface(ren, pressStartSurface);
    pressStartRect.y = 400;
    
    GameOverSurface = TTF_RenderText_Solid(Font, "Game Over!", color);
    TGameOver = SDL_CreateTextureFromSurface(ren, GameOverSurface);
    
    SDL_QueryTexture(TStartgame, NULL, NULL, &StartGameRect.w, &StartGameRect.h);
    StartGameRect.x = (SCREEN_WIDTH - StartGameRect.w)/2;
    
    SDL_QueryTexture(TPressStart, NULL, NULL, &pressStartRect.w, &pressStartRect.h);
    pressStartRect.x = (SCREEN_WIDTH - pressStartRect.w)/2;
    
    SDL_QueryTexture(TGameOver, NULL, NULL, &GameOverRect.w, &GameOverRect.h);
    GameOverRect.x = (SCREEN_WIDTH - GameOverRect.w)/2;
    GameOverRect.y = (SCREEN_HEIGHT - GameOverRect.h)/2 - 50;
}

void Menu::RenderMenu()
{
    SDL_RenderCopy(renderer, TLogo, NULL, &LogoPos);
    SDL_RenderCopy(renderer, TStartgame, NULL, &StartGameRect);
    SDL_RenderCopy(renderer, TPressStart, NULL, &pressStartRect);
}

void Menu::RenderGameOver()
{
    SDL_RenderCopy(renderer, TGameOver, NULL, &GameOverRect);
}

void Menu::destroyStart()
{
    SDL_DestroyTexture(TLogo);
    SDL_DestroyTexture(TStartgame);
    SDL_DestroyTexture(TPressStart);
}

void Menu::destroyGameOver()
{
    SDL_DestroyTexture(TGameOver);
}
