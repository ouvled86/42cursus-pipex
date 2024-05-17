NAME = pipex

SRCS =

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(CFLAGS) $< -o $@