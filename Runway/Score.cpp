#include "Score.hpp"
#include "WindowFunctions.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

Score::Score(){}

Score::~Score(){}

Score::Score(SDL_Renderer *render)
{
    renderer = render;
    Font = TTF_OpenFont("/Users/timmy/Desktop/Runway/CCOverbyteOff-Regular.ttf", 30);
    textSurface = TTF_RenderText_Solid(Font,"Score: ",color);
    Text = SDL_CreateTextureFromSurface(render, textSurface);
    textRect.y = ScoreTextGetY;
    textRect.x = ScoreTextGetX;
    
    livesSurface = TTF_RenderText_Solid(Font, "Lives: ", color);
    TLives = SDL_CreateTextureFromSurface(render, livesSurface);
    livesRect.y = livesRect.x = ScoreGetY;
    
    SDL_QueryTexture(Text, NULL, NULL, &textRect.w, &textRect.h);
    SDL_QueryTexture(Text, NULL, NULL, &livesRect.w, &livesRect.h);
}

void Score::GetCurrentScore(SDL_Renderer *render)
{
    renderer = render;
    string SCurrentScore = to_string(scoregame);
    const char *CurrentScore = SCurrentScore.c_str();
    Font = TTF_OpenFont("/Users/timmy/Desktop/Runway/CCOverbyteOff-Regular.ttf", 30);
    scoreSurface = TTF_RenderText_Solid(Font, CurrentScore, color);
    TCurrentScore = SDL_CreateTextureFromSurface(render, scoreSurface);
    scoreRect.x = ScoreGetX;
    scoreRect.y = ScoreGetY;
    
    string SCurrentLives = to_string(lives);
    const char *CurrentLives = SCurrentLives.c_str();

    livesCountSurface = TTF_RenderText_Solid(Font, CurrentLives, color);
    TLivesCount = SDL_CreateTextureFromSurface(render, livesCountSurface);
    livescountRect.x = 110;
    livescountRect.y = ScoreGetY;
    
    SDL_QueryTexture(TCurrentScore, NULL, NULL, &scoreRect.w, &scoreRect.h);
    SDL_QueryTexture(TLivesCount, NULL, NULL, &livescountRect.w, &livescountRect.h);
}

void Score::RenderCopyScore()
{
    SDL_RenderCopy(renderer, Text, NULL, &textRect);
    SDL_RenderCopy(renderer, TLives, NULL, &livesRect);
}

void Score::renderCopyText()
{
    SDL_RenderCopy(renderer, TCurrentScore, NULL, &scoreRect);
    SDL_RenderCopy(renderer, TLivesCount, NULL, &livescountRect);
}


