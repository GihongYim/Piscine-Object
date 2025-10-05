NAME		=	module01
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
STD98		= 	-std=c++98

SRCS = Tool.cpp Shovel.cpp Hammer.cpp Worker.cpp Workshop.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(STD98) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(STD98) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)
re 	:
	make fclean
	make all

.PHONY : all re clean fclean