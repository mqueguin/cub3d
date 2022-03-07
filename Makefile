NAME	        =		cub3D

NAME_B          =       cub3D_bonus

SRCS            =       srcs/main.c\
						srcs/ft_parse.c\
						srcs/ft_parse_map.c\
						srcs/ft_init_parse.c\
						srcs/ft_check_space_map.c\
						srcs/ft_map_is_close.c\
						srcs/ft_parse_utils.c\
						srcs/ft_parse_utils2.c\
						srcs/ft_recover_map.c\
						srcs/ft_utils.c\
						srcs/check_file.c\
						srcs/cub3d_utils.c\
						srcs/ft_parse_settings.c\

SRCS_B      =       $(wildcard srcs_bonus/*.c)

INCLUDES_DIR     =       includes/

INCLUDES_DIR_B  =       includes_bonus/

LIB_DIR         =       libft/

LIBFT           =       libft/libft.a

CC              =       gcc

OBJS            =       ${SRCS:.c=.o}

OBJS_B          =       ${SRCS_B:.c=.o}

MLX         =       minilibx/libmlx_Linux.a

MLX_DIR     =       minilibx/

RM          =       rm -rf

#MACOS
#LFLAGS		=			-framework OpenGL -framework AppKit

#LINUX
#LFLAGS       =       -lm -lbsd -lX11 -lXext

FLAGS       =       -Wall -Wextra -Werror

.c.o:
					@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}
					@echo "\x1b[32m[ LOADED ]\033[0m ${<:.s=.o}"

all:			${NAME}

${NAME}:		${OBJS}
						@make -C ${LIB_DIR}
						@make -C ${LIB_DIR} bonus
						@${CC} ${FLAGS} ${LFLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS} ${LIBFT} #${MLX}
						@echo "\nlibft.a has been created"
						@echo "cub3d has been created"

bonus:		${OBJS_B}
						@make -C ${LIB_DIR}
						@make -C ${LIB_DIR} bonus
						@${CC} ${FLAGS} ${LFLAGS} -I ${INCLUDES_DIR_B} -o ${NAME_B} ${OBJS_B} ${LIBFT} ${MLX}
						@echo "\nlibft.a has been created"
						@echo "cub3d_bonus has been created"

clean:
						@make -C ${LIB_DIR} clean
						@${RM} ${OBJS} ${OBJS_B}
						@echo "\n *.o files deleted\n"

fclean:		clean
						@make -C ${LIB_DIR} fclean
						@${RM} ${NAME} ${NAME_B}
						@echo "\nPrograms The libft and cub3d have been deleted\n"

re:		fclean all

.PHONY:           all     clean   fclean  re
