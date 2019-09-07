#include "EventListener.hpp"

EventListener::EventListener()
{
}

EventListener::~EventListener()
{
}

bool EventListener::isRunning()
{
    return (_isRunning);
}

void EventListener::setSDLEvent(const SDL_Event &e)
{
    _event = e;
}

void EventListener::listen()
{
    while (SDL_PollEvent(&_event))
    {
        if (_event.type == SDL_QUIT)
        {
            _isRunning = false;
        }
    }
}