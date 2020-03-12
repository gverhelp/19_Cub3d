/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:03:44 by gverhelp          #+#    #+#             */
/*   Updated: 2020/03/05 14:09:59 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_free(char **rest, int nb)
{
	if (*rest == NULL)
	{
		free(*rest);
		*rest = NULL;
	}
	return (nb);
}

char		*ft_strndup(const char *s)
{
	int		a;
	int		len;
	char	*str;

	len = 0;
	a = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	str = malloc((len + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	while (s[a] != '\n' && s[a] != '\0')
	{
		str[a] = s[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

int			ft_read(int fd, char **line, char *rest)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	ret = 1;
	if (rest != NULL)
		if ((*line = ft_strdup_gnl(rest)) == NULL)
			return (-1);
	if (rest == NULL)
		if ((*line = ft_strdup_gnl("")) == NULL)
			return (-1);
	while ((ft_strchr_gnl(*line, '\n') == NULL) &&
			(ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		tmp = *line;
		buf[ret] = '\0';
		if ((*line = ft_strjoin_gnl(*line, buf)) == NULL)
			return (-1);
		free(tmp);
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	*rest[FOPEN_MAX];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if ((ret = ft_read(fd, line, rest[fd])) == -1)
		return (ft_free(&rest[fd], -1));
	if (rest[fd] != NULL)
		free(rest[fd]);
	if ((rest[fd] = ft_strdup_gnl(ft_strchr_gnl(*line, '\n'))) == NULL)
		return (ft_free(&rest[fd], -1));
	if (ft_strchr_gnl(*line, '\n') == NULL)
		return (ft_free(&rest[fd], 0));
	tmp = *line;
	if ((*line = ft_strndup(*line)) == NULL)
		return (ft_free(&rest[fd], -1));
	free(tmp);
	return (1);
}
