##
## EPITECH PROJECT, 2017
## MAKEFILE
## File description:
## Makefile
##

NAME	= lem_in

CC	= gcc -g

RM	= rm -f

SRCS	=	./src/get_next_line.c		\
		./src/main.c			\
		./src/parse_file.c		\
		./src/read_file.c		\
		./src/fill_tab.c		\
		./src/fill_tunnels_rooms.c	\
		./src/fill_tunnels_tab.c	\
		./src/fill_struct.c		\
		./src/create_all_struct.c	\
		./src/count_link.c		\
		./src/select_name.c		\
		./src/create_link.c		\
		./src/create_all_links.c 	\
		./src/connects_links.c		\
		./src/find_start.c		\
		./src/find_end.c		\
		./src/search_way.c		\
                ./src/move_disp.c               \
                ./src/find_room.c		\
		./src/clean_tab.c

OBJS	= $(SRCS:.c=.o)

LIB = -L ./lib/ -lmy

CFLAGS = -I ./include/

CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 make -C ./lib/my/
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/my/

re: fclean all

.PHONY: all clean fclean re
