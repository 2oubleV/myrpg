##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## B-MUL-200-LIL-2-1-myrpg-antoine.podvin
##

SRC	=	src/main.c	\
		src/my_rpg.c	\
		src/init_game.c	\
		src/init_game2.c	\
		src/map.c 	\
		src/events.c	\
		src/game.c	\
		src/move_map.c	\
		src/move_player.c 	\
		src/pause.c	\
		src/manage_keys.c	\
		src/main_menu.c \
		src/go_in_building.c    \
		src/help.c 	\
		src/inventory.c	\
		src/final.c	\
		src/data.c	\
		src/power.c	\
		src/utils.c	\
		src/mob.c	\
		src/end_game.c 	\
		src/end.c 	\

OBJ =   $(SRC:.c=.o)

NAME	=	my_rpg

LIBRARY	=	-Llib/my -lmy

W_FLAGS	=	-W -Wall -Wextra

CSFML	=	-lcsfml-system -lcsfml-graphics	-lcsfml-window -lcsfml-audio

MATH	= 	-lm

all:	$(NAME)

$(NAME):    $(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(LIBRARY) $(W_FLAGS) $(CSFML) $(MATH)

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)
	rm -f libmy.a
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f lib/my/*.o

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re: fclean all

debug:
	make debug -C ./lib/my
	gcc -o $(NAME) $(SRC) $(LIBRARY) $(W_FLAGS) $(CSFML) $(MATH) -g
