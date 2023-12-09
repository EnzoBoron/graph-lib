#
# Makefile ./tree
#

SRC = 	add_nodes.c\
		error.c\
		display_tree.c\
		find_way.c\
		display_array.c\
		create_node_int.c\
		display_list_int.c\
		change_node_tree.c\
		get_path.c\
		return_ways.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CP = cp -f tree.h $(NAME) ../

.SILENT: $(OBJ)

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@$(CP)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
