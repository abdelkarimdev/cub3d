/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:56:05 by aben-el-          #+#    #+#             */
/*   Updated: 2026/01/04 16:02:47 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	covert_to_rgb(int type, t_data *map, char **value)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = get_color_value(value[0]);
	num2 = get_color_value(value[1]);
	num3 = get_color_value(value[2]);
	if (num1 < 0 || num2 < 0 || num3 < 0)
	{
		ft_putstr_fd("Error\nInvalid RGB", 2);
		return (1);
	}
	if (type == FLOOR && map->color[FLOOR] == -1)
		map->color[FLOOR] = (num1 << 16) | (num2 << 8) | num3;
	else if (type == CIEL && map->color[CIEL] == -1)
		map->color[CIEL] = (num1 << 16) | (num2 << 8) | num3;
	else
	{
		ft_putstr_fd("Error\nInvalid Color there is more than one Color", 2);
		return (1);
	}
	return (0);
}

int	check_color_validity(int type, t_data *map, char *color)
{
	char	**value;

	if (get_comma_len(color) != 2)
		return (ft_putstr_fd("Error\nInvalid Color [too many comma]", 2), 1);
	value = ft_split(color, ',');
	if (!value)
		return (ft_putstr_fd("Error\naccuring while spliting", 2), 1);
	if (arr_size(value) != 3)
	{
		ft_putstr_fd("Error\ncolor should be like [R.G.B]", 2);
		return (free_arr(value), 1);
	}
	if (covert_to_rgb(type, map, value))
		return (free_arr(value), 1);
	free_arr(value);
	return (0);
}

int	pars_color(t_data *map, int type, char *textures)
{
	if (check_color_validity(type, map, textures))
		return (1);
	return (0);
}
