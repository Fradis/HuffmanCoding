SRC =		src/HuffmanCoding.c \
			src/tools.c

OSRC = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

NAME = HuffmanCoding

all: $(NAME)

$(NAME): $(OSRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OSRC)

clean:
	$(RM) $(OSRC)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re