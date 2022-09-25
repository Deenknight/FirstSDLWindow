#include "headers/bar.h"

Bar::Bar(int x, int y, int height, int width){
    _rect.x = x;
    _rect.y = y;
    _rect.h = height;
    _rect.w = width;

    _color = {.r = 255, .g = 255, .b = 255};

}

Bar::~Bar(){};

void Bar::setPos(int xPos, int yPos){
    _rect.x = xPos;
    _rect.y = yPos;
}

void Bar::setWidth(int width){
    _rect.w = width;
}

void Bar::setState(BarState state){
    switch(state){
        case BarState::NOTSORTED:
            _color = {.r = 255, .g = 255, .b = 255};
            break;
        case BarState::MOVING:
            _color = {.r = 255, .g = 0, .b = 0};
            break;
        case BarState::SORTED: 
            _color = {.r = 0, .g = 255, .b = 0};
            break;
    }
}

void Bar::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, 255);
    SDL_RenderDrawRect(renderer, &_rect);
    SDL_RenderFillRect(renderer, &_rect);
}




