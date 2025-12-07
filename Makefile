NAME = cub3D

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -Iinc -Ilibft -Iget_next_line -Iminilibx-linux #-fsanitize=address
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
GNL_DIR = get_next_line
MLX_DIR = minilibx-linux

SRCS = $(SRC_DIR)/main.c \
	   $(SRC_DIR)/parsing/parsing.c \
	   $(SRC_DIR)/parsing/parsing_utils.c \
	   $(SRC_DIR)/parsing/checking_up_side_down_file.c \
	   $(SRC_DIR)/parsing/floot_flit_checking.c \
	   $(SRC_DIR)/parsing/parsing_texture.c \
	   $(SRC_DIR)/parsing/parsing_texture_utils.c \
	   $(SRC_DIR)/parsing/parsing_texture_utils_1.c \
	   $(SRC_DIR)/parsing/parsing_texture_utils_2.c \
	   $(SRC_DIR)/parsing/parsing_map.c \
	   $(SRC_DIR)/parsing/parsing_valid_map.c \
	   $(SRC_DIR)/parsing/map_valid.c \
	   $(SRC_DIR)/parsing/map_valid_utils.c \
	   $(SRC_DIR)/free/free_map_type_idet.c \
	   $(SRC_DIR)/free/free_map.c \
	   $(SRC_DIR)/free/free_map_map.c \
	   $(SRC_DIR)/free/free_split.c \
       $(GNL_DIR)/get_next_line.c \
       $(GNL_DIR)/get_next_line_utils.c
#        $(SRC_DIR)/valid_map/check_valid_map.c \
#        $(SRC_DIR)/valid_map/is_map_valid.c \

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX   = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean || true

re: fclean all

.PHONY: all clean fclean re
