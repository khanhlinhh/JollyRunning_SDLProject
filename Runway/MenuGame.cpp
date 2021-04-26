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
    
    LogoRect.w = textureWidth;
    LogoRect.h = textureHeight;
    LogoRect.x = LogoRect.y = 0;
    LogoPos.y = LogoY;
    LogoPos.w = LogoRect.w = logoSizeWidth;
    LogoPos.h = LogoRect.h = logoSizeHeight;
    LogoPos.x = (SCREEN_WIDTH - LogoPos.w)/2;
    
    Font = TTF_OpenFont("/Users/timmy/Desktop/Runway/CCOverbyteOff-Regular.ttf", 50);
    Fontsmall = TTF_OpenFont("/Users/timmy/Desktop/Runway/CCOverbyteOff-Regular.ttf", 20);
    
    startGameSurface = TTF_RenderText_Solid(Font, "Jolly Running", color);
    TStartgame = SDL_CreateTextureFromSurface(ren, startGameSurface);
    StartGameRect.x = 20;
    StartGameRect.y = 330;
    
    pressStartSurface = TTF_RenderText_Solid(Fontsmall, "Press S to start", color);
    TPressStart = SDL_CreateTextureFromSurface(ren, pressStartSurface);
    pressStartRect.x = 110;
    pressStartRect.y = 400;
    
    
    
    SDL_QueryTexture(TStartgame, NULL, NULL, &StartGameRect.w, &StartGameRect.h);
    SDL_QueryTexture(TPressStart, NULL, NULL, &pressStartRect.w, &pressStartRect.h);
}

void Menu::RenderMenu()
{
    SDL_RenderCopy(renderer, TLogo, &LogoRect, &LogoPos);
    SDL_RenderCopy(renderer, TStartgame, NULL, &StartGameRect);
    SDL_RenderCopy(renderer, TPressStart, NULL, &pressStartRect);
}
