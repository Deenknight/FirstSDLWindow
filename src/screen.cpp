#include "headers/screen.h"
#include "headers/bar.h"


Screen::Screen(){
    _window = nullptr;
    _renderer = nullptr;
    _bgc = {255, 255, 255, 0};

    _screenWidth = 1024;
    _screenHeight = 600;

    _screenState = ScreenState::PLAY;

    TTF_Font* _TNR = TTF_OpenFont("TIMES.ttf", 24);
    
};

Screen::~Screen(){};

void Screen::run(){
    init("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
    
    displayLoop();
}

void Screen::init(const char* title, int x, int y, int w, int h, Uint32 flags){

    //initialize sdl and the window
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow(title, x, y, w, h, flags);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    
    
    //initialize the text library
    TTF_Init();

    _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, 640, 480);

    //_pixels = new Uint32[640 * 480];



    //set the background colour
    SDL_SetRenderDrawColor(_renderer, _bgc.r, _bgc.g, _bgc.b, _bgc.a);


    
    
    
}

void Screen::displayLoop(){
    
    SDL_Color textColor = {0, 0, 0, 0};
    std::string message = "test string to display text";

    //create the surface that the text will be rendered on
    _textSurface = TTF_RenderText_Solid(_TNR, message.c_str(), textColor);
    SDL_FreeSurface(_textSurface);
    SDL_Rect renderQuad = { 20, _screenHeight - 30, _textSurface->w, _textSurface->h };
    


    while (_screenState != ScreenState::EXIT){
        handleEvents();
        SDL_RenderClear(_renderer);

        //SDL_UpdateTexture(_texture, NULL, _pixels, 640 * sizeof(Uint32));
        //SDL_RenderCopy(_renderer, _texture, NULL, NULL);

        /*
            text
            slider for number of bars or number input
            ---bars
            button for different sort techniques
            sort button

            sorting
            movement of bars

        */

        
        SDL_RenderCopy(_renderer, _texture, NULL, &renderQuad);

        

        //set background colour
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
