##
## Makefile for makefile in /home/danilo_d/rendu/PSU_2014_my_printf
##
## Made by Dimitri Danilov
## Login   <danilo_d@epitech.net>
##
## Started on  Sat Nov 15 13:07:25 2014 Dimitri Danilov
## Last update Wed Jun 17 14:24:24 2015 danilov dimitri
##

NAME	= Darien_Reborn

SRCS	= srcs/main.c \
	  srcs/get_next_line.c \
	  srcs/str_to_tab.c \
	  srcs/reborn.c \
	  srcs/music.c \
	  srcs/aff_map.c \
	  srcs/load_map.c \
	  srcs/check_buttons.c \
	  srcs/get_pixel.c \
	  srcs/my_get_nbr.c \
	  srcs/xmalloc.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Iinclude/ -Wall -Wextra -lSDL -lSDL -lSDLmain  -lSDL_image -lfmodex64

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(SRCS) $(CFLAGS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
