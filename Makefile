SRCS		= push_swap.c \
			  list.c \
			  push.c \
			  rotate.c \
			  reverse_rotate.c \
			  swap.c \
			  radix_sort.c \
			  utils.c \
			  init_stacks.c \
			  stack.c
SRCS		:= $(addprefix src/,$(SRCS)) 
SRCS_BONUS	= checker_bonus.c \
			  list.c \
			  push.c \
			  rotate.c \
			  reverse_rotate.c \
			  swap.c \
			  utils.c \
			  init_stacks.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  stack.c
SRCS_BONUS	:= $(addprefix src/,$(SRCS_BONUS))
OBJS		= ${SRCS:.c=.o}
OBJ_BONUS   = ${SRCS_BONUS:.c=.o}
NAME		= push_swap
NAME_BONUS  = checker
CC			= gcc
MAKE		= make
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -Iinclude -Iprintf
			
$(NAME):		$(OBJS)
				$(MAKE) -C printf
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) printf/libftprintf.a
all:			$(NAME)
$(NAME_BONUS):	$(OBJ_BONUS)
				$(MAKE) -C printf
				$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) printf/libftprintf.a
bonus:			$(NAME_BONUS)
clean:
				${RM} ${OBJS} $(OBJ_BONUS)
				$(MAKE) clean -C printf
fclean:			clean
				${RM} $(NAME) $(NAME_BONUS)
				$(MAKE) fclean -C printf
re:				fclean all
.PHONY:			all clean fclean re bonus
