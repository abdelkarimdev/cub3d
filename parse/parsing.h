/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:06:03 by aben-el-          #+#    #+#             */
/*   Updated: 2026/01/04 05:40:46 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

/*************************COLOR**************************/
int		covert_to_rgb(int type, t_data *map, char **value);
int		check_color_validity(int type, t_data *map, char *color);
int		pars_color(t_data *map, int type, char *textures);
/*************************COLOR**************************/

/*************************TEXTURES**************************/
int		get_type(char *file_str, int *color_flag);
char	*get_line(size_t *offset, char *file_str);
int		pars_texture(t_data *map, int type, char *textures);
int		pars_args(t_data *map, char *file_str, size_t *offset);
int		main_pars(int color_flag, char *line, int type, t_data *map);
char	*get_path(char *line, int skip);
/*************************TEXTURES**************************/

/*************************MAP**************************/
int		pars_map(t_data *map, char *file_str, size_t offset);
int		valid_ement(char *file_str);
int		check_map(char **map);
int		check_holes(char **map);
int		is_space(char **map, int i, int j);
int		is_walkable(char *s);
/*************************MAP**************************/

/*************************UTILS**************************/
void	skip_newline(size_t *offset, char *file_str);
size_t	into_newline(size_t offset, char *str);
void	init_t_map(t_data *map);
int		skip_space(char *line, int skip);
char	*get_name(char **path);
int		arr_size(char **arr);
int		get_comma_len(char *arr);
int		get_color_value(const char *nptr);
/*************************UTILS**************************/

#endif
