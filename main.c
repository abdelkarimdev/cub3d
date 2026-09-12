/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 06:39:37 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/04 16:00:24 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->tex_img[i].ptr);
		i++;
	}
	mlx_destroy_image(data->mlx, data->scren_img.ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_arr(data->map);
	free_textures(data->textures);
	exit(0);
}

int	key_press(int keycode, t_data *d)
{
	if (keycode == ESC_KEY)
		close_game(d);
	if (keycode == W_KEY)
		move_forward(d);
	if (keycode == S_KEY)
		move_backward(d);
	if (keycode == A_KEY)
		shift_to_right(d);
	if (keycode == D_KEY)
		shift_to_left(d);
	if (keycode == LEFT_KEY)
		rotate(d, -ROTATION_SPEED);
	if (keycode == RIGHT_KEY)
		rotate(d, +ROTATION_SPEED);
	render(d);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd("Error\nIvalid args", 2), 1);
	if (parsing(&data, av[1]) == 1)
		return (1);
	if (init(&data) == 1)
	{
		free_arr(data.map);
		free_textures(data.textures);
		return (1);
	}
	mlx_hook(data.win, 17, 0, close_game, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	render(&data);
	mlx_loop(data.mlx);
	return (0);
}
