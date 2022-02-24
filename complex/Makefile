NAME	=	complex
SRCS	=	complex.cpp	\
			utils.cpp
OBJS	=	$(SRCS:.cpp=.o)

all		: $(NAME)

$(NAME) : $(OBJS)
	g++ -g -o $(NAME) $(OBJS)

%.o		: %.c
	g++ -g -o $@ -c $?

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all