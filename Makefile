SRCS	= boat.cpp \
	  fonctions.cpp \
	  game.cpp \
	  harbor.cpp \
	  main.cpp \
	  player.cpp \
	  platform.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS	+= -W -Wall -Wextra -Werror

NAME	= battleship

RM	= rm -f

CC	= g++

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
