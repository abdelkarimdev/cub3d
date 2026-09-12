/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 06:58:02 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/04 16:59:16 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_xpm_files(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->tex_img[i].ptr = mlx_xpm_file_to_image(data->mlx, \
		data->textures[i], &data->tex_img[i].width, &data->tex_img[i].hight);
		if (data->tex_img[i].ptr == NULL)
		{
			while (--i >= 0)
				mlx_destroy_image(data->mlx, data->tex_img[i].ptr);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	init_screen_image(t_data *data)
{
	data->scren_img.ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (data->scren_img.ptr == NULL)
		return (1);
	data->scren_img.addr = mlx_get_data_addr(data->scren_img.ptr, \
			&data->scren_img.bpp, &data->scren_img.line_len, \
			&data->scren_img.endian);
	if (data->scren_img.addr == NULL)
	{
		mlx_destroy_image(data->mlx, data->scren_img.ptr);
		return (1);
	}
	return (0);
}

static int	init_images(t_data *data)
{
	int	i;

	if (init_screen_image(data) == 1)
		return (ft_putstr_fd("Error\n faild in load screen image", 2), 1);
	if (load_xpm_files(data) == 1)
	{
		mlx_destroy_image(data->mlx, data->scren_img.ptr);
		return (ft_putstr_fd("Error\n faild in load images", 2), 1);
	}
	i = 0;
	while (i < 4)
	{
		data->tex_img[i].addr = mlx_get_data_addr(data->tex_img[i].ptr, \
				&data->tex_img[i].bpp, &data->tex_img[i].line_len, \
				&data->tex_img[i].endian);
		if (data->tex_img[i].addr == NULL)
			return (ft_putstr_fd("Error\n faild in get data of images", 2), 1);
		i++;
	}
	return (0);
}

int	init(t_data *data)
{
	int	i;

	init_player(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_putstr_fd("Error\n faild in initialize mlx", 2), 1);
	if (init_images(data) == 1)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (data->win == NULL)
	{
		i = 0;
		while (i < 4)
			mlx_destroy_image(data->mlx, data->tex_img[i++].ptr);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (ft_putstr_fd("Error\n faild in create window", 2), 1);
	}
	return (0);
}
