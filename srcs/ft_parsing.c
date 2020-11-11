/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:35:57 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:40:13 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_r_size(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (list->size[0] == '\0')
	{
		tmp = list->size;
		list->size = ft_strjoin(list->size, line);
		free(tmp);
		list->aparsing++;
		return (0);
	}
	else
		return (-1);
}

int	ft_text_no(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (list->textno[0] == '\0')
	{
		tmp = list->textno;
		list->textno = ft_strjoin(list->textno, line);
		free(tmp);
		list->aparsing++;
		return (0);
	}
	else
		return (-1);
}

int	ft_whatstheconf(t_list *list, char *line)
{
	if (line[0] == 'R')
		return (ft_r_size(list, line));
	if (line[0] == 'N')
		return (ft_text_no(list, line));
	if (line[0] == 'W')
		return (ft_text_we(list, line));
	if (line[0] == 'E')
		return (ft_text_ea(list, line));
	if (line[0] == 'F')
		return (ft_text_f(list, line));
	if (line[0] == 'C')
		return (ft_text_c(list, line));
	if (line[0] == 'S')
	{
		if (line[1] == 'O')
			return (ft_text_so(list, line));
		if (line[1] == ' ')
			return (ft_text_sprite(list, line));
	}
	if (list->aparsing < 8)
		return (-1);
	return (0);
}

int	ft_whatsinmap(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == '\0' && list->aparsing > 8)
	{
		write(1, "Error\nError in map 3\n", 21);
		return (-1);
	}
	if (line[0] != '\0' && list->aparsing == 8)
	{
		tmp = list->tmpmap;
		list->tmpmap = ft_strjoin(tmp, line);
		free(tmp);
		tmp = list->tmpmap;
		list->tmpmap = ft_strjoin(tmp, "\n");
		free(tmp);
		list->bparsing++;
		return (1);
	}
	return (1);
}

int	ft_parsing(char *file, t_list *list)
{
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open(file, O_RDONLY)) <= 0)
	{
		write(1, "Error\nUnopened File\n", 20);
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		if (ft_whatsinmap(list, line) == -1)
			return (-1);
		if (line[0] != '\0')
			if (ft_whatstheconf(list, line) == -1)
				return (-1);
		free(line);
	}
	close(fd);
	if (ft_check(list) == -1)
		return (-1);
	return (0);
}
