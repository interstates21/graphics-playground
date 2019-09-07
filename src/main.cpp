#include "main.hpp"
#include "Game.hpp"
#include "PixelBuff.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"
#include "EventListener.hpp"

using namespace std;
// todo: resize window

int main()
{
    Game *game = Game::getInstance();
    Renderer renderer(WIDTH, HEIGHT);
    EventListener eventListener;
    PixelBuff pixelBuff(WIDTH, HEIGHT);
    Scene scene;

    game->init();

    renderer.initSDL();
    game->setRenderer(renderer);
    game->setPixelBuff(pixelBuff);
    game->setEventListener(eventListener);
    game->setScene(scene);
    game->run();

    return 0;
}