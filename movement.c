/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:59:30 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/04 15:34:24 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shift_to_right(t_data *d)
{
	double	move_x;
	double	move_y;
	double	padding_x;
	double	padding_y;

	move_x = d->player.dir_y * MOVE_SPEED;
	move_y = -d->player.dir_x * MOVE_SPEED;
	if (move_x > 0)
		padding_x = PLAYER_RADIUS;
	else
		padding_x = -PLAYER_RADIUS;
	if (move_y > 0)
		padding_y = PLAYER_RADIUS;
	else
		padding_y = -PLAYER_RADIUS;
	if (d->map[(int)(d->player.y)][(int)(d->player.x + move_x
			+ padding_x)] != '1')
		d->player.x += move_x;
	if (d->map[(int)(d->player.y + move_y
			+ padding_y)][(int)(d->player.x)] != '1')
		d->player.y += move_y;
}

void	shift_to_left(t_data *d)
{
	double	move_x;
	double	move_y;
	double	padding_x;
	double	padding_y;

	move_x = -d->player.dir_y * MOVE_SPEED;
	move_y = d->player.dir_x * MOVE_SPEED;
	if (move_x > 0)
		padding_x = PLAYER_RADIUS;
	else
		padding_x = -PLAYER_RADIUS;
	if (move_y > 0)
		padding_y = PLAYER_RADIUS;
	else
		padding_y = -PLAYER_RADIUS;
	if (d->map[(int)(d->player.y)][(int)(d->player.x + move_x
			+ padding_x)] != '1')
		d->player.x += move_x;
	if (d->map[(int)(d->player.y + move_y
			+ padding_y)][(int)(d->player.x)] != '1')
		d->player.y += move_y;
}

void	move_forward(t_data *d)
{
	double	move_x;
	double	move_y;
	double	padding_x;
	double	padding_y;

	move_x = d->player.dir_x * MOVE_SPEED;
	move_y = d->player.dir_y * MOVE_SPEED;
	if (move_x > 0)
		padding_x = PLAYER_RADIUS;
	else
		padding_x = -PLAYER_RADIUS;
	if (move_y > 0)
		padding_y = PLAYER_RADIUS;
	else
		padding_y = -PLAYER_RADIUS;
	if (d->map[(int)d->player.y][(int)(d->player.x + move_x \
			+ padding_x)] != '1')
		d->player.x += move_x;
	if (d->map[(int)(d->player.y + move_y \
			+ padding_y)][(int)d->player.x] != '1')
		d->player.y += move_y;
}

void	move_backward(t_data *d)
{
	double	move_x;
	double	move_y;
	double	padding_x;
	double	padding_y;

	move_x = -d->player.dir_x * MOVE_SPEED;
	move_y = -d->player.dir_y * MOVE_SPEED;
	if (move_x > 0)
		padding_x = PLAYER_RADIUS;
	else
		padding_x = -PLAYER_RADIUS;
	if (move_y > 0)
		padding_y = PLAYER_RADIUS;
	else
		padding_y = -PLAYER_RADIUS;
	if (d->map[(int)d->player.y][(int)(d->player.x + move_x \
			+ padding_x)] != '1')
		d->player.x += move_x;
	if (d->map[(int)(d->player.y + move_y
			+ padding_y)][(int)d->player.x] != '1')
		d->player.y += move_y;
}

void	rotate(t_data *data, double rotate_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rotate_angle)
		- data->player.dir_y * sin(rotate_angle);
	data->player.dir_y = old_dir_x * sin(rotate_angle) + data->player.dir_y
		* cos(rotate_angle);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rotate_angle)
		- data->player.plane_y * sin(rotate_angle);
	data->player.plane_y = old_plane_x * sin(rotate_angle)
		+ data->player.plane_y * cos(rotate_angle);
}
