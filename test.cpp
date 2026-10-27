#include <SDL.h>
#include <iostream>

int main(){
    int result = SDL_Init(SDL_INIT_VIDEO);

    if ( result < 0 ){
        std::cerr << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Gaming Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        0
    );

    if ( window == nullptr ){
        std::cerr << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    if ( renderer == nullptr )
    {
        std::cerr << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Rect rect{40, 30, 90, 100};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 10);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    rect = {500, 25, 100, 100};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 150);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 200);
    rect = {400, 100, 16, 200};
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);

    bool running = true;
    
    while (running){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            if ( event.type == SDL_QUIT ){
                running = false;
            }
        }

        SDL_Delay(16);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
