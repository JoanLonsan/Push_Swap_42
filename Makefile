
NAME		= push_swap
CHECK		= checker

SRCS		=	src/instructions_a.c src/instructions_b.c src/instructions_c.c src/main.c \
				src/radix.c src/simple.c src/simple_b.c utils/check_args.c utils/index.c \
				utils/t_list.c utils/tprint_and_errors.c utils/utils.c \

CHECK_SRCS	=	utils/check_args.c utils/index.c utils/t_list.c utils/tprint_and_errors.c \
				utils/utils.c bonus/checker_bonus.c bonus/cmds.c src/instructions_a.c \
				src/instructions_b.c src/instructions_c.c \

OBJS		= ${SRCS:.c=.o}
CHECK_OBJS	= ${CHECK_SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Iincludes -fsanitize=address

ECHO		= echo
RM			= rm -rf

DEF_COLOR	=	\033[0;39m
GREEN		=	\033[1;92m

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@$(ECHO) "Dependencies: $(GREEN)100%$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@$(ECHO) "Push_Swap: $(GREEN)Created ✔️$(DEF_COLOR)"

bonus: ${NAME} ${CHECK}

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}
	@$(ECHO) "Checker: $(GREEN)Created ✔️$(DEF_COLOR)"

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}
	@$(ECHO) "Push_Swap: objc. files$(DEF_COLOR)$(GREEN) Cleaned ✔️$(DEF_COLOR)"

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}
	@$(ECHO) "Push_Swap: exec. files$(DEF_COLOR)$(GREEN) Cleaned ✔️$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
