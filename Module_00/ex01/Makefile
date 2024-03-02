NAME	=	graph
CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
STD98	= 	-std=c++98

SRCS = Vector2.cpp Graph.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(SRCS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(STD98) $(SRCS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)
re 	:
	make fclean
	make all

.PYONY : all re clean fclean