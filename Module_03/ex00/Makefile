NAME	=	car
CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
STD98	= 	-std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = car.hpp wheel.hpp gear.hpp break.hpp engine.hpp power.hpp

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

.PYONY : all re clean fclean