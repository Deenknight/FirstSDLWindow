#pragma once
#include <iostream>

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

enum class BarState {NOTSORTED, MOVING, SORTED};

class Bar{
    public:
        Bar(int x, int y, int height, int width);
        ~Bar();

        void setState(BarState state);
        void setPos(int xPos, int yPos);
        void setWidth(int width);
        
        
        void draw(SDL_Renderer* renderer);
    private:
        SDL_Rect _rect;
        SDL_Color _color;

};