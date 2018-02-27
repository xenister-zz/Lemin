/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:21:45 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/27 20:36:25 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_matrix(t_base *info)
{
	int		size;

	ft_printf("*******IN CREATE MATRIX*******\n");
	if ((!IMX) && (IMSZ = info->index))
		IMX = ft_inttable(IMX, IMSZ, IMSZ);
	return (1);
}

int		set_matrix(t_base *info, int a, int b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_printf("--------IN SET MATRIX---------\n");
	ft_printf("---------|%d|--|%d|-----------\n", a, b);
	while (i < IMSZ)
	{
		j = 0;
		while (j < IMSZ)
		{
			if (i == a && j == b)
			{
				IMX[i][j] = 1;
				IMX[j][i] = 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
/*
int		path_finder(t_base *info, int a, int b)
{
	int		nbrtube;
	int		avoidtube;

	nbrtube = 0;
	while ()
	return (0);	
}*/