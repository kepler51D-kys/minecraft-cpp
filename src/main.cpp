#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
// #define SDL_MAIN_USE_CALLBACKS
// #include <SDL3/SDL_main.h>
#include "renderer.hpp"

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    allInit(&window, &renderer, &font, "../assets/fonts/COMIC.TFF", Vec2(1280,720));

    SDL_Event* event;
    while (true) {
        while(SDL_PollEvent(event)) {
            if (event->type == SDL_EVENT_QUIT) {
                goto cleanup;
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    cleanup:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    return 0;
}