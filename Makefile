# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 18:54:15 by mqueguin          #+#    #+#              #
#    Updated: 2021/04/15 18:07:08 by mqueguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRC_BONUS		=	bonus/bonus.c\
# 				bonus/screen_shot.c\
# 				bonus/check_color_data.c\
# 				bonus/check_map.c\
# 				bonus/check_is_map_close.c\
# 				bonus/check_is_map_close_last_column.c\
# 				bonus/check_param_file.c\
# 				bonus/check_path.c\
# 				bonus/check_resolution.c\
# 				bonus/display.c\
# 				bonus/draw_column_px.c\
# 				bonus/esc_game.c\
# 				bonus/exit_game.c\
# 				bonus/free_data.c\
# 				bonus/get_color.c\
# 				bonus/get_info.c\
# 				bonus/load_file.c\
# 				bonus/get_map.c\
# 				bonus/get_texture_and_sprite.c\
# 				bonus/get_texture_path.c\
# 				bonus/init.c\
# 				bonus/init_2.c\
# 				bonus/key.c\
# 				bonus/main.c\
# 				bonus/move_player.c\
# 				bonus/parsing.c\
# 				bonus/print_texture.c\
# 				bonus/raycasting.c\
# 				bonus/raycasting_2.c\
# 				bonus/sprite.c\
# 				bonus/sprite_utils.c\
# 				bonus/utils.c


# INCLUDE_BONUS		=	bonus/cub3d.h\
# 				bonus/ft_printf.h\
# 				bonus/get_next_line.h\
# 				bonus/libft.h\
# 				bonus/mlx.h

SRC_NAME		=	main.c\
			check_file.c\
			cub3d_utils.c\
			ft_check_space_map.c\
			ft_init_parse.c\
			ft_map_is_close.c\
			ft_parse_map.c\
			ft_parse_settings.c\
			ft_parse_utils.c\
			ft_parse_utils2.c\
			ft_parse.c\
			ft_recover_map.c\
			ft_utils.c\
			ft_init_game.c\
			ft_events.c\
			mlx_utils.c\
			ft_raycasting.c\
			ft_raycasting_init.c\
			ft_player_move.c\
			ft_textures.c

INCLUDE_NAME		=	cub3d.h\
				libft.h\
				mlx.h

NAME		= Cub3D

CC		= clang

RM		= rm -rf

CP		= cp -r

LS		= ls -la

CFLAGS		=  -c#-Wall -Wextra -Werror -g -c

#LFLAGS		= -framework OpenGL -framework AppKit
LFLAGS		= -lm -lbsd -lX11 -lXext

#OBJ_BONUS		= $(SRC_BONUS:.c=.o)

OBJ_NAME		= $(SRC_NAME:.c=.o)

LIBMLX_MAC		= libmlx.a

LIBMLX_NAME		= libmlx_Linux.a

LIBFT_NAME		= libft.a

INCLUDE_PATH		= ./includes

SRC_PATH		= ./srcs

OBJ_PATH		= ./.obj

LIBFT_SRC_PATH		= ./libft

MLX_LINUX_PATH		= ./minilibx

INCLUDE			= $(addprefix $(INCLUDE_PATH)/, $(INCLUDE_NAME))

SRC			= $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ			= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LIBFT			= $(addprefix $(INCLUDE_PATH)/, $(LIBFT_NAME))

LIBFT_SRC		= $(addprefix $(LIBFT_SRC_PATH)/, $(LIBFT_NAME))

#LIBPRINTF_SRC		= $(addprefix $(LIBPRINTF_SRC_PATH)/, $(LIBPRINTF_NAME))

LIBMLX_LINUX		= $(addprefix $(MLX_LINUX_PATH)/, $(LIBMLX_NAME))

all: $(OBJ_PATH) $(LIB_PATH) $(NAME)

$(OBJ_PATH):
	@echo Creating object directory
	@mkdir -p $(OBJ_PATH)

$(LIB_PATH):
	@echo Creating library directory
	@mkdir -p $(LIB_PATH)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX_LINUX) $(INCLUDE)
	@echo Compiling executable $(NAME)..
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX_LINUX) $(LFLAGS)
	@$(LS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo Compiling $< in $@..
	@$(CC) -o $@ $(CFLAGS) $<

# $(LIBPRINTF): $(LIBPRINTF_SRC)
# 	@echo Copy $(LIBPRINTF_SRC) in $(LIBPRINTF)..
# 	@$(CP) $(LIBPRINTF_SRC) $(LIBPRINTF)

# $(LIBPRINTF_SRC):
# 	@echo Compiling FT_PRINTF..
# 	@(cd $(LIBPRINTF_SRC_PATH) && $(MAKE))

$(LIBFT): $(LIBFT_SRC)
	@echo Copy $(LIBFT_SRC) in $(LIBFT)..
	@($(CP) $(LIBFT_SRC) $(LIBFT))

$(LIBFT_SRC):
	@echo Compiling LIBFT..
	@(cd $(LIBFT_SRC_PATH) && $(MAKE))

#$(LIBMLX_LINUX):
#	@echo Compiling minilibx linux..
#	@(cd $(MLX_LINUX_PATH) && $(MAKE))

#bonus :  $(OBJ_BONUS) $(LIBPRINTF) $(LIBFT) $(LIBMLX_LINUX) $(INCLUDE_BONUS)
#	@echo Compiling executable $(NAME)..
#	@$(CC) -o $(NAME) $(OBJ_BONUS) $(LIBPRINTF) $(LIBFT) $(LIBMLX_LINUX) $(LFLAGS)
#	@$(LS)

clean:
	@echo Delete $(OBJ)..
	@$(RM) $(OBJ) $(OBJ_PATH)
	@echo Delete library files and directory
	@$(RM) $(LIBFT) $(LIB_PATH)
	@(cd && $(MAKE) clean)
	@$(LS)
	#@(cd $(MLX_LINUX_PATH) && $(MAKE) clean)
	#@$(LS)

# fclean: clean
# 	@echo Delete executable $(NAME)..
# 	@$(RM) $(NAME)
# 	@echo Delete library $(LIBFT)..
# 	rm bonus/*.o
# 	@echo Delete $(OBJ_BONUS)
# 	@(cd $(LIBFT_SRC_PATH) && $(RM) $(LIBFT_NAME) && $(LS))
# 	@echo Delete library $(LIBPRINTF)..
# 	@(cd $(LIBPRINTF_SRC_PATH) && $(MAKE) fclean && $(LS))
# 	@$(LS)

re : fclean all

.PHONY: all clean fclean re