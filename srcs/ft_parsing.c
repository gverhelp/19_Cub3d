/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:29:35 by gverhelp          #+#    #+#             */
/*   Updated: 2020/09/09 18:30:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int     ft_r_size(t_list *list, char *line)
{
    char	*tmp;

	tmp = NULL;
    if (list->size[0] == '\0')
	{
		tmp = list->size;
		list->size = ft_strjoin(list->size, line);
		free(tmp);
		list->aParsing++;
		return (0);
	}
	else
		return (-1);
}

int     ft_text_NO(t_list *list, char *line)
{
    char	*tmp;

	tmp = NULL;
    if (list->textNO[0] == '\0')
	{
		tmp = list->textNO;
		list->textNO = ft_strjoin(list->textNO, line);
		free(tmp);
		list->aParsing++;
		return (0);
	}
	else
		return (-1);
}

int		ft_whatstheconf(t_list *list, char *line)
{
	if (line[0] == 'R')
		return (ft_r_size(list, line));
	if (line[0] == 'N')
		return (ft_text_NO(list, line));
	if (line[0] == 'W')
		return (ft_text_WE(list, line));
	if (line[0] == 'E')
		return (ft_text_EA(list, line));
	if (line[0] == 'F')
		return (ft_text_F(list, line));
	if (line[0] == 'C')
		return (ft_text_C(list, line));
	if (line[0] == 'S')
	{
		if (line[1] == 'O')
			return (ft_text_SO(list, line));
		if (line[1] == ' ')
			return (ft_text_Sprite(list, line));
	}
	if (ft_isspace(line[0]) == 0 && list->aParsing < 8)
		return (-1);
	return (0);
}

int		ft_whatsinmap(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == '\0' && list->aParsing > 8)
	{
		write(1, "Error\nError in map 3\n", 21);
		return (-1);
	}
	if (line[0] != '\0' && list->aParsing == 8)
	{
		tmp = list->tmpmap;
		list->tmpmap = ft_strjoin(tmp, line);
		free(tmp);
		tmp = list->tmpmap;
		list->tmpmap = ft_strjoin(tmp, "\n");
		free(tmp);
		list->bParsing++;
		return (1);
	}
	return (1);	
}

int		ft_parsing(char *file, t_list *list)
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
		return(-1);
	return (0);
}