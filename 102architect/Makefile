##
## EPITECH PROJECT, 2023
## 102architect
## File description:
## Makefile
##

CC	=	gcc

TARGET	=	102architect

CFLAGS	=	-I./include -Wall -Wextra -Wshadow

SRC	=	main.c			\
		my_str_isnum.c	\
		print_result.c	\
		translation.c	\
		scaling.c		\
		rotation.c		\
		reflection.c	\

OBJ	=	$(SRC:.c=.o)

all: $(TARGET)


$(TARGET):	$(OBJ)
	@echo -e "\e[36mBuilding $(TARGET)...\e[0m"
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) -lm
	@echo -e "\e[1m\e[32mBinary ready!\e[0m"

clean:
	@rm -f $(OBJ)
	@rm -f coding-style-reports.log
	@echo -e "\e[1m\e[36mObject files deleted!\e[0m"

fclean: clean
	@rm -f $(TARGET)
	@echo -e "\e[1m\e[36mBinary deleted!\e[0m"

re: fclean all
