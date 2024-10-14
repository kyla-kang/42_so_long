NAME			= so_long

LIBFT			= ./libft/libft.a

CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -L${HOME}/my_libs/minilibx-linux -lmlx -lXext -lX11
INC				= -I${HOME}/my_libs/minilibx-linux -I/usr/include

RM	 			= rm -f

SRCS_DIR		= ./src/
SRCS 			= $(addprefix $(SRCS_DIR), main.c check.c init.c move.c rendor.c utils.c)
OBJS			= ${SRCS:c=o}

all:			${NAME}

${NAME}:		${OBJS}
				@make -C libft/
				@${CC} ${SRCS} ${LIBFT} ${CFLAGS} ${INC} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "${NAME}: Successfully Compiled"

${LIBFT}:
				make -C libft

%.o: %.c
				@${CC} ${CFLAGS} ${INC} -c $< -o $@

clean:
				@make clean -C libft/
				@rm -f ${OBJS}
				@echo "${NAME}: Object files are now clean."

fclean:
				@make fclean -C libft/
				@rm -f ${NAME}
				@echo "${NAME}: ${NAME} is now clean."

re:				fclean all

.PHONY:			all clean fclean re