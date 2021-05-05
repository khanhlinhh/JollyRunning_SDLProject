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
    TTF_Font *Font = TTF_OpenFont("/Users/timmy/Desktop/Runway/CCOverbyteOff-Regular.ttf", 30);
    TTF_Font *FontBig = TTF_OpenFont("/Users/timmy/Desktop/Runway/CCOverbyteOff-Regular.ttf", 50);
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *livesSurface;
    SDL_Surface *livesCountSurface;
    SDL_Surface *textSurface;
    SDL_Surface *scoreSurface;
    SDL_Surface *highScoreSurface;
    
    SDL_Texture *TLives;
    SDL_Texture *TLivesCount;
    SDL_Texture *Text;
    SDL_Texture *TCurrentScore;
    SDL_Texture *THighScore;
    SDL_Texture *TTrophy;
    SDL_Renderer *renderer;
    
    SDL_Rect textRect;
    SDL_Rect livesRect;
    SDL_Rect livescountRect;
    SDL_Rect scoreRect;
    SDL_Rect HighScoreRect;
    SDL_Rect TrophyRect;
    
    void GetCurrentScore(SDL_Renderer *render);
    void getHighScore();
    void printHightScore(SDL_Renderer *ren);
    void renderCopyText();
    void RenderCopyScore();
    void RenderHighScore();
};

#endif
