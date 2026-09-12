/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazounda <aazounda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:06:08 by aben-el-          #+#    #+#             */
/*   Updated: 2026/01/03 15:20:45 by aazounda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_get_str(const char *str, char c)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	i = 0;
	while (str[i] == c)
		i++;
	len = 0;
	while (str[len + i] != c && str[i + len] != '\0')
		len++;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		ptr[j] = str[i + j];
		j++;
	}
	ptr[len] = '\0';
	return (ptr);
}

static void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		p;

	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	p = 0;
	while (i < ft_count_words(s, c))
	{
		ptr[i] = ft_get_str(s + p, c);
		if (!ptr[i])
			ft_free(ptr);
		while (s[p] == c)
			p++;
		p += ft_strlen(ptr[i]);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
/*#include <stdio.h>
int	main(void)
{
	char *p = ".  abd  I am Mohamed vc          .";
	char **str;
	str = ft_split(p, ' ');

	// Test 1
	printf("%d    \n", (int)ft_strlen(p));
	printf("%d\n", ft_count_words(p, ' '));
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}*/
