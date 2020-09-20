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

void	ft_whatstheconf3(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'S' && list->textS[0] == '\0')	
	{
		if (line[1] == 'O' && list->textS[0] == '\0')
		{
			tmp = list->textS;
			list->textS = ft_strjoin(list->textS, line);
			free(tmp);
		}
		if (line[1] == ' ' && list->textSprite[0] == '\0')
		{
			tmp = list->textSprite;
			list->textSprite = ft_strjoin(list->textSprite, line);
			free(tmp);
		}
	}
	list->aParsing++;
}

void	ft_whatstheconf2(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'E' && list->textE[0] == '\0')
	{
		tmp = list->textE;
		list->textE = ft_strjoin(list->textE, line);
		free(tmp);
	}
	if (line[0] == 'F' && list->textF[0] == '\0')
	{
		tmp = list->textF;
		list->textF = ft_strjoin(list->textF, line);
		free(tmp);
	}
	if (line[0] == 'C' && list->textC[0] == '\0')
	{
		tmp = list->textC;
		list->textC = ft_strjoin(list->textC, line);
		free(tmp);
	}
	ft_whatstheconf3(list, line);
}

void	ft_whatstheconf(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'R' && list->size[0] == '\0')
	{
		tmp = list->size;
		list->size = ft_strjoin(list->size, line);
		free(tmp);
	}
	if (line[0] == 'N' && list->textN[0] == '\0')
	{
		tmp = list->textN;
		list->textN = ft_strjoin(list->textN, line);
		free(tmp);
	}
	if (line[0] == 'W' && list->textW[0] == '\0')
	{
		tmp = list->textW;
		list->textW = ft_strjoin(list->textW, line);
		free(tmp);
	}
	ft_whatstheconf2(list, line);
}

int		ft_whatsinmap(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == '\0' && list->aParsing > 8)
	{
		write(1, "Error in Map\n", 13);
		return (-1);
	}
	if (line[0] != '\0' && list->aParsing > 8)
	{
		tmp = list->tmpmap;
		list->tmpmap = ft_strjoin(tmp, line);
		free(tmp);
		tmp = list->tmpmap;
		list->tmpmap = ft_strjoin(tmp, "\n");
		free(tmp);
		return (1);
	}
	return (-1);	
}

int		ft_parsing(char *file, t_list *list)
{
	int		fd;
	char	*line;

	line = NULL;
	list->aParsing = 0;
	list->bParsing = 0;
	if ((fd = open(file, O_RDONLY)) <= 0)
	{
		write(1, "Error Unopened File", 19);
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
			ft_whatstheconf(list, line);
		if (ft_whatsinmap(list, line) == 1)
			list->bParsing++;
		free(line);
	}
	printf("%s", list->tmpmap);
//	if (ft_check(list, fd, line) == -1)
//		return(-1);
//je dois encore close(fd) qlq part
	return (0);
}
