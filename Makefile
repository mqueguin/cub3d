# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 18:54:15 by mqueguin          #+#    #+#              #
#    Updated: 2021/03/24 19:29:09 by mqueguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END		=	\x1b[0m
BOLD	=	\x1b[1m
UNDER	=	\x1b[4m
RED		=	\x1b[31m
GREEN	=	\x1b[32m
YELLOW	=	\x1b[33m
BLUE	=	\x1b[34m
PURPLE	=	\x1b[35m
CYAN	=	\x1b[36m
WHITE	=	\x1b[37m


OBJ_DIR 	=	obj/

SRC_DIR 	=	srcs/

LIB_DIR 	=	libft/

CUB3D_H	=	includes/cub3d.h\

#PRINTF_BONUS_H	=	-I includes_bonus/ft_printf_bonus.h

LIBFT_H		= 	libft/libft.h\

SRCS	 	=	main.c\
				check_file.c\
				cub3d_utils.c\
				ft_init_parse.c\
				ft_parse_map.c\
				ft_parse_settings.c\
				ft_parse_utils.c\
				ft_parse_utils2.c\
				ft_parse.c\
				ft_recover_map.c\


#SRCS_BONUS	=	

NAME 		=	cub3d.a

LIBFT_A 	=	libft.a

CC			=	gcc -Wall -Wextra -Werror $(CUB3D_H) $(LIBFT_H) -c -o

#CC_BONUS	=	gcc -Wall -Wextra -Werror $(PRINTF_BONUS_H) $(LIBFT_H) -c

CFIND		=	$(SRCS:%=$(SRC_DIR)%)

OFILE		=	$(SRCS:%.c=%.o)

#OFILE_BONUS	=	$(SRCS_BONUS:%.c=%.o)

OBJ			=	$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@echo "$(GREEN)\t\t\t\t########################################"
		@echo "\t\t\t\t####                                ####"
		@echo "\t\t\t\t####                                ####"
		@echo "\t\t\t\t####            $(BOLD)$(CYAN)CUB3D$(END)$(GREEN)           ####"
		@echo "\t\t\t\t####                                ####"
		@echo "\t\t\t\t####                                ####"
		@echo "\t\t\t\t########################################\n\n$(END)"
		@mkdir -p $(OBJ_DIR)
		@echo "$(BLUE)Create:$(END) cub3d Object directory $(GREEN)$(BOLD)[OK]$(END)"

$(NAME): $(OBJ)
		@echo "\n\n\t\t$(BOLD)====================== $(GREEN)COMPILATION LIBFT... $(END)$(BOLD)====================$(END)\t\t\n\n"
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo "$(BOLD)$(GREEN)\n\t\t\t-------------------- CUB3D COMPLETE --------------------"

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo "$(BOLD)$(GREEN)[GOOD]$(END) Create: $(@:obj/%=%)"
		@$(CC) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

#bonus:	
#		@echo "$(BOLD)$(CYAN)\n\t\t\t-------------------- Bonus Compilation... --------------------$(END)"
#		@make -C $(LIB_DIR)
#		@$(CC_BONUS) srcs_bonus/*.c
#		@mv *.o srcs_bonus
#		@cp $(LIB_DIR)$(LIBFT_A) 
#		@mv $(LIBFT_A) $(NAME)
#		@ar rc $(NAME) $(OFILE_BONUS)
#		@ranlib $(NAME)
#		@echo "$(BOLD)$(GREEN)\n\t\t\t-------------------- BONUS COMPLETE --------------------$(END)"


clean:
		@/bin/rm -rf $(OBJ_DIR)
		#@rm -rf srcs_bonus/*.o
		@make -C $(LIB_DIR) clean
		@echo "Cleaned cub3d object files"

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo "$(BOLD)$(RED)\t\t\t-_-_-_-_-_-_-_-_-_-_ Cleaned $(NAME) _-_-_-_-_-_-_-_-_-_-$(END)"

re: fclean all

.PHONY: all clean flcean re