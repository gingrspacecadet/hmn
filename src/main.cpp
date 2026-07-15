#include <stdio.h>
#include <SDL3/SDL.h>

#define _DEFER_CONCAT(a, b) a##b
#define DEFER_CONCAT(a, b) _DEFER_CONCAT(a, b)

#define _defer_impl(id, code)                                      \
    auto DEFER_CONCAT(_defer_lambda_, id) = [&]() { code; };       \
    struct DEFER_CONCAT(_defer_struct_, id) {                      \
        decltype(DEFER_CONCAT(_defer_lambda_, id)) f;              \
        ~DEFER_CONCAT(_defer_struct_, id)() { f(); }               \
    } DEFER_CONCAT(_defer_instance_, id){ DEFER_CONCAT(_defer_lambda_, id) }

#define defer(code) _defer_impl(__COUNTER__, code)

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO))
        return 1;
    
    defer(SDL_Quit());
    

    SDL_Window *win = SDL_CreateWindow("chat", 800, 600, SDL_WINDOW_RESIZABLE);

    if (!win)
        return 1;
        
    defer(SDL_DestroyWindow(win));

    SDL_Renderer *r = SDL_CreateRenderer(win, NULL);
    
    if (!r)
        return 1;

    defer(SDL_DestroyRenderer(r));

    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderClear(r);
    SDL_RenderPresent(r);
    
    SDL_Event e;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_EVENT_QUIT:
                running = false;
                break;

            case SDL_EVENT_KEY_DOWN:
                printf("Key down: %s\n", SDL_GetKeyName(e.key.key));
                break;

            case SDL_EVENT_WINDOW_RESIZED:
                printf("Window resized: %d x %d\n", e.window.data1, e.window.data2);
                break;
            }
        }

        SDL_Delay(16);
    }

    return 0;
}