/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:57:08 by fsalvett          #+#    #+#             */
/*   Updated: 2023/02/02 15:01:04 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_how_many_strings(char const *str, char ch)
{
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ch)
		{
			j++;
			while (str[i] != ch && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (j);
}

void	ft_fill_the_strings(const char*s, char **pointer, char c, int dim)
{
	int	i;
	int	y;
	int	j;

	i = 0;
	y = 0;
	j = 0;
	while (i < dim)
	{
		while (s[j] == c)
		{
			j++;
		}
		y = j;
		while (s[y] != c && s[y] != '\0')
		{
			y++;
		}
		pointer[i] = ft_substr(s, j, y - j);
		j = y;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**mega_pointer;
	int		dim;

	dim = ft_how_many_strings(s, c);
	if (!dim)
	{	
		mega_pointer = malloc(sizeof(char *));
		mega_pointer[0] = 0;
		return (mega_pointer);
	}
	mega_pointer = malloc((dim + 1) * sizeof(char *));
	if (!mega_pointer)
		return (NULL);
	mega_pointer[dim] = NULL;
	ft_fill_the_strings(s, mega_pointer, c, dim);
	return (mega_pointer);
}
