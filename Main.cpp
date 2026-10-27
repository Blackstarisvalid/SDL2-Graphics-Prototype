#include <SDL.h>
#include <iostream>
#include <cmath>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH  800 
#define RECT_SIDE_LEN 40 

class Entity
{
    void ManageCollisions(){

        if ( x < RECT_SIDE_LEN / 2 )
        {
            x = RECT_SIDE_LEN / 2;
            dx = -dx;
        }
        else if ( x >= WINDOW_WIDTH - RECT_SIDE_LEN / 2 )
        {
            x = WINDOW_WIDTH - RECT_SIDE_LEN / 2 - 1;
            dx = -dx;
        }
        if ( y < RECT_SIDE_LEN / 2 )
        {
            y = RECT_SIDE_LEN / 2;
            dy = -dy;
        }
        else if ( y >= WINDOW_HEIGHT - RECT_SIDE_LEN / 2)
        {
            y = WINDOW_HEIGHT - RECT_SIDE_LEN / 2 - 1;
            dy = -dy;
        }
    }
public:
        float x, y;
        float dx, dy;

        void Update(){
            x += dx;
            y += dy;
            ManageCollisions();
            SDL_Delay(1);
        }

        void Render(SDL_Renderer* renderer){

            SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_Rect rect{
                rect.x = x - RECT_SIDE_LEN / 2,
                rect.y = y - RECT_SIDE_LEN / 2,
                RECT_SIDE_LEN,
                RECT_SIDE_LEN
            };
            SDL_RenderFillRect(renderer, &rect);
            SDL_RenderPresent(renderer);

        }
};
int main(void){

    int result = SDL_Init(SDL_INIT_VIDEO);

    if ( result < 0 ){
        std::cerr << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Gaming engine", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0 
        );
    
    if ( window == nullptr ){

        std::cerr << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    if ( renderer == nullptr ){

        std::cerr << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    Entity rectangle = {
        rectangle.x = WINDOW_WIDTH / 2,
        rectangle.y = WINDOW_HEIGHT / 2,
        1,
        1
    };

    bool IsRunning = true;
    
    while (IsRunning){

        SDL_Event event;
        while (SDL_PollEvent(&event)){
            
            if ( event.type == SDL_QUIT ){
                IsRunning = false;
            }
        }
        rectangle.Update();
        rectangle.Render(renderer);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}