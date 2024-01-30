##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

#CC	=	gcc

CFLAGS	=	-W -Wall

SRC	=	secured.c	\
		supp_secured.c	\
		supp1_secured.c	\
		error.c	\
		miniprintf2.c	\
		my_put_nbr.c	\
		test.c

OBJ	=	$(SRC:.c=.o)

PROG	=	secured

NAME	=	libhashtable.a

all:	$(OBJ)

	ar rcs $(NAME) $(OBJ)

debug:
	gcc $(CFLAGS) -o $(PROG) $(SRC) main.c -L . -lhashtable -ggdb

compil:	$(OBJ)
	gcc $(CFLAGS) -o $(PROG) $(OBJ) main.c -L . -lhashtable

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(PROG)
	rm -f *~
	rm -f *#
re:	fclean all
