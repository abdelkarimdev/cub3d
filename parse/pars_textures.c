/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:56:43 by aben-el-          #+#    #+#             */
/*   Updated: 2026/01/04 16:02:47 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_type(char *file_str, int *color_flag)
{
	if (!ft_strncmp(file_str, "NO ", 3))
		return (NORTH);
	if (!ft_strncmp(file_str, "SO ", 3))
		return (SOUTH);
	if (!ft_strncmp(file_str, "WE ", 3))
		return (WEST);
	if (!ft_strncmp(file_str, "EA ", 3))
		return (EAST);
	if (!ft_strncmp(file_str, "F ", 2))
	{
		*color_flag = 1;
		return (FLOOR);
	}
	if (!ft_strncmp(file_str, "C ", 2))
	{
		*color_flag = 1;
		return (CIEL);
	}
	return (-1);
}

char	*get_line(size_t *offset, char *file_str)
{
	char	*line;
	size_t	len;
	size_t	size;

	size = ft_strlen(file_str);
	if (size < *offset)
		return (NULL);
	skip_newline(offset, file_str);
	len = into_newline(*offset, file_str) - *offset;
	line = ft_substr(file_str, *offset, len);
	if (!line)
		return (NULL);
	*offset += ft_strlen(line) + 1;
	return (line);
}

int	pars_texture(t_data *map, int type, char *textures)
{
	if (map->textures[type] == NULL)
	{
		map->textures[type] = ft_strdup(textures);
		if (!map->textures[type])
			return (ft_putstr_fd("Error", 2), 1);
	}
	else
	{
		ft_putstr_fd("Error\nthere is dup textures check agin", 2);
		return (1);
	}
	return (0);
}

int	main_pars(int color_flag, char *line, int type, t_data *map)
{
	char	*texture_line;
	char	*color_line;

	if (!color_flag)
	{
		texture_line = get_path(line, 3);
		if (!texture_line)
			return (ft_putstr_fd("Error\nInvalid textures ", 2), 1);
		if (pars_texture(map, type, texture_line))
			return (1);
	}
	else if (color_flag)
	{
		color_line = get_path(line, 2);
		if (!color_line)
			return (ft_putstr_fd("Error\nInvalid color ", 2), 1);
		if (pars_color(map, type, color_line))
			return (1);
	}
	return (0);
}

int	pars_args(t_data *map, char *file_str, size_t *offset)
{
	char	*line;
	char	*tmp;
	int		i;
	int		type;
	int		color_flag;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		color_flag = 0;
		tmp = line;
		line = get_line(offset, file_str);
		if (!line)
			return (free(tmp), ft_putstr_fd("Error\ngetline fail", 2), 1);
		free(tmp);
		type = get_type(line, &color_flag);
		if (type == -1)
			return (free(line),
				ft_putstr_fd("Error\ninvlid texture or color Element", 2), 1);
		if (main_pars(color_flag, line, type, map))
			return (free(line), 1);
		i++;
	}
	return (free(line), 0);
}
