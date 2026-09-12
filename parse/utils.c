/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-el- <aben-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:31:35 by aben-el-          #+#    #+#             */
/*   Updated: 2025/12/27 12:01:47 by aben-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	skip_newline(size_t *offset, char *file_str)
{
	while (file_str[*offset] == '\n')
	{
		(*offset)++;
	}
}

size_t	into_newline(size_t offset, char *str)
{
	size_t	i;

	i = offset;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*get_name(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	return (path[i - 1]);
}

int	get_comma_len(char *arr)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (arr[i])
	{
		if (arr[i] == ',')
			count++;
		i++;
	}
	return (count);
}
