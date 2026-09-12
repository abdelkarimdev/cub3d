/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-el- <aben-el-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:11:13 by aben-el-          #+#    #+#             */
/*   Updated: 2025/12/27 11:44:13 by aben-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_textures(char **s)
{
	if (s[NORTH])
		free(s[NORTH]);
	if (s[SOUTH])
		free(s[SOUTH]);
	if (s[WEST])
		free(s[WEST]);
	if (s[EAST])
		free(s[EAST]);
}
