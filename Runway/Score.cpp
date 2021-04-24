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
    
    SDL_QueryTexture(Text, NULL, NULL, &textRect.w, &textRect.h);
}

void Score::GetCurrentScore(SDL_Renderer *render)
{
    renderer = render;
    string SCurrentScore = to_string(scoregame);
    const char *CurrentScore = SCurrentScore.c_str();
    scoreSurface = TTF_RenderText_Solid(Font, CurrentScore, color);
    TCurrentScore = SDL_CreateTextureFromSurface(render, scoreSurface);
    scoreRect.x = ScoreGetX;
    scoreRect.y = ScoreGetY;
    
    SDL_QueryTexture(TCurrentScore, NULL, NULL, &scoreRect.w, &scoreRect.h);
}

void Score::renderCopyText()
{
    SDL_RenderCopy(renderer, Text, NULL, &textRect);
    SDL_RenderCopy(renderer, TCurrentScore, NULL, &scoreRect);
}


