#
# MAKEFILE ./
#

SRC = main.c

NAME = test_lib

LIB = -L ./tree -lmy -I include

FLAG = -W -Wall -Wextra

all:
	@make -C tree -s
	@gcc $(SRC) -o $(NAME) $(LIB) -g $(FLAG)

clean:
	@make clean -C tree -s

fclean: clean
	@make fclean -C tree -s
	@rm -f $(NAME)
	@rm -f libmy.a

re: fclean all



