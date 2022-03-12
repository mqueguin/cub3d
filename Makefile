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
						srcs/ft_parse_utils3.c\
						srcs/ft_recover_map.c\
						srcs/ft_utils.c\
						srcs/check_file.c\
						srcs/cub3d_utils.c\
						srcs/ft_parse_settings.c\
						srcs/ft_parse_identifier.c\
						srcs/ft_events.c\
						srcs/ft_init_game.c\
						srcs/ft_player_move.c\
						srcs/ft_raycasting_init.c\
						srcs/ft_raycasting.c\
						srcs/ft_textures.c\
						srcs/ft_texture2.c\
						srcs/mlx_utils.c

SRCS_B      =       bonus/srcs_bonus/main_bonus.c\
					bonus/srcs_bonus/ft_parse_bonus.c\
					bonus/srcs_bonus/ft_parse_map_bonus.c\
					bonus/srcs_bonus/ft_init_parse_bonus.c\
					bonus/srcs_bonus/ft_check_space_map_bonus.c\
					bonus/srcs_bonus/ft_map_is_close_bonus.c\
					bonus/srcs_bonus/ft_parse_utils_bonus.c\
					bonus/srcs_bonus/ft_parse_utils2_bonus.c\
					bonus/srcs_bonus/ft_parse_utils3_bonus.c\
					bonus/srcs_bonus/ft_recover_map_bonus.c\
					bonus/srcs_bonus/ft_utils_bonus.c\
					bonus/srcs_bonus/check_file_bonus.c\
					bonus/srcs_bonus/cub3d_utils_bonus.c\
					bonus/srcs_bonus/ft_parse_settings_bonus.c\
					bonus/srcs_bonus/ft_parse_identifier_bonus.c\
					bonus/srcs_bonus/ft_events_bonus.c\
					bonus/srcs_bonus/ft_init_game_bonus.c\
					bonus/srcs_bonus/ft_player_move_bonus.c\
					bonus/srcs_bonus/ft_raycasting_init_bonus.c\
					bonus/srcs_bonus/ft_raycasting_bonus.c\
					bonus/srcs_bonus/ft_textures_bonus.c\
					bonus/srcs_bonus/ft_texture2_bonus.c\
					bonus/srcs_bonus/mlx_utils_bonus.c

INCLUDES_DIR     =       includes/

INCLUDES_DIR_B  =       bonus/includes_bonus/

LIB_DIR         =       libft/

LIBFT           =       libft/libft.a

CC              =       gcc

OBJS            =       ${SRCS:.c=.o}

OBJS_B          =       ${SRCS_B:.c=.o}

MLX         =       minilibx/libmlx.a

MLX_DIR     =       minilibx/

RM          =       rm -rf

#MACOS
LFLAGS		=			-framework OpenGL -framework AppKit

#LINUX
#LFLAGS       =       -lm -lbsd -lX11 -lXext

FLAGS       =       -Wall -Wextra -Werror -g #-ggdb3

.c.o:
					@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}
					@echo "\x1b[32m[ LOADED ]\033[0m ${<:.s=.o}"

all:			${NAME}

${NAME}:		${OBJS}
						@make -C ${LIB_DIR}
						@make -C ${LIB_DIR} bonus
						@${CC} ${FLAGS} ${LFLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS} ${LIBFT} ${MLX}
						@echo "\nlibft.a has been created"
						@echo "cub3d has been created"

bonus:		${OBJS_B}
						@make -C ${LIB_DIR}
						@make -C ${LIB_DIR} bonus
						@${CC} ${FLAGS} ${LFLAGS} -I ${INCLUDES_DIR} -o ${NAME_B} ${OBJS_B} ${LIBFT} ${MLX}
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
