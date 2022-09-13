#pragma once
#include <iostream>

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

class enum GameState {PLAY, EXIT};


class Game{
    public:
        
        Game();
        ~Game();

        void run();
    private:
        void init(const char* title, int x, int y, int w, int h, Uint32 flags);
        void gameLoop();
        void handleEvents();

        SDL_Window* _window;
        SDL_Renderer* _renderer;

        int _screenWidth;
        int _screenHeight;

        GameState _gameState;
}


