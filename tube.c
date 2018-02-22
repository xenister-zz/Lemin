/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:20:58 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/22 19:21:18 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_tube(t_base *info, char	*line)
{
	ft_printf("--- IN TUBE ---\n");
	if (info->end && !(check_room(info, info->end)))
		return (0);
	else
		info->end = NULL;
	return (1);
}

int		check_tube(t_base *info, char *line)
{
	ft_printf("--- IN CHECK TUBE ---\n");
	
	return(1);
}