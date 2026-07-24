NAME := cub3D
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFLAGS := -Iincludes \
	-Iincludes/render \
	-Iincludes/render/destroy \
	-Iincludes/render/draw \
	-Iincludes/render/math \
	-Iincludes/render/player_ctrl \
	-Iincludes/render/projection \
	-Iincludes/render/ray \
	-Iincludes/render/texture \
	-Iminilibx-linux
BUILD_DIR := build
COMMON_SRC := src/core/error.c src/core/game.c
PARSER_SRC := src/parsing/parse_scene.c
RENDER_SRC := \
	src/rendering/render_game.c \
	src/rendering/destroy/render_destroy.c \
	src/rendering/draw/render_draw.c \
	src/rendering/draw/render_draw_shapes.c \
	src/rendering/frame/render_frame.c \
	src/rendering/frame/render_frame_ray.c \
	src/rendering/hooks/render_hooks.c \
	src/rendering/math/render_math_vector.c \
	src/rendering/player_ctrl/render_pc_collision_check.c \
	src/rendering/player_ctrl/render_pc_move.c \
	src/rendering/player_ctrl/render_pc_rotate.c \
	src/rendering/projection/render_projection.c \
	src/rendering/ray/render_ray_build.c \
	src/rendering/ray/render_ray_setup.c \
	src/rendering/ray/render_ray_dda.c \
	src/rendering/texture/render_texture.c \
	src/rendering/texture/render_texture_color.c \
	src/rendering/texture/render_texture_draw.c \
	src/rendering/texture/render_texture_load.c \
	src/rendering/texture/render_texture_map.c \
	src/rendering/texture/render_texture_sample.c \
	src/rendering/texture/render_texture_select.c
SRC := src/main.c $(COMMON_SRC) $(PARSER_SRC) $(RENDER_SRC)
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

DEV_PARSE := cub3d_parser
DEV_PARSE_SRC := dev/parser_main.c $(COMMON_SRC) $(PARSER_SRC)
DEV_PARSE_OBJ := $(DEV_PARSE_SRC:%.c=$(BUILD_DIR)/%.o)

DEV_RENDER := cub3d_renderer
DEV_RENDER_SRC := dev/renderer_main.c $(COMMON_SRC) $(RENDER_SRC)
DEV_RENDER_OBJ := $(DEV_RENDER_SRC:%.c=$(BUILD_DIR)/%.o)

MLX_DIR := minilibx-linux
MLX_LIB := $(MLX_DIR)/libmlx.a

LDLIBS := $(MLX_LIB) -lXext -lX11 -lm

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

dev-parse: $(DEV_PARSE)

$(DEV_PARSE): $(DEV_PARSE_OBJ)
	$(CC) $(CFLAGS) $(DEV_PARSE_OBJ) -o $(DEV_PARSE)

dev-render: $(DEV_RENDER)

$(DEV_RENDER): $(MLX_LIB) $(DEV_RENDER_OBJ)
	$(CC) $(CFLAGS) $(DEV_RENDER_OBJ) $(LDLIBS) -o $(DEV_RENDER)

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
