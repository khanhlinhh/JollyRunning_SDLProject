#include "Score.hpp"
#include "WindowFunctions.h"
#include "TextureManager.hpp"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Score::Score(){}

Score::~Score(){}

Score::Score(SDL_Renderer *render)
{
    renderer = render;
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

void Score::getHighScore()
{
    int PrevHighScore;
    ifstream myfile ("/Users/timmy/Desktop/Runway/HighScore.txt");
    if (myfile.is_open())
    {
        myfile >> PrevHighScore;
        if (scoregame > PrevHighScore)
        {
            ofstream file("/Users/timmy/Desktop/Runway/HighScore.txt");
            file << scoregame << endl;
        }
    }
}

void Score::printHightScore(SDL_Renderer *ren)
{
    renderer = ren;
    int HighScore = 0;
    ifstream myfile ("/Users/timmy/Desktop/Runway/HighScore.txt");
    if (myfile.is_open())
    {
        myfile >> HighScore;
    }
    cout << HighScore << endl;
    string SHighScore = to_string(HighScore);
    const char *highScore = SHighScore.c_str();
    highScoreSurface = TTF_RenderText_Solid(FontBig, highScore, color);
    THighScore = SDL_CreateTextureFromSurface(ren, highScoreSurface);
    SDL_QueryTexture(THighScore, NULL, NULL, &HighScoreRect.w, &HighScoreRect.h);
    HighScoreRect.x = (SCREEN_WIDTH)/2 + 20;
    HighScoreRect.y = (SCREEN_HEIGHT)/2 - 5;
    
    
    TTrophy = TextureManager::LoadTexture("/Users/timmy/Desktop/Runway/Image/trophy.png", ren);
    SDL_QueryTexture(TTrophy, NULL, NULL, &TrophyRect.w, &TrophyRect.h);
    TrophyRect.x = (SCREEN_WIDTH)/2 - 70;
    TrophyRect.y = (SCREEN_HEIGHT)/2 - 15;
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

void Score::RenderHighScore()
{
    SDL_RenderCopy(renderer, TTrophy, NULL, &TrophyRect);
    SDL_RenderCopy(renderer, THighScore, NULL, &HighScoreRect);
}


