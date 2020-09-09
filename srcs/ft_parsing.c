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

void	ft_whatstheconf3(t_list2 *list2, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'F' && list2->textF[0] == '\0')
	{
		tmp = list2->textF;
		list2->textF = ft_strjoin(list2->textF, line);
		free(tmp);
	}
	if (line[0] == 'C' && list2->textC[0] == '\0')
	{
		tmp = list2->textC;
		list2->textC = ft_strjoin(list2->textC, line);
		free(tmp);
	}
}

void	ft_whatstheconf2(t_list2 *list2, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'E' && list2->textE[0] == '\0')
	{
		tmp = list2->textE;
		list2->textE = ft_strjoin(list2->textE, line);
		free(tmp);
	}
	if (line[0] == 'W' && list2->textW[0] == '\0')
	{
		tmp = list2->textW;
		list2->textW = ft_strjoin(list2->textW, line);
		free(tmp);
	}
	if (line[0] == 'S' && list2->textSprite[0] == '\0')
	{
		tmp = list2->textSprite;
		list2->textSprite = ft_strjoin(list2->textSprite, line);
		free(tmp);
	}
	ft_whatstheconf3(list2, line);
}

void	ft_whatstheconf(t_list2 *list2, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'R' && list2->size[0] == '\0')
	{
		tmp = list2->size;
		list2->size = ft_strjoin(list2->size, line);
		free(tmp);
	}
	if (line[0] == 'N' && list2->textN[0] == '\0')
	{
		tmp = list2->textN;
		list2->textN = ft_strjoin(list2->textN, line);
		free(tmp);
	}
	if (line[0] == 'S' && list2->textS[0] == '\0')
	{
		tmp = list2->textS;
		list2->textS = ft_strjoin(list2->textS, line);
		free(tmp);
	}
	ft_whatstheconf2(list2, line);
}

int		ft_parsing(char *file)
{
	int		fd;
	char	*line;
	t_list2	list2;

	ft_init_list_parsing(&list2);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
			ft_whatstheconf(&list2, line);
	}
	return (0);
}
