
CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = cub3D

SRCS = ./main.c\
		parse/pars_color.c\
		parse/parsing.c\
		parse/utils.c\
		parse/check_map.c\
		parse/pars_textures.c\
		parse/costum.c\
		parse/free_func.c\
		libft_utils/ft_calloc.c\
		libft_utils/ft_isdigit.c\
		libft_utils/ft_memcpy.c\
		libft_utils/ft_putstr_fd.c\
		libft_utils/ft_substr.c\
		libft_utils/ft_split.c\
		libft_utils/ft_strchr.c\
		libft_utils/ft_strdup.c\
		libft_utils/ft_strjoin.c\
		libft_utils/ft_strlen.c\
		libft_utils/ft_strtrim.c\
		libft_utils/ft_bzero.c\
		libft_utils/ft_strncmp.c\
		render/render.c\
		render/cast_ray.c\
		render/render_utils.c\
		./init.c\
		./init_player.c\
		./movement.c\

OBJ = ${SRCS:.c=.o}

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I/usr/include/minilibx-linux -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
