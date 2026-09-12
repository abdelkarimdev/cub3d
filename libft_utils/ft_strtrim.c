/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:32:15 by aben-el-          #+#    #+#             */
/*   Updated: 2026/01/03 15:20:59 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_set_valid(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (s1[i] && is_set_valid(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (s1[i] && is_set_valid(s1[j], set))
		j--;
	ptr = malloc(sizeof(char) * (j - i + 1) + 1);
	if (!ptr)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		ptr[k] = s1[i];
		k++;
		i++;
	}
	ptr[k] = '\0';
	return (ptr);
}
/*int main ()
{
	char c[30] = "%#%%#%abdelkarim%#%%#%";
	char se[20] = "%#%";
	printf("%s\n", ft_strtrim(c,se));
	printf("test 2:\n");
	char cx[30] = "%#%%#%abdel%#%karim%#%%#%";
	char sev[20] = "%#%";
	printf("%s\n", ft_strtrim(cx, sev));
}*/
