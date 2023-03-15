##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile
##

SRC = 	strlen.asm \
		strchr.asm \
		strrchr.asm \
		strcmp.asm \
		strncmp.asm \
		strcspn.asm \
		strpbrk.asm \
		memset.asm \
		memcpy.asm \
		memmove.asm \
		strstr.asm \
		strcasecmp.asm \
		memfrob.asm \

TESTS_SRC = tests/test_strlen.c \
			tests/test_strcmp.c \
			tests/test_strchr.c \
			tests/test_strpbrk.c \
			tests/test_strrchr.c \
			tests/test_strncmp.c \
			tests/test_strstr.c \
			tests/test_strcspn.c \
			tests/test_strcasecmp.c \
			tests/test_memfrob.c \

OBJ =   $(SRC:.asm=.o)

NAME    =	libasm.so

all:    $(NAME)

%.o: %.asm
	nasm -f elf64 -o $@ $<
$(NAME):	$(OBJ)
	ld -shared -fPIC -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gcda
	rm -f *.gcno

re:	fclean all

tests_run: fclean all
	gcc -o unit_tests $(TESTS_SRC) -ldl --coverage -lcriterion
	./unit_tests

.PHONY: all clean fclean re tests_run
