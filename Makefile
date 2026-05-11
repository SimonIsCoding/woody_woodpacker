#Variables
COMP	= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
NAME	= woody_woodpacker
SRCS_DIR= srcs
SRCS	= $(SRCS_DIR)/main.c
OBJS	= $(SRCS:.c=.o)
INCLUDE	= inc/woody.h

#Rules
all:	$(NAME)

%.o:	%.c $(INCLUDE) Makefile
		$(COMP) $(FLAGS) -c $< -o $@ 

$(NAME): $(OBJS) $(INCLUDE) Makefile
		$(COMP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
