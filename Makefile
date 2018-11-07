##
## EPITECH PROJECT, 2018
## Makefile day10
## File description:
## 
##

NAME = cat

NAMETEST = tests_cat

SRC =	src/cat.c \
	src/main.c

SRCTEST = tests/test_cat.c \
	src/cat.c

OBJ =	$(SRC:.c=.o)

INC =	-I./include/ \

CFLAGS= $(INC)	\
	-W	\
	-Wall	\
	-Wextra	\

LDFLAGS= -lmy   \
         -L./lib/my/ \

CC =	gcc

TMPTEST = *.g*

RULE =	all

all:    $(NAME)


$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CDFLAGS)

tests_run: $(OBJ)
	$(CC) -lcriterion --coverage $(SRCTEST) $(CFLAGS) $(LDFLAGS) -o $(NAMETEST)
	./$(NAMETEST)
clean:
	$(RM) $(OBJ) $(TMPTEST)

fclean:	clean
	$(RM) $(NAME) $(NAMETEST)

re:	fclean all
