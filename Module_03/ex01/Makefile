NAME	=	car_ex01
CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
STD98	= 	-std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = graph.hpp Vector2.hpp

$(NAME) : $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(STD98) $(OBJS)

%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(STD98) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all re clean fclean
