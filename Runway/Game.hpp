#ifndef Class_hpp
#define Class_hpp
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "WindowFunctions.h"

class Game
{
public:
    Game();
    ~Game();
    
    void init (const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() {return isRunning;};
    
    const char* texturesheet1 = "/Users/timmy/Desktop/Runway/Image/cat.png";
    const char* texturesheet2 = "/Users/timmy/Desktop/Runway/Image/pig.png";
    const char* texturesheet3 = "/Users/timmy/Desktop/Runway/Image/monkey.png";
    const char* texturesheet4 = "/Users/timmy/Desktop/Runway/Image/cat.png";
    const char* texturesheet5 = "/Users/timmy/Desktop/Runway/Image/dog.png";
    const char* texturesheet6 = "/Users/timmy/Desktop/Runway/Image/goat.png";
    const char* texturesheet7 = "/Users/timmy/Desktop/Runway/Image/chicken.png";
    const char* texturesheet8 = "/Users/timmy/Desktop/Runway/Image/koala.png";
    const char* texturesheet9 = "/Users/timmy/Desktop/Runway/Image/cow.png";
    
private:
    int count = 50;
    int level = 1;
    int temp = 120;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
};
#endif
