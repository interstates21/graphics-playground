#include "go.hpp"

using namespace std;

// void sdl_clean(t_sdl *sdl)
// {
//     // todo: delete[] pixels;
//     SDL_DestroyTexture(sdl->texture);
//     SDL_DestroyRenderer(sdl->renderer);
//     SDL_DestroyWindow(sdl->window);
//     SDL_Quit();
// }



void put_pix(Uint32 **pixels, int x, int y, Uint32 color)
{
    (*pixels)[y * WIDTH + x] = color;
}

void sdl_clear_texture(Uint32 **pixels)
{
    bzero(*pixels, WIDTH * HEIGHT * 4);
}


void sdl_apply_renderer(SDL_Texture *tex, SDL_Renderer *rend,  Uint32 *pixels) {
        SDL_UpdateTexture(tex, NULL, pixels, WIDTH * sizeof(Uint32));
        SDL_RenderCopy(rend, tex, NULL, NULL);
        SDL_RenderPresent(rend);
        sdl_clear_texture(&pixels);
        SDL_RenderClear(rend);
}


Uint32 *get_screen_pixels(void)
{
    Uint32 *pixels;

    if (!(pixels = (Uint32 *)malloc(WIDTH * HEIGHT * sizeof(Uint32))))
        printf("allocating pixels failed.");
    memset(pixels, 0, WIDTH * HEIGHT * sizeof(Uint32));
    return (pixels);
}

void initSDl(SDL_Window *win, SDL_Renderer *rend, SDL_Texture *tex) {
    SDL_Init(SDL_INIT_VIDEO);
    win =  SDL_CreateWindow("Playful Light",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    tex  = SDL_CreateTexture(rend,
    SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT); 

}

void render(Uint32 *pixels) {
    for (int i = 0; i < WIDTH - 1; i++) {
        for(int j = 0; j < HEIGHT - 1; j++) {
            put_pix(&pixels, i, j, 0x0000ff);
        }
    }
}


void run(SDL_Texture *tex, SDL_Renderer *rend) {

    Uint32 *pixels = get_screen_pixels();
    

 bool is_running = true;
SDL_Event event;
while (is_running) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            is_running = false;
        }
            
    }
    render(pixels);
    put_pix(&pixels, 4, 5, 0x0000ff);
    // sdl_apply_renderer(tex, rend, pixels);
        SDL_UpdateTexture(tex, NULL, pixels, WIDTH * sizeof(Uint32));
        SDL_RenderCopy(rend, tex, NULL, NULL);
        SDL_RenderPresent(rend);
        sdl_clear_texture(&pixels);
        SDL_RenderClear(rend);

}
        // SDL_Quit();s
}


int main(void) {
    SDL_Window *win;
    SDL_Renderer *rend;
    SDL_Texture *tex;


    initSDl(win, rend, tex);
    run(tex, rend);
}