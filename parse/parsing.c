/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:31:45 by aben-el-          #+#    #+#             */
/*   Updated: 2026/01/04 16:02:47 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	pars_map(t_data *_map, char *file_str, size_t offset)
{
	char	**map;
	char	*tmp;
	size_t	len;

	len = ft_strlen(file_str);
	tmp = file_str;
	if (len >= offset)
	{
		file_str = ft_strtrim(&file_str[offset], "\n");
		if (!file_str || !*file_str)
			return (free(tmp), free(file_str),
				ft_putstr_fd("Error no matched map", 2), 1);
	}
	else
		return (free(file_str), ft_putstr_fd("Error no map detected", 2), 1);
	free(tmp);
	if (valid_ement(file_str))
		return (free(file_str), 1);
	map = ft_split(file_str, '\n');
	if (!map)
		return (free(file_str), ft_putstr_fd("Error split", 2), 1);
	if (check_map(map))
		return (free_arr(map), free(file_str), 1);
	_map->map = map;
	return (free(file_str), 0);
}

static int	read_file(char *file_name, char **file_str)
{
	int		read_len;
	char	buff[11];
	char	*tmp;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	while (true)
	{
		read_len = read(fd, buff, 10);
		if (read_len <= 0)
			break ;
		buff[read_len] = '\0';
		tmp = *file_str;
		*file_str = ft_strjoin(*file_str, buff);
		if (!*file_str)
			return (free(tmp), close(fd), 1);
		free(tmp);
	}
	if (read_len < 0)
		return (free(*file_str), close(fd), 1);
	close(fd);
	return (0);
}

static int	parse_file_name(char *path)
{
	char	**file_name;
	char	*name;

	file_name = ft_split(path, '/');
	if (!file_name)
		return (ft_putstr_fd("Error\naccuring while spliting", 2), 1);
	name = get_name(file_name);
	if (ft_strlen(name) <= 4)
	{
		ft_putstr_fd("Error\nInvalid path map", 2);
		return (free_arr(file_name), 1);
	}
	if (ft_strncmp(&name[ft_strlen(name) - 4], ".cub", 4))
	{
		ft_putstr_fd("Error\nInvalid map extension", 2);
		return (free_arr(file_name), 1);
	}
	free_arr(file_name);
	return (0);
}

int	parsing(t_data *map, char *filemap)
{
	char	*file_str;
	size_t	offset;

	file_str = NULL;
	offset = 0;
	init_t_map(map);
	if (parse_file_name(filemap))
		return (1);
	if (read_file(filemap, &file_str) || !file_str)
		return (ft_putstr_fd("Error\naccuring while reading the file", 2), 1);
	if (pars_args(map, file_str, &offset))
		return (free(file_str), free_textures(map->textures), 1);
	if (pars_map(map, file_str, offset))
		return (free_textures(map->textures), 1);
	return (0);
}
