/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:49:24 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/04 15:49:55 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cub3d.h"

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		distance;
	double		wall_x;
	int			side;
}				t_ray;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	double	t_max_x;
	double	t_max_y;
	double	t_delta_x;
	double	t_delta_y;
	int		step_x;
	int		step_y;
}			t_dda;

typedef struct s_line
{
	int		draw_start;
	int		draw_end;
	int		height;
}			t_line;

void	cast_ray(t_data *data, t_ray *ray, int x);
void	render(t_data *data);
void	put_pixel_to_image(t_img *img, int x, int y, int color);
int		get_pixel_from_image(t_img *img, int x, int y);
void	clear_buffer(t_data *data);

#endif
