#include "ScrollingBackground.hpp"
#include "WindowFunctions.h"
#include "TextureManager.hpp"

using namespace std;

Background::Background(const char* texturesheet, SDL_Renderer* ren)
{
    renderer = ren;
    TBackground = TextureManager::LoadTexture(texturesheet, ren);
}

void Background::scrollingBackground(SDL_Renderer* ren, SDL_Rect* clip)
{
    SDL_RenderCopy(renderer, TBackground, clip, &Texture);
    Texture.y -= SCREEN_HEIGHT;
    SDL_RenderCopy(renderer, TBackground, clip, &Texture);
    Texture.y += SCREEN_HEIGHT;
    Texture.y = (Texture.y + 2) % SCREEN_HEIGHT;
}

