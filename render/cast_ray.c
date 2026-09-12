/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:29:15 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/04 14:53:05 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	init_delta(t_ray *ray, t_dda *dda)
{
	if (ray->ray_dir_x == 0)
		dda->t_delta_x = 1e30;
	else
		dda->t_delta_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		dda->t_delta_y = 1e30;
	else
		dda->t_delta_y = fabs(1 / ray->ray_dir_y);
}

void	init_solv(t_data *data, t_ray *ray, t_dda *dda)
{
	dda->step_x = 1;
	dda->step_y = 1;
	init_delta(ray, dda);
	dda->map_x = (int)data->player.x;
	dda->map_y = (int)data->player.y;
	if (ray->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->t_max_x = (data->player.x - dda->map_x) * dda->t_delta_x;
	}
	else
		dda->t_max_x = (dda->map_x + 1.0 - data->player.x)
			* dda->t_delta_x;
	if (ray->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->t_max_y = (data->player.y - dda->map_y) * dda->t_delta_y;
	}
	else
		dda->t_max_y = (dda->map_y + 1.0 - data->player.y)
			* dda->t_delta_y;
}

static int	solv(t_data *data, t_ray *ray, t_dda *dda)
{
	if (dda->t_max_x < dda->t_max_y)
	{
		dda->t_max_x += dda->t_delta_x;
		dda->map_x += dda->step_x;
		ray->side = VERTICAL;
	}
	else
	{
		dda->t_max_y += dda->t_delta_y;
		dda->map_y += dda->step_y;
		ray->side = HORIZONTAL;
	}
	if (data->map[dda->map_y][dda->map_x] == '1')
		return (1);
	return (0);
}

void	cast_ray(t_data *data, t_ray *ray, int i)
{
	t_dda	s;
	double	camera_factor;

	camera_factor = 2 * i / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = data->player.dir_x + data->player.plane_x * camera_factor;
	ray->ray_dir_y = data->player.dir_y + data->player.plane_y * camera_factor;
	init_solv(data, ray, &s);
	while (1)
	{
		if (solv(data, ray, &s))
			break ;
	}
	if (ray->side == VERTICAL)
		ray->distance = (s.t_max_x - s.t_delta_x);
	else
		ray->distance = (s.t_max_y - s.t_delta_y);
	if (ray->side == VERTICAL)
		ray->wall_x = data->player.y + ray->distance * ray->ray_dir_y;
	else
		ray->wall_x = data->player.x + ray->distance * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}
