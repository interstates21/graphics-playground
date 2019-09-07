
#ifndef EVENT_LISTENER_HPP
#define EVENT_LISTENER_HPP

#include "main.hpp"

class EventListener
{
public:
    EventListener(/* args */);
    ~EventListener();
    void listen();
    bool isRunning();
    void setSDLEvent(const SDL_Event &);

private:
    bool _isRunning;
    SDL_Event _event;
};

#endif
