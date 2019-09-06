

#ifndef MAIN_HPP
# define MAIN_HPP

# include <time.h>
# include <fcntl.h>
# include <SDL2/SDL.h>
# include <iostream>
# include "libft.h"

#ifdef __APPLE__
# include "SDL2.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
#elif __linux__
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_ttf.h>
#endif

# define WIDTH 1280
# define HEIGHT 600


#endif