/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:21:45 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/01 21:26:05 by susivagn         ###   ########.fr       */
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
				IMX[i][j] = info->a;
				IMX[j][i] = info->a;
				info->a++;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		rec_papa(t_base *info, int fils, int clear, int del)
{
	int		i;

	i = 0;
	if (IPAPA && (fils > 0))
	{
		while (i < info->a)
		{
			if (IPAPA[i] == 0 && (IPAPA[i] = fils))
				break ;
			i++;
		}
	}
	if (IPAPA && clear == 1)
		while (i < info->a)
		{
			IPAPA[i] = 0;
			i++;
		}
	if (IPAPA && del > 0)

	return (0);
}

int		path_cleaner(t_base *info, int	i, int j)
{
	int		distance;
	int		end;

	distance = 0;
	end = 0;
	while (i < IMSZ && !end)
	{
		if (IMX[i][j] > 0 && (distance = (distance + 1)))
		{
			j = 0;
			while (j < IMSZ)
			{
				if (IMX[i][j] > 0 && (distance = (distance + 1)))

				j++;
			}
		}
		i++;
	}
	return (0);
}