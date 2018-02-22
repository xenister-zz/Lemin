/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:19:46 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/22 19:20:29 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		list_room(t_base *info, int index, char *name)
{
	t_house		*thouse;
	t_list		*tempo;
 

	if (!(thouse = ft_memalloc(sizeof(*thouse), 0)))
		return (0);
	thouse->index = index;
	thouse->name = name;
	ft_lstadd(&info->list_house, ft_lstnew(thouse, sizeof(*thouse)));
	free(thouse);
	tempo = info->list_house;
	ft_printf("--------------PRINTING LIST----------------\n");
	while (ILC->name || ILN != NULL)
	{
		ft_printf("Index = |%d| - Name = |%s|\n", ILC->index, ILC->name);
		if (ILN != NULL)
			ILH = ILN;
		else
			break ;
	}
	ILH = tempo;
	return (1);
}

int		check_room(t_base *info, char *line)
{
	char	*tmp;
	
	ft_printf("ENTRY CHECK ROOM\n");
	ft_printf("LINE  ==  %s|\n", line);
	tmp = ft_strsub(line, 0, ft_strclen(line, ' '));
	if (!tmp || tmp[0] == 'L' || tmp[0] == '#')
		return (0);
	else if (IBOO == 1)
		return (list_room(info, 0, line));
	else if (!(list_room(info, info->index, tmp)))
			return (0);
	info->index++;
	return(1);
}

int		get_room(t_base *info, char *line)
{
	ft_printf("--- IN ROOM ---%d-\n", IBOO);
	if (IBOO == 4)
	{
		IBOO = 0;
		return(1);
	}
	if (ft_strchr(line, '-'))
		return (get_tube(info, line));
	if (line[0] == ' ' || ft_count_char(line, ' ') != 2)
		return (0);
	else
		return (check_room(info, line));
	return (1);
}