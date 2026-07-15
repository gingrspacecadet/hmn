#include "renderer.hpp"

#include <SDL3/SDL.h>

bool Renderer::create(const char *title, int w, int h) {
    _win = SDL_CreateWindow(title, w, h, SDL_WINDOW_RESIZABLE);
    if (!_win) return false;

    _r = SDL_CreateRenderer(_win, nullptr);
    if (!_r) {
        SDL_DestroyWindow(_win);
        return false;
    }

    return true;
}

void Renderer::draw(Rect r, Colour c) {
    SDL_Rect sr = {.x = r.x, .y = r.y, .w = r.width, .h = r.height};
    SDL_FRect sf;
    SDL_RectToFRect(&sr, &sf);
    SDL_SetRenderDrawColor(_r, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(_r, &sf);
}

void Renderer::start_frame(Colour c) {
    SDL_SetRenderDrawColor(_r, c.r, c.g, c.b, c.a);
    SDL_RenderClear(_r);
}

void Renderer::end_frame() {
    SDL_RenderPresent(_r);
}