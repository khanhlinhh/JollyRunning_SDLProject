#ifndef Score_hpp
#define Score_hpp

#include <iostream>
#include <SDL2/SDL_ttf.h>

struct Score
{
    Score();
    Score(SDL_Renderer* render);
    ~Score();
    
    int scoregame = 0;
    int lives = 3;
    TTF_Font *Font;
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *livesSurface;
    SDL_Surface *livesCountSurface;
    SDL_Surface *textSurface;
    SDL_Surface *scoreSurface;
    SDL_Texture *TLives;
    SDL_Texture *TLivesCount;
    SDL_Texture *Text;
    SDL_Texture *TCurrentScore;
    SDL_Renderer *renderer;
    SDL_Rect textRect;
    SDL_Rect livesRect;
    SDL_Rect livescountRect;
    SDL_Rect scoreRect;
    
    void GetCurrentScore(SDL_Renderer *render);
    void renderCopyText();
    void RenderCopyScore();
};

#endif
