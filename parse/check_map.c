/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:12:40 by aben-el-          #+#    #+#             */
/*   Updated: 2026/01/04 16:02:47 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_ement(char *file_str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (file_str[i + 1])
	{
		if (!ft_strchr(" 01SNWE\n", file_str[i]))
		{
			ft_putstr_fd("Error\ninvalid map[invalid Element detected]", 2);
			return (1);
		}
		if (file_str[i] == '\n' && file_str[i + 1] == '\n')
		{
			ft_putstr_fd("Error\ninvalid map [empty line in map]", 2);
			return (1);
		}
		if (ft_strchr("SNWE", file_str[i]))
			count++;
		i++;
	}
	if (!count || count > 1)
		return (ft_putstr_fd("Error\ninvalid map [too many players]", 2), 1);
	return (0);
}

int	is_walkable(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	is_space(char **map, int i, int j)
{
	if (j >= (int)ft_strlen(map[i]))
		return (1);
	if (map[i][j] == ' ')
		return (1);
	return (0);
}

int	check_holes(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i + 1])
	{
		j = 0;
		if (!ft_strchr(" 1", map[i][0]) || !ft_strchr(" 1",
				map[i][ft_strlen(map[i]) - 1]))
			return (ft_putstr_fd("Error\nmap not closed", 2), 1);
		while (map[i][j + 1])
		{
			if (ft_strchr("0NSEW", map[i][j]))
			{
				if (is_space(map, i, j - 1) || is_space(map, i, j + 1)
					|| is_space(map, i - 1, j) || is_space(map, i + 1, j))
					return (ft_putstr_fd("Error\nInvalid map [hole]", 2), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(char **map)
{
	if (is_walkable(map[0]))
		return (ft_putstr_fd("Error\ninvalid map [map not closed]", 2), 1);
	if (check_holes(map))
		return (1);
	if (is_walkable(map[arr_size(map) - 1]))
		return (ft_putstr_fd("Error\ninvalid map [map not closed]", 2), 1);
	return (0);
}
