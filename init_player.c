/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:13:56 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/03 21:13:00 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_direction(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	else if (data->map[i][j] == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	else if (data->map[i][j] == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	else if (data->map[i][j] == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("SNWE", data->map[i][j]))
			{
				data->player.x = j + 0.5;
				data->player.y = i + 0.5;
				init_player_direction(data, i, j);
				data->player.plane_x = -data->player.dir_y * tan((PI / 3) / 2);
				data->player.plane_y = data->player.dir_x * tan((PI / 3) / 2);
				break ;
			}
			j++;
		}
		i++;
	}
}
