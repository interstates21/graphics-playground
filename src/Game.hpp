
#ifndef GAME_HPP
#define GAME_HPP

#include "PixelBuff.hpp"
#include "main.hpp"
#include "Vector2.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"
#include "EventListener.hpp"
#include "Line.hpp"

class Game
{
public:
    void run();

    void init();
    void setRenderer(Renderer const &);
    void setScene(Scene const &);
    void setEventListener(EventListener const &);
    void setPixelBuff(PixelBuff const &);

    static Game *getInstance();

private:
    void _renderTestScreen();
    void _renderTestLine();
    Renderer _renderer;
    Scene _scene;
    PixelBuff _pixelBuff;
    EventListener _eventListener;

    Game();
    Game(const Game &);
    ~Game();
    Game &
    operator=(const Game &);
    static Game *instance;
};

#endif