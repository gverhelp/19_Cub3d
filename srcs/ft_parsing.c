/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:29:35 by gverhelp          #+#    #+#             */
/*   Updated: 2020/09/08 19:09:01 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_whatsintext3(t_data2 *data2, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'F' && data2->textF[0] == '\0')
	{
		tmp = data2->textF;
		data2->textF = ft_strjoin(data2->textF, line);
		free(tmp);
	}
	if (line[0] == 'C' && data2->textC[0] == '\0')
	{
		tmp = data2->textC;
		data2->textC = ft_strjoin(data2->textC, line);
		free(tmp);
	}
}

void	ft_whatsintext2(t_data2 *data2, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'E' && data2->posE[0] == '\0')
	{
		tmp = data2->posE;
		data2->posE = ft_strjoin(data2->posE, line);
		free(tmp);
	}
	if (line[0] == 'W' && data2->posW[0] == '\0')
	{
		tmp = data2->posW;
		data2->posW = ft_strjoin(data2->posW, line);
		free(tmp);
	}
	if (line[0] == 'S' && data2->textS[0] == '\0')
	{
		tmp = data2->textS;
		data2->textS = ft_strjoin(data2->textS, line);
		free(tmp);
	}
	ft_whatsintext3(data2, line);
}

void	ft_whatsintext(t_data2 *data2, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == 'R' && data2->size[0] == '\0')
	{
		tmp = data2->size;
		data2->size = ft_strjoin(data2->size, line);
		free(tmp);
	}
	if (line[0] == 'N' && data2->posN[0] == '\0')
	{
		tmp = data2->posN;
		data2->posN = ft_strjoin(data2->posN, line);
		free(tmp);
	}
	if (line[0] == 'S' && data2->posS[0] == '\0')
	{
		tmp = data2->posS;
		data2->posS = ft_strjoin(data2->posS, line);
		free(tmp);
	}
	ft_whatsintext2(data2, line);
}

int		ft_parsing(char *file)
{
	int		fd;
	char	*line;
	t_data2	data2;

	ft_init_list_parsing(&data2);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
		{
			ft_whatsintext(&data2, line);
		}
	}
	return (0);
}
