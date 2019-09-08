
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

    bool move_forw;
    bool move_back;
    bool rot_right;
    bool rot_left;

private:
    bool _isRunning;
    SDL_Event _event;
};

#endif
