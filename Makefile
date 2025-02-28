NAME = fract_ol

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SOURCES_FILES = fract_ol.c main.c init.c render.c math_utils.c events.c
				
SRC = $(addprefix $(SRC_DIR)/, $(SOURCES_FILES))

OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES_FILES:.c=.o))
OBJECTS_DIR = objects
SRC_DIR = srcs

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./includes/libft

MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = ./minilibx-linux

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS) 
	@echo "Building..."
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "Ready!"

$(OBJECTS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus -s --no-print-directory

$(MLX):
	@make -C $(MLX_DIR)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

clean:
	@rm -rf $(OBJECTS_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@echo "Cleaned!"

fclean: clean
	@make -C $(LIBFT_DIR) fclean -s --no-print-directory
	@rm -rf $(NAME)

re: fclean all
	@echo "Rebuilded!"

.PHONY: all clean fclean re