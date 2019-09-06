#include "main.hpp"

using namespace std;

// todo: resize window

Uint32 *get_screen_pixels(void)
{
    Uint32 *pixels;

    if (!(pixels = (Uint32 *)malloc(WIDTH * HEIGHT * sizeof(Uint32)))) // todo: make sure we don't need 1 extra memory cell
        cout << "memory failed" << std::endl;
    memset(pixels, 0, WIDTH * HEIGHT * sizeof(Uint32));
    return (pixels);
}

void run(t_sdl *sdl)
{
    bool end;

    end = false;
    while (!end)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            sdl_put_pix(&(sdl->pixels), i, 5, 0x00ffff);
        }
        SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, WIDTH * sizeof(Uint32));
        SDL_RenderClear(sdl->renderer);
        SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
        SDL_RenderPresent(sdl->renderer);
        SDL_WaitEvent(&(sdl->event));
        event_hooks(sdl, &end);
    }
}

int main()
{
    t_sdl sdl;

    sdl_init(&sdl);
    sdl_init_renderer(&sdl);
    sdl.pixels = get_screen_pixels();
    run(&sdl);
    sdl_clean(&sdl);
    return 0;
}