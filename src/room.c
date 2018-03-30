/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:19:46 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/30 17:52:37 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		list_room(t_base *info, int index, char *name, char *line)
{
	t_house		*thouse;

	if ((index == 0 && info->bool_start == 1) ||
		(info->nbr_of_room > 1 && (!check_room_doublon(info, name))))
	{
		free(line);
		free(name);
		return (0);
	}
	if (!(thouse = ft_memalloc(sizeof(*thouse), 0)))
		return (0);
	thouse->index = index;
	thouse->name = name;
	if (index == 0)
		thouse->ant = info->fourmi;
	else
		thouse->ant = 0;
	ft_lstadd(&info->list_house, ft_lstnew(thouse, sizeof(*thouse)));
	free(thouse);
	info->nbr_of_room++;
	if (index == 0 && info->bool_start == 0)
		info->bool_start = 1;
	return (1);
}

int		check_room_doublon(t_base *info, char *name)
{
	t_list		*tempo;

	tempo = ILH;
	while (ILC->name || ILN != NULL)
	{
		if (ft_strcmp(ILC->name, name) == 0 && (ILH = tempo))
			return (0);
		if (ILN != NULL)
			ILH = ILN;
		else
			break ;
	}
	ILH = tempo;
	return (1);
}

int		check_coord(t_base *info, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (info->nbr_of_tube > 0)
		return (0);
	while (++i != 3)
	{
		if (!(tmp = ft_str_nword(line, i, ' ')))
			return (0);
		if (ft_isalldigit(tmp) == 0)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);
}

int		check_room(t_base *info, char *line)
{
	char	*tmp;

	if (!check_coord(info, line))
	{
		if (IBOO != 2)
			free(line);
		return (0);
	}
	if (!(tmp = ft_str_nword(line, 0, ' ')))
		return (0);
	if (tmp[0] == 'L' || tmp[0] == '#')
	{
		free(tmp);
		if (IBOO != 2)
			free(line);
		return (0);
	}
	else if (IBOO == 1 && (!list_room(info, 0, tmp, line)))
		return (0);
	else if (IBOO != 1 && !(list_room(info, info->index, tmp, line)))
		return (0);
	info->index++;
	return (1);
}

int		get_room(t_base *info, char *line)
{
	if (line[0] == '\0')
	{
		free(line);
		return (0);
	}
	if (IBOO == 4 && (!(IBOO = 0)))
		return (1);
	if (ft_strchr(line, '-'))
	{
		if (!get_tube(info, line))
		{
			free(line);
			return (0);
		}
		return (1);
	}
	if (line[0] == ' ' || ft_count_char(line, ' ') != 2)
	{
		free(line);
		return (0);
	}
	else if (!check_room(info, line))
		return (0);
	return (1);
}
