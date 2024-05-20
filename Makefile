NAME = pipex

SRCS =	srcs/clean_ups/close_fds.c \
		srcs/clean_ups/free_heap.c \
		srcs/execution/childs_exec.c \
		srcs/parsing/handle_args.c \
		srcs/parsing/handle_cmds.c \
		srcs/parsing/safe_functions.c \
		srcs/main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo Compiling pipex sources..
	@cc -g $(CFLAGS) $^ -o $@

$(LIBFT):
	@echo Archiving libft..
	@make -s -C libft/

%.o: %.c includes/pipex.h
	@cc $(CFLAGS) -g -c $< -o $@

clean:

	@echo Cleaning object files..
	@rm -f $(OBJS)
	@make fclean -s -C libft/

fclean:
	@echo Cleaning object files and executable..
	@rm -f $(OBJS) $(NAME)
	@make fclean -s -C libft/

re: fclean all