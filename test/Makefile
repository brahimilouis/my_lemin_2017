##
## EPITECH PROJECT, 2017
## makefile unitaire
## File description:
## makefile unitaire
##

SRC_DIR		=	$(realpath ../src)

SRC		=	$(SRC_DIR)/count_link.c			\
			$(SRC_DIR)/create_all_links.c		\
			$(SRC_DIR)/create_link.c		\
			$(SRC_DIR)/create_all_struct.c		\
			$(SRC_DIR)/fill_struct.c		\
			$(SRC_DIR)/fill_tab.c			\
			$(SRC_DIR)/fill_tunnels_rooms.c		\
			$(SRC_DIR)/fill_tunnels_tab.c		\
			$(SRC_DIR)/find_end.c			\
			$(SRC_DIR)/find_start.c			\
			$(SRC_DIR)/get_next_line.c		\
			$(SRC_DIR)/parse_file.c			\
			$(SRC_DIR)/read_file.c			\
			$(SRC_DIR)/search_way.c			\
			$(SRC_DIR)/select_name.c		\
			$(SRC_DIR)/connects_links.c

SRC_UT_DIR	=	$(realpath .)

SRC_UT		=	$(SRC_UT_DIR)/tests_return_cptlink.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage

CFLAGS		+=	-I ../include/

LDFLAGS		=	-lcriterion -lgcov

LIB		=	-L ../lib/ -lmy

NAME		=	units

all:		$(NAME)
		rm -f $(OBJ)
		rm -f $(SRC_DIR)/*.g*
		rm -f $(SRC_UT_DIR)/*g*

$(NAME):	$(OBJ)
		make -C ../lib/my/
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS) $(LIB)

clean:
		make clean -C ../lib/my/
		rm -f $(OBJ)
		rm -f $(SRC_DIR)/*.g*
		rm -f $(SRC_UT_DIR)/*g*

fclean:		clean
		make fclean -C ../lib/my/
		rm -f $(NAME)

re:		fclean all
