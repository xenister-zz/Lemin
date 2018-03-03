/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:21:45 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/03 18:09:56 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_matrix(t_base *info)
{
	int		size;

	size = 0;
	IMSZ = info->index;
	ft_printf("*******IN CREATE MATRIX*******\n");
	if ((!IMX))
		if (!(IMX = ft_inttable(IMX, IMSZ, IMSZ)))
			return (0);
	if (!IPAPA)
		if (!(IPAPA = ft_inttable(IPAPA, IMSZ, 2)))
			return (0);
	IPAPA[0][0] = 0;
	while (size++ < IMSZ)
		IPAPA[0][size] = -1;
	if (!ILT)
		if (!(ILT = ft_memalloc(IMSZ * (sizeof(int)), 0)))
			return (0);
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

int		path_finder(t_base *info, int i, int j)
{
	int		end;
	int		distance;

	end = 0;
	distance = 0;
	ft_printf("ILT ++++++++\n");
	while (i < IMSZ)
		ft_printf("|%d", ILT[i++]);
	ft_printf("\n");
	ft_printf("ILT ++++++++\n");
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < IMSZ)
		{
			ft_printf("|");
			ft_printf(RED"%d"C_DEFAULT, IPAPA[i][j++]);
		}
		ft_printf("\n");
		i++;
	}
	// i = 0;
	// while (!end)
	// {
	// 	if ((i == (IMSZ - 1) && j == (IMSZ - 1)) && !end)
	// 		return (0);
	// 	j = 0;
	// 	while (j < IMSZ)
	// 	{
			
	// 	}
	// 	i++;
	// }

	return (1);
}

/*

int		matrice_cleaner(t_base *info, int i, int j)
{
	int		clean;

	clean = 1;
	while (((i != (IMSZ - 1)) && (j != (IMSZ - 1))) && clean == 1)
	{
		if (IMX[j][i] > 0)
		{
			j = 0;
			while ()
		}
		i++;
	}
	return (0);
}
*/
/*
int		rec_papa(t_base *info, int fils, int clear)
{
	int		i;

	i = 0;
	if (IPAPA && (clear == 0) && (fils > 0))
	{
		while (i < info->a)
		{
			if (IPAPA[i] == -1 && (IPAPA[i] = fils))   //Condition a check
				break ;
			i++;
		}
	}
	i = 0;
	if (IPAPA && clear == 1)
		while (i < info->a)
		{
			IPAPA[i] = -1;
			i++;
		}
	return (1);
}

int		path_finder(t_base *info, int	i, int j)
{
	int		distance;
	int		end;

	distance = 0;
	end = 0;
	while (!end)
	{
		if (IMX[i][j] > 0 && (distance = (distance + 1)))
		{
			rec_papa(info, i, 0);
			if (IMX[i][j] > 0 && j == info->index)
					end = 1;
			j = 0;
			while (!end && j < IMSZ)
			{
				if (IMX[i][j] > 0 && (distance = (distance + 1)) && 
				rec_papa(info, j, 0))
					break ;
				if (IMX[i][j] > 0 && j == info->index)
					end = 1;
				j++;
			}
			if (!end && j == IMSZ && i == (IMSZ - 1))
					return (0);
		}
		i++;
	}
	return (distance);
}*/