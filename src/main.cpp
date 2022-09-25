#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <iostream>
#include <headers/screen.h>


int main(int argc, char* argv[]){
    Screen screen;

    screen.run();

    return 0;
}