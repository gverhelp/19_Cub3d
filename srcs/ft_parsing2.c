/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:08 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:43:08 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_text_we(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (list->textwe[0] == '\0')
	{
		tmp = list->textwe;
		list->textwe = ft_strjoin(list->textwe, line);
		free(tmp);
		list->aparsing++;
		return (0);
	}
	else
		return (-1);
}

int	ft_text_ea(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (list->textea[0] == '\0')
	{
		tmp = list->textea;
		list->textea = ft_strjoin(list->textea, line);
		free(tmp);
		list->aparsing++;
		return (0);
	}
	else
		return (-1);
}

int	ft_text_f(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (list->textf[0] == '\0')
	{
		tmp = list->textf;
		list->textf = ft_strjoin(list->textf, line);
		free(tmp);
		list->aparsing++;
		return (0);
	}
	else
		return (-1);
}

int	ft_text_c(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (list->textc[0] == '\0')
	{
		tmp = list->textc;
		list->textc = ft_strjoin(list->textc, line);
		free(tmp);
		list->aparsing++;
		return (0);
	}
	else
		return (-1);
}

int	ft_text_so(t_list *list, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (list->textso[0] == '\0')
	{
		tmp = list->textso;
		list->textso = ft_strjoin(list->textso, line);
		free(tmp);
		list->aparsing++;
		return (0);
	}
	else
		return (-1);
}
