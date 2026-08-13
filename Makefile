NAME := cub3D
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -Iincludes -Ilibft/inc

BUILD_DIR := build
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
COMMON_SRC := src/core/error.c src/core/game.c
PARSER_SRC := src/parsing/parse_scene.c src/parsing/parse_identifiers.c \
	src/parsing/parse_config.c src/parsing/parse_lines.c \
	src/parsing/parse_finalize.c src/parsing/parse_map_grid.c \
	src/parsing/parse_map_spawn.c src/parsing/parse_map_chars.c \
	src/parsing/parse_map_flood.c src/parsing/parse_map.c
RENDER_SRC := src/rendering/render_game.c
SRC := src/main.c $(COMMON_SRC) $(PARSER_SRC) $(RENDER_SRC)
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

DEV_PARSE := cub3d_parser
DEV_PARSE_SRC := dev/parser_main.c $(COMMON_SRC) $(PARSER_SRC)
DEV_PARSE_OBJ := $(DEV_PARSE_SRC:%.c=$(BUILD_DIR)/%.o)

DEV_RENDER := cub3d_renderer
DEV_RENDER_SRC := dev/renderer_main.c $(COMMON_SRC) $(RENDER_SRC)
DEV_RENDER_OBJ := $(DEV_RENDER_SRC:%.c=$(BUILD_DIR)/%.o)
NORM_FILES := includes src dev

all: $(NAME)

$(NAME): norm $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

dev-parse: $(DEV_PARSE)

$(DEV_PARSE): norm $(DEV_PARSE_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(DEV_PARSE_OBJ) $(LIBFT) -o $(DEV_PARSE)

dev-render: $(DEV_RENDER)

$(DEV_RENDER): norm $(DEV_RENDER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(DEV_RENDER_OBJ) $(LIBFT) -o $(DEV_RENDER)

norm:
	norminette $(NORM_FILES)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(DEV_PARSE) $(DEV_RENDER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

FORCE:

.PHONY: all clean fclean re bonus dev-parse dev-render norm FORCE
