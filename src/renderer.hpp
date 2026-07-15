#include <SDL3/SDL.h>

struct Rect {
    Rect(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}

    int x, y, width, height;
};

struct Colour {
    Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : r(r), g(g), b(b), a(a) {}
    
    uint8_t r, g, b, a;
};

struct Renderer {
    bool create(const char *title, int w, int h);
    void draw(Rect r, Colour c);
    void start_frame(Colour c = Colour(30, 30, 30, 255));
    void end_frame();

private:
    SDL_Window *_win = nullptr;
    SDL_Renderer *_r = nullptr;
};