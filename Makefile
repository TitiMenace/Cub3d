SRC_FILES		=	main.c 

SRC_DIR 		= srcs

SRC		=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

LIBS_FOLDER		=  lib

INCLUDES_DIR	= includes

INCLUDES_FILES	= 	includes.h\
					cub3d.h\
					struct.h

INCLUDES		= $(addprefix $(INCLUDES_DIR)/,$(INCLUDES_FILES))

OBJ_DIR = .build

OBJ		= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC) )

MLX_DIR = minilibx
MLX = ./$(LIBS_FOLDER)/$(MLX_DIR)/libmlx_Linux.a

LIBS = $(MLX)

NAME	=	cub3d

CC		=	cc

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBS)
			$(CC) $(OBJ) $(LIBS) -lm -lXext -lX11 -o $(NAME)
			@echo "\033[1;32m\nDone!\033[0m"

$(OBJ_DIR)/%.o 		:	$(SRC_DIR)/%.c $(INCLUDES)
						@printf "\033[0;33m Generating fdf object... %-38.38s \r" $@
						@mkdir -p $(OBJ_DIR)
						@$(CC) -Wall -Wextra -Werror -g3 -O3 -Ofast -c -I $(INCLUDES_DIR) $< -o $@

clean	:
			rm -rf $(OBJ_DIR)
			rm -rf $(OBJ_BONUS_DIR)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

bonus	:	all

$(LIBS)	:				
			make -C $(LIBS_FOLDER)/$(MLX_DIR)

cleanlib :
			make fclean -C $(LIBS_FOLDER)/$(MLX_DIR)

.PHONY	:	all clean fclean re cleanlib
