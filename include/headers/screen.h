#pragma once
#include <iostream>

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

enum class ScreenState {PLAY, EXIT};


class Screen{
    public:
        
        Screen();
        ~Screen();

        void run();
    private:
        void init(const char* title, int x, int y, int w, int h, Uint32 flags);
        void displayLoop();
        void handleEvents();

        SDL_Window* _window;
        SDL_Renderer* _renderer;
        SDL_Color _bgc;


        int _screenWidth;
        int _screenHeight;

        ScreenState _screenState;

        Uint32* _pixels;
        SDL_Texture* _texture;
};


