CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRCS = main.cpp BitcoinExchange.cpp CryptoRate.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = BitcoinExchange
.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
