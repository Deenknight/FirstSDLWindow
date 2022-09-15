#include "headers/screen.h"

Screen::Screen(){
    _window = nullptr;
    _renderer = nullptr;

    _screenWidth = 1024;
    _screenHeight = 600;

    _screenState = ScreenState::PLAY;
};

Screen::~Screen(){};

void Screen::run(){
    init("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
    
}

void Screen::init(const char* title, int x, int y, int w, int h, Uint32 flags){
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow(title, x, y, w, h, flags);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
}

void Screen::displayLoop(){
    while (_screenState != ScreenState::EXIT){
        handleEvents();
    }
}

void Screen::handleEvents(){
    SDL_Event evnt;
    SDL_PollEvent(&evnt);

    switch(evnt.type){
        case SDL_QUIT:
            _screenState = ScreenState::EXIT;
            break;
    }
}
