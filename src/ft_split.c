/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:04:59 by yobenali          #+#    #+#             */
/*   Updated: 2021/11/21 20:10:13 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	ft_calcul(char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		while (*str != c && *str)
		{
			str++;
			if (*str == c || *str == '\0')
				i++;
		}
	}
	return (i);
}

static char	**ft_free(char **tab, int j)
{
	int	i;

	i = -1;
	if (j != 0)
		while (++i <= j)
			free(tab[i]);
	free(tab);
	return (NULL);
}

static char	**ft_wlen(char *str, char **tab, char c)
{
	int		wdlen;
	int		j;
	int		i;

	i = 0;
	j = -1;
	while (str[i])
	{
		wdlen = 0;
		while (str[i] != c && str[i])
		{
			wdlen++;
			i++;
			if (str[i] == c || str[i] == '\0')
			{
				tab[++j] = (char *)ft_calloc(wdlen + 1, sizeof(char));
				if (!tab[j])
					return (ft_free(tab, j));
				ft_strlcpy(tab[j], &str[i - wdlen], wdlen + 1);
			}
		}
		while (str[i] == c && str[i])
			i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;

	if (!s)
		return (NULL);
	len = ft_calcul((char *) s, c);
	tab = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_wlen((char *)s, tab, c);
	return (tab);
}
