/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:26:39 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/05 10:35:52 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	determine_face(t_ray *ray)
{
	if (ray->side == HORIZONTAL)
	{
		if (ray->ray_dir_y < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
	else
	{
		if (ray->ray_dir_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	return (0);
}

static int	get_color(t_data *data, t_ray *ray, int tex_y)
{
	int	tex_x;
	int	face;
	int	img_width;

	face = determine_face(ray);
	img_width = data->tex_img[face].width;
	tex_x = (int)(ray->wall_x * img_width);
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= img_width)
		tex_x = img_width - 1;
	if ((ray->side == HORIZONTAL && ray->ray_dir_y > 0)
		|| (ray->side == VERTICAL && ray->ray_dir_x < 0))
		tex_x = img_width - 1 - tex_x;
	return (get_pixel_from_image(&data->tex_img[face], tex_x, tex_y));
}

static void	draw_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (WIN_HEIGHT / 2))
	{
		j = 0;
		while (j < (WIN_WIDTH))
		{
			put_pixel_to_image(&data->scren_img, j, i, data->color[CIEL]);
			j++;
		}
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < (WIN_WIDTH))
		{
			put_pixel_to_image(&data->scren_img, j, i, data->color[FLOOR]);
			j++;
		}
		i++;
	}
}

static void	draw_vertical_line(t_data *data, t_ray *ray, int i, t_line *line)
{
	int		j;
	double	step;
	double	tex_y;
	int		color;
	int		img_hight;

	img_hight = data->tex_img[determine_face(ray)].hight;
	step = (double)img_hight / line->height;
	tex_y = (line->draw_start - WIN_HEIGHT / 2 + line->height / 2) * step;
	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= img_hight)
		tex_y = img_hight - 1;
	j = line->draw_start;
	while (j < line->draw_end)
	{
		tex_y += step;
		color = get_color(data, ray, tex_y);
		put_pixel_to_image(&data->scren_img, i, j, color);
		j++;
	}
}

void	render(t_data *data)
{
	int		i;
	t_ray	ray;
	t_line	line;

	clear_buffer(data);
	draw_background(data);
	i = 0;
	while (i < WIN_WIDTH)
	{
		cast_ray(data, &ray, i);
		line.height = (int)(WIN_HEIGHT / ray.distance);
		line.draw_start = -line.height / 2 + WIN_HEIGHT / 2;
		if (line.draw_start < 0)
			line.draw_start = 0;
		line.draw_end = line.height / 2 + WIN_HEIGHT / 2;
		if (line.draw_end >= WIN_HEIGHT)
			line.draw_end = WIN_HEIGHT;
		draw_vertical_line(data, &ray, i, &line);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->scren_img.ptr, 0, 0);
}
