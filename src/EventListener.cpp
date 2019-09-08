#include "EventListener.hpp"

EventListener::EventListener() : move_forw(false), move_back(false),  rot_right(false), rot_left(false)
{}

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

        if (_event.type == SDL_KEYDOWN || _event.type == SDL_KEYUP) {

            if (_event.type == SDL_KEYDOWN) {
                if (_event.key.keysym.sym == SDLK_ESCAPE)
				    _isRunning = false;
            }
              if (_event.key.keysym.sym == SDLK_w)
					move_forw = _event.type == SDL_KEYDOWN;
				if (_event.key.keysym.sym == SDLK_s)
					move_back = _event.type == SDL_KEYDOWN;
				if (_event.key.keysym.sym == SDLK_a)
					rot_left = _event.type == SDL_KEYDOWN;
				if (_event.key.keysym.sym == SDLK_d)
					rot_right = _event.type == SDL_KEYDOWN;

        }
    }
}