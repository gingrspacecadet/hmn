#include <SDL3/SDL.h>

struct Rect {
    Rect(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}

    int x, y, width, height;
};

struct Renderer {
    bool create(const char *title, int w, int h) {
        _win = SDL_CreateWindow(title, w, h, SDL_WINDOW_RESIZABLE);
        if (!_win) return false;

        _r = SDL_CreateRenderer(_win, nullptr);
        if (!_r) {
            SDL_DestroyWindow(_win);
            return false;
        }

        return true;
    }

    void draw(Rect r) {
        SDL_Rect sr = {.x = r.x, .y = r.y, .w = r.width, .h = r.height};
        SDL_FRect sf;
        SDL_RectToFRect(&sr, &sf);
        SDL_SetRenderDrawColor(_r, 200, 50, 50, 255);
        SDL_RenderFillRect(_r, &sf);
    }

    void start_frame() {
        SDL_SetRenderDrawColor(_r, 30, 30, 30, 255);
        SDL_RenderClear(_r);
    }

    void end_frame() {
        SDL_RenderPresent(_r);
    }
private:
    SDL_Window *_win = nullptr;
    SDL_Renderer *_r = nullptr;
};