#include "Game.hpp"

Game *Game::instance = nullptr;

Game::Game() : _renderer(WIDTH, HEIGHT), _scene(), _pixelBuff(WIDTH, HEIGHT), _eventListener()
{
}

Game *Game::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Game();
    }

    return instance;
}

Game::~Game()
{
    delete instance;
}
 void Game::_renderTestScreen()
 {
     for (int i = 0; i < (int)_renderer.getWidth(); ++i)
     {
          Vector2<int> v(i, 5);
            v.render(_pixelBuff, 0x0000ff);
          for (unsigned j = 0; j < _renderer.getHeight(); ++j)
          {
          }
     }
 }

void Game::init()
{
    std::cout << "The Game is running!" << std::endl;
}

void Game::setPixelBuff(PixelBuff const &p)
{
    _pixelBuff = p;
}

void Game::setRenderer(Renderer const &r)
{
    _renderer = r;
}

void Game::setEventListener(EventListener const &e)
{
    _eventListener = e;
}

void Game::setScene(Scene const &s)
{
    _scene = s;
}

void Game::run()
{
    while (_eventListener.isRunning())
    {
        _eventListener.listen();
        // _scene.apply(_eventListener);
        _renderTestScreen();
        _renderer.renderFrame(_pixelBuff);
    }
}