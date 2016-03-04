##
## Makefile for minishell1 in /home/clemen_j/Work/PSU/PSU_2015_minishell1
## 
## Made by Clémenceau Cedric
## Login   <clemen_j@epitech.net>
## 
## Started on  Mon Jan 18 22:44:40 2016 Clémenceau Cedric
## Last update Thu Feb 18 14:54:41 2016 Clémenceau Cedric
##

CC	= gcc -g

RM	= rm -f

CFLAGS	= -I./include/
CLFAGS	+= -g -W -Wall -Wextra ##-ansii -pedantic

SRC	= server/server.c \
	  server/put_nbrs.c

SRC2	= client/client.c \
	  client/my_getnbr.c

NAME	= server/server

NAME2	= client/client

OBJ	= $(SRC:.c=.o)

OBJ2	= $(SRC2:.c=.o)

$(NAME)	: $(OBJ) $(OBJ2)
	  $(CC) -o $(NAME) $(OBJ)
	  $(CC) -o $(NAME2) $(OBJ2)

all	: $(NAME)

clean	:
	  $(RM) $(OBJ)
	  $(RM) $(OBJ2)

fclean	: clean
	  $(RM) $(NAME)
	  $(RM) $(NAME2)

re	: clean fclean all
