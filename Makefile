NAME = addressBook

SRCS = ./sources/main.cpp ./sources/addressBook.cpp ./sources/contact.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = g++ 
FLAGS = -Wall -Wextra -std=c++17
I = -I./includes
HEADER = includes/contact.hpp includes/addressBook.hpp

%.o: %.cpp $(HEADER) Makefile
	$(CXX) $(FLAGS) $(I) -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	$(CXX) $(OBJS) -o ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}

re: 	fclean all

.PHONY: all clean fclean
