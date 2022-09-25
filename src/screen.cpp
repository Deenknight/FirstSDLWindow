#include "headers/screen.h"
#include "headers/bar.h"


Screen::Screen(){
    _window = nullptr;
    _renderer = nullptr;
    _bgc = {.r = 0, .g = 0, .b = 0, .a = 255};

    _screenWidth = 1024;
    _screenHeight = 600;

    _screenState = ScreenState::PLAY;

    _pixels = new Uint32[640 * 480];
    _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, 640, 480);

    
    

};

Screen::~Screen(){};

void Screen::run(){
    init("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
    
    displayLoop();
}

void Screen::init(const char* title, int x, int y, int w, int h, Uint32 flags){

    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow(title, x, y, w, h, flags);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_renderer, _bgc.r, _bgc.g, _bgc.b, _bgc.a);

    
    
}

void Screen::displayLoop(){
    Bar bar1 = Bar(250, 150, 200, 200);
    Bar bar2 = Bar(500, 300, 200, 200);
    bar2.setState(BarState::MOVING);
    while (_screenState != ScreenState::EXIT){
        handleEvents();
        SDL_RenderClear(_renderer);

        //SDL_UpdateTexture(_texture, NULL, _pixels, 640 * sizeof(Uint32));
        //SDL_RenderCopy(_renderer, _texture, NULL, NULL);

        bar1.draw(_renderer);
        bar2.draw(_renderer);

        SDL_SetRenderDrawColor(_renderer, _bgc.r, _bgc.g, _bgc.b, _bgc.a);

        SDL_RenderPresent(_renderer);
    }

    delete[] _pixels;
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_renderer);


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
