/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:42:07 by aben-el-          #+#    #+#             */
/*   Updated: 2026/01/03 16:41:03 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_space(char *line, int skip)
{
	int	i;

	i = skip;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

char	*get_path(char *line, int skip)
{
	char	*str;
	int		start;

	start = skip_space(line, skip);
	str = &line[start];
	return (str);
}

int	get_color_value(const char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] == ' ')
		i++;
	if (!ft_isdigit(nptr[i]))
		return (-1);
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - 48);
		if (result > 255)
			return (-1);
		i++;
	}
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] && nptr[i] != '\n')
		return (-1);
	return (result);
}

void	init_t_map(t_data *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map->textures[i] = NULL;
		i++;
	}
	map->color[0] = -1;
	map->color[1] = -1;
	map->map = NULL;
}
