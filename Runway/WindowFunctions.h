#ifndef WindowFuntions_h
#define WindowFuntions_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 358;
const int SCREEN_HEIGHT = 747;

//Size của nhân vật
const int characterWidth = 120;
const int characterHeight = 120;

//Đặt toạ độ y nhân vật khi start game
const int STARTING_POINT = 600;

//Toạ độ cắt texture character
const int GO_STRAIGHT = 80;
const int GO_LEFT = 0;
const int GO_RIGHT = 40;

//Size cuả nhân vật
const int SIZE_CHARACTER = 80;
//Số chướng ngại vật animals
const int animalNumbers = 9;
const int SIZE_ANIMALS = 150;

const int animalWidth[animalNumbers] = {71,70,90,76,83,88,66,98,153};
const int animalHeight[9] = {110,93,90,98,83,106,98,87,102};

//Toạ độ x xuất hiện animals
const int numLine = 3;
const int Line[numLine] = {80, 150, 215};
 
#endif
