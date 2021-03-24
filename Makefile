##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Made by Vincent Daribo
##

SRC	=	printf_doss/my_printf.c 	\
		printf_doss/my_put_hex.c 	\
		printf_doss/conv_int.c 		\
		printf_doss/my_put_oct.c 	\
		printf_doss/my_put_nbr.c 	\
		printf_doss/my_strlen.c 	\
		printf_doss/my_putstr.c 	\
		printf_doss/my_putchar.c 	\
		printf_doss/my_put_bin.c 	\
		printf_doss/my_put_u.c 		\
		printf_doss/my_put_plus.c 	\
		manage_arr.c 		\
		my_int_array.c 		\
		choose_smaller.c 	\

SRC2	=	main.c 	\
		manage_file.c 	\
		bsq.c 	\
		errors_handling.c 	\
		str_to_arr.c 	\
		arr_to_str.c 	\
		one_line.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all :	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o bsq $(SRC2) -g3 -L. -lmy -Wall -Wextra -pedantic
clean :
	@rm -f $(OBJ) *~ *.gcno *.gcda *.o

fclean : clean
	rm -f $(NAME)
	rm -f bsq

re : fclean all
