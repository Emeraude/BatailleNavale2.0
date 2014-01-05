SRCS	= credits.cpp \
	  jeu.cpp \
	  joueur.cpp \
	  main.cpp \
	  menu.cpp \
	  fonctions.cpp

OBJS	= $(SRCS:.cpp=.o)

CFLAGS	+= -W -Wall

NAME	= battleship_2

all:	$(NAME)

$(NAME):	$(OBJS)
	g++ -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
