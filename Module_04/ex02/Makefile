NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \
    	../ex00/Person.cpp \
		../ex00/Form.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re