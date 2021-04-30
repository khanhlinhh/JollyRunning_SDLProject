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
    
    void Timers();
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() {return isRunning;};
    bool startGame = false;
    
    const char* texturesheet1 = "/Users/timmy/Desktop/Runway/Image/Hindrances/cat.png";
    const char* texturesheet2 = "/Users/timmy/Desktop/Runway/Image/Hindrances/pig.png";
    const char* texturesheet3 = "/Users/timmy/Desktop/Runway/Image/Hindrances/monkey.png";
    const char* texturesheet4 = "/Users/timmy/Desktop/Runway/Image/Hindrances/cat.png";
    const char* texturesheet5 = "/Users/timmy/Desktop/Runway/Image/Hindrances/dog.png";
    const char* texturesheet6 = "/Users/timmy/Desktop/Runway/Image/Hindrances/goat.png";
    const char* texturesheet7 = "/Users/timmy/Desktop/Runway/Image/Hindrances/chicken.png";
    const char* texturesheet8 = "/Users/timmy/Desktop/Runway/Image/Hindrances/koala.png";
    const char* texturesheet9 = "/Users/timmy/Desktop/Runway/Image/Hindrances/cow.png";
    
private:
    int count = 0;
    int level = 1;
    int temp = 12;
    int mark = 150;

    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    
    int startGametime = 0;
    
    bool isRunning;
    bool gameOver = false;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
};
#endif
