#include "Renderer.hpp"
#include "main.hpp"

Renderer::Renderer(unsigned w, unsigned h) : _width(w), _height(h), _renderer(nullptr), _window(nullptr), _texture(nullptr) {}

Renderer::~Renderer()
{
    std::cout << "Renderer Destructor Called " << std::endl;
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}
SDL_Window *Renderer::getWindow() const
{
    return _window;
}

SDL_Renderer *Renderer::getRenderer() const
{
    return _renderer;
}

SDL_Texture *Renderer::getTexture() const
{
    return _texture;
}

unsigned Renderer::getWidth() const
{
    return _width;
}

unsigned Renderer::getHeight() const
{
    return _height;
}

Renderer &Renderer::operator=(const Renderer &r)
{
    _renderer = r._renderer;
    _texture = r._texture;
    _window = r._window;
    _width = r._width;
    _height = r._height;
    return (*this);
}

void Renderer::renderFrame(PixelBuff &buff)
{
    SDL_UpdateTexture(_texture, NULL, buff.getPixels().data(), _width * sizeof(Uint32));
    SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    SDL_RenderPresent(_renderer);
    buff.clear();
    SDL_RenderClear(_renderer);
}

void Renderer::initSDL()
{
    SDL_Init(SDL_INIT_VIDEO);
    _window = SDL_CreateWindow("Playful Light", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, 0);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, _width, _height);
}
