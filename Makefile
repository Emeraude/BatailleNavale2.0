SRCS	= boat.cpp \
	  jeu.cpp \
	  joueur.cpp \
	  main.cpp \
	  fonctions.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS	+= -W -Wall -Wextra -Werror

NAME	= battleship

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	g++ -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
