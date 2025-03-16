NAME	 =	practice
CXX		 =	c++
CXXFLAGS = -Wall -Wextra -Werror
STD98	 = 	-std=c++98

SRCS = *.cpp

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

.PHONY : all re clean fclean