/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:20:58 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/26 19:45:17 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_end_room(t_base *info)
{
	if (info->end && !(check_room(info, info->end)))
		return (0);
	else
		ft_strdel(&info->end);
	return (1);
}

int		get_tube(t_base *info, char	*line)
{
	char	*str1;
	char	*str2;

	ft_printf("--- IN TUBE ---\n");
	if (info->end && !get_end_room(info))
		return (0);
	if (!check_tube(info, ft_str_nword(line, 0, '-')))
		return (0);
	if (!check_tube(info, ft_str_nword(line, 1, '-')))
		return (0);
	return (1);
}

int		check_tube(t_base *info, char *tocheck)
{
	t_list	*tempo;

	tempo = ILH;
	ft_printf("--- IN CHECK TUBE ---\n");
	ft_printf("TUBE == %s|\n", tocheck);
	while ()
	return(1);
}