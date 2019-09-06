NAME = go
CC = clang++
FILES = test
SRC = $(addprefix src/, $(addsuffix .cpp, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
SDL_CFLAGS = $(shell sdl2-config --cflags)
SPEED = -O3
FLAGSTMP = -Wall -Wextra -Werror
HEADERS = -I./includes

OS = $(shell uname)
ifeq ($(OS), Linux)
CGFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
else
CGFLAGS = -framework OpenGL -framework AppKit
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer
endif

all: $(NAME)
$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(FLAGS) $(SPEED) $(OBJ) $(CGFLAGS) $(FRAMEWORKS)
obj/%.o: src/%.cpp
	@$(CC) -o $@ $(FLAGS) $(SPEED) $(HEADERS) $(INCLUDES) -c $^
clean:
	@rm -f $(OBJ)
fclean:
	@rm -rf $(OBJ)
	@rm -f $(NAME)
re: fclean all

