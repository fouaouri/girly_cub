NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g3
LIBFT = libs/libft
LIBS = $(addprefix $(LIBFT), /libft.a)

PARSING_SRC = parsing/

RAY_CASTING_SRC = ray_casting/

PARSING_FILES = parsing_of_clrs_txtrs.c parsing_of_map.c parsing.c second_pasing.c parsing_of_calors.c\
				parsing_of_map2.c parsing_of_map3.c\

RAY_CASTING_FILES = cub.c functions/get_next_line.c move_pixel.c calculate_dis.c\
					reset_turn_direc.c data_value_mlx.c color_buffer.c init_file.c\
					hori_up_down.c vertical_down.c vertical_up.c

PARSING_F_FILES = $(addprefix $(PARSING_SRC), $(PARSING_FILES))

RAY_CASTING_F_FILES = $(addprefix $(RAY_CASTING_SRC), $(RAY_CASTING_FILES))

ALL_FILES = $(addprefix $(RAY_CASTING_SRC), $(RAY_CASTING_FILES)) \
				$(addprefix $(PARSING_SRC), $(PARSING_FILES))

PARSING_OBJ = $(PARSING_F_FILES:%.c=%.o)

RAY_CASTING_OBJ = $(RAY_CASTING_F_FILES:%.c=%.o)

O_FILES = $(RAY_CASTING_F_FILES:%.c=%.o)
O_FILES += $(PARSING_F_FILES:%.c=%.o)

SILENT = @

all: libft $(NAME)

$(NAME) : $(O_FILES)
	$(SILENT) $(CC) $(CFLAGS) $(ALL_FILES) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

libft:
	$(SILENT)	cd $(LIBFT) && make

clean : 
	$(SILENT) cd $(LIBFT) && make clean
	$(SILENT) rm -rf $(O_FILES)

fclean : clean
	$(SILENT) cd $(LIBFT) && make fclean
	$(SILENT) rm -rf $(NAME)

re : fclean all