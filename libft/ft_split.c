/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:35:38 by gverhelp          #+#    #+#             */
/*   Updated: 2019/11/12 17:23:14 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_malloc_s(char const *s, char c)
{
	int	a;
	int	counter;

	a = 0;
	counter = 0;
	while (s[a] != '\0')
	{
		while (s[a] != '\0' && s[a] == c)
			a++;
		if (s[a] != '\0' && s[a] != c)
		{
			counter++;
			while (s[a] != '\0' && s[a] != c)
				a++;
		}
	}
	return (counter);
}

static void		ft_free(char **tab)
{
	int	a;

	a = 0;
	while (tab[a] != NULL)
	{
		free(tab[a]);
		a++;
	}
	free(tab);
}

static char		*ft_write(const char *s, char c, char **tab)
{
	size_t	a;
	char	*dest;

	a = 0;
	while (s[a] != '\0' && s[a] != c)
		a++;
	dest = ft_substr(s, 0, a);
	if (dest == NULL)
		ft_free(tab);
	return (dest);
}

char			**ft_split(char const *s, char c)
{
	int		a;
	int		b;
	int		counter;
	char	**tab;

	a = 0;
	b = 0;
	counter = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = malloc((ft_malloc_s(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (s[a] != '\0')
	{
		while (s[a] == c)
			a++;
		if (s[a] != '\0' && s[a] != c)
		{
			tab[b++] = ft_write(&s[a], c, tab);
			while (s[a] != c && s[a] != '\0')
				a++;
		}
	}
	tab[b] = NULL;
	return (tab);
}
