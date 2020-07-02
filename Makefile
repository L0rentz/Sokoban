##
## EPITECH PROJECT, 2019
## my_sokoban
## File description:
## makefile
##

NAME	=	my_sokoban

SRCS	=	main.c \
		move3.c \
		load_file_in_mem.c \
		did_you_lose.c \
		init_struct.c \
		my_strlen.c \
		manual.c \
		move.c \
		init_ncurses.c \
		my_list_utils1.c \
		my_list_utils2.c \
		my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		list_boxes.c \
		move2.c \
		list_boxes2.c \

OBJS	=	$(SRCS:.c=.o)

LFLAGS = -lncurses

CFLAGS =	-Wall -Werror -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJS) $(SRCS)
		gcc -o $(NAME) $(OBJS) $(LFLAGS) $(CFLAGS)

clean:
		rm $(OBJS)

fclean:
		rm $(NAME)
		rm $(OBJS)

re: fclean all
