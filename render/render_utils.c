/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:02:34 by aazounda          #+#    #+#             */
/*   Updated: 2026/01/05 10:31:15 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	clear_buffer(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < (WIN_WIDTH))
		{
			put_pixel_to_image(&data->scren_img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_pixel_from_image(t_img *img, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->hight)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		return ((int)(*(unsigned int *)dst));
	}
	return (0x00000000);
}
