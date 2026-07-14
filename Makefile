NAME := cub3D
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -Iincludes

BUILD_DIR := build
COMMON_SRC := src/core/error.c src/core/game.c
PARSER_SRC := src/parsing/parse_scene.c
RENDER_SRC := src/rendering/render_game.c
SRC := src/main.c $(COMMON_SRC) $(PARSER_SRC) $(RENDER_SRC)
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

DEV_PARSE := cub3d_parser
DEV_PARSE_SRC := dev/parser_main.c $(COMMON_SRC) $(PARSER_SRC)
DEV_PARSE_OBJ := $(DEV_PARSE_SRC:%.c=$(BUILD_DIR)/%.o)

DEV_RENDER := cub3d_renderer
DEV_RENDER_SRC := dev/renderer_main.c $(COMMON_SRC) $(RENDER_SRC)
DEV_RENDER_OBJ := $(DEV_RENDER_SRC:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

dev-parse: $(DEV_PARSE)

$(DEV_PARSE): $(DEV_PARSE_OBJ)
	$(CC) $(CFLAGS) $(DEV_PARSE_OBJ) -o $(DEV_PARSE)

dev-render: $(DEV_RENDER)

$(DEV_RENDER): $(DEV_RENDER_OBJ)
	$(CC) $(CFLAGS) $(DEV_RENDER_OBJ) -o $(DEV_RENDER)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME) $(DEV_PARSE) $(DEV_RENDER)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus dev-parse dev-render
