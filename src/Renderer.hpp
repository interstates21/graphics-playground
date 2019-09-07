#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "main.hpp"
#include "PixelBuff.hpp"

class Renderer
{

public:
    Renderer(unsigned, unsigned);
    Renderer(const Renderer &);
    ~Renderer();
    Renderer &
    operator=(const Renderer &);
    static Renderer *getInstance();
    void initSDL(void);
    SDL_Window *getWindow() const;
    SDL_Renderer *getRenderer() const;
    SDL_Texture *getTexture() const;
    unsigned getWidth() const;
    unsigned getHeight() const;

    void renderFrame(PixelBuff &);

private:
    unsigned _width;
    unsigned _height;
    SDL_Renderer *_renderer;
    SDL_Window *_window;
    SDL_Texture *_texture;
};

#endif // !RENDERER_HPP