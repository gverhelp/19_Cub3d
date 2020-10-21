#include "../include/cub3d.h"

int     ft_text_WE(t_list *list, char *line)
{
    char	*tmp;

	tmp = NULL;
    if (list->textWE[0] == '\0')
	{
		tmp = list->textWE;
		list->textWE = ft_strjoin(list->textWE, line);
		free(tmp);
		list->aParsing++;
		return (0);
	}
	else
		return (-1);
}

int     ft_text_EA(t_list *list, char *line)
{
    char	*tmp;

	tmp = NULL;
    if (list->textEA[0] == '\0')
	{
		tmp = list->textEA;
		list->textEA = ft_strjoin(list->textEA, line);
		free(tmp);
		list->aParsing++;
		return (0);
	}
	else
		return (-1);
}

int     ft_text_F(t_list *list, char *line)
{
    char	*tmp;

	tmp = NULL;
    if (list->textF[0] == '\0')
	{
		tmp = list->textF;
		list->textF = ft_strjoin(list->textF, line);
		free(tmp);
		list->aParsing++;
		return (0);
	}
	else
		return (-1);
}

int     ft_text_C(t_list *list, char *line)
{
    char	*tmp;

	tmp = NULL;
    if (list->textC[0] == '\0')
	{
		tmp = list->textC;
		list->textC = ft_strjoin(list->textC, line);
		free(tmp);
		list->aParsing++;
		return (0);
	}
	else
		return (-1);
}

int     ft_text_SO(t_list *list, char *line)
{
    char	*tmp;

	tmp = NULL;
    if (list->textSO[0] == '\0')
	{
		tmp = list->textSO;
		list->textSO = ft_strjoin(list->textSO, line);	
    	free(tmp);
		list->aParsing++;
		return (0);
	}
	else
		return (-1);
}