##
## EPITECH PROJECT, 2023
## 101pong
## File description:
## Makefile
##

CC = gcc

TARGET = 101pong

CFLAGS = -Wall -Wextra -Werror -I./include

LDFLAGS = -lm

SRC	=	pong.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
