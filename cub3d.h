/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 06:39:08 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/04 16:52:44 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define FLOOR 0
# define CIEL 1

# define PI 3.14159265359

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define VERTICAL 1
# define HORIZONTAL 0

# define ESC_KEY 65307
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define MOVE_SPEED 0.3
# define ROTATION_SPEED 0.2

# define PLAYER_RADIUS 0.2

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_img
{
	int			width;
	int			hight;
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_data
{
	char		**map;
	char		*textures[4];
	int			color[2];
	void		*mlx;
	void		*win;
	t_img		scren_img;
	t_img		tex_img[4];
	t_player	player;

}				t_data;

int				parsing(t_data *map, char *filemap);
int				init(t_data *data);
void			init_player(t_data *data);
void			render(t_data *data);

void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			rotate(t_data *data, double rotate_angle);
void			shift_to_right(t_data *data);
void			shift_to_left(t_data *data);

void			free_arr(char **arr);
void			free_textures(char **s);

/**************************LIBFT***************************/

int				ft_isdigit(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
void			ft_putstr_fd(char *s, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);

/**************************LIBFT***************************/

#endif
