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

int		ft_parsing(char *file, t_list *list)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
			ft_whatstheconf(list, line);
	}
	close(fd);
	return (0);
}
