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
          for (unsigned j = 0; j < _renderer.getHeight(); ++j)
          {
               Vector2<int> v(i, j);
                v.render(_pixelBuff, 0x0000ff);
          }
     }
 }

void Game::_testApplyController(Vector2 <int> &p, float &angle) {

    if (_eventListener.move_forw) {
        p.x = p.x + 1;
        p.y = p.y + 1;
    }
    if (_eventListener.move_back) {
        p.x = p.x - 1;
        p.y = p.y - 1;
    }
    if (_eventListener.rot_left) {
        angle -= 0.1;
    }

    if (_eventListener.rot_right) {
        angle += 0.1;
    }

     angle += 0.1;
}

void Game::_renderTestLine()
 {
    Line l(p1, p2);

    _testApplyController(pos, angle);
    Line pl(pos.x, pos.y, cos(angle) * 20 + pos.x,  sin(angle) * 20 + pos.y);
    l.render(_pixelBuff, NICE_BLUE);
    pl.render(_pixelBuff, NICE_BLUE);
    pos.render(_pixelBuff, RED);

 }




void Game::init()
{
    p1 = Vector2 <int>(70, 20);
    p2 = Vector2 <int>(70, 190);
    pos = Vector2 <int>(50, 50);
    angle = 0;
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
    init();
    while (_eventListener.isRunning())
    {
        _eventListener.listen();
        // _scene.apply(_eventListener);
        // _renderTestScreen();
        _renderTestLine();
        _renderer.renderFrame(_pixelBuff);
    }
}