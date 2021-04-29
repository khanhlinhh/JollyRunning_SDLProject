#ifndef MenuGame_hpp
#define MenuGame_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
class Menu
{
public:
    Menu();
    Menu(SDL_Renderer* ren);
    
    ~Menu();
    
    SDL_Renderer* renderer;
    SDL_Texture* TLogo;
    SDL_Texture* TStartgame;
    SDL_Texture* TPressStart;
    SDL_Texture* TGameOver;
    SDL_Rect LogoRect, StartGameRect, pressStartRect, GameOverRect;
    SDL_Rect LogoPos;
    int textureWidth, textureHeight;
    TTF_Font *Font, *Fontsmall;
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *startGameSurface;
    SDL_Surface *pressStartSurface;
    SDL_Surface *GameOverSurface;
    
    void RenderMenu();
    void RenderGameOver();
    void destroyStart();
    void destroyGameOver();
};

#endif
