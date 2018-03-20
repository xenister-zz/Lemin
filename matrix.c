/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:21:45 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/20 03:17:44 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_matrix(t_base *info)
{
	int		size;

	size = 0;
	IMSZ = info->index;
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
	{
		if (!(ILT = ft_memalloc(IMSZ * (sizeof(int)), -1)))
			return (0);
		ILT[0] = 0;
	}
	return (1);
}

int		set_matrix(t_base *info, int a, int b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
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

int		tube_cleaner(t_base *info, int	i, int j)
{
	int		c;
	
	info->a = 0;
	while (++i < (IMSZ - 1))
	{
		j = 0;
		c = 0;
		while (j < IMSZ)
		{
			if (IMX[i][j] == 1)
			{
				c++;
				info->a = j;
			}
			if (j++ == (IMSZ - 1) && c == 1 &&
				((info->a != 0) || (info->a != (IMSZ - 1))))
			{
				IMX[i][info->a] = 0;
				IMX[info->a][i] = 0;
			}
		}
	}
	return (1);
}

int		save_room(t_base *info, int room)
{
	int		c;

	c = 0;
	if (IPAPA[1][room] == 0 && IPAPA[0][room] == -1)
	{
		IPAPA[0][room] = info->a;
		return (1);
	}
	if (IPAPA[1][room] == 1 && IPAPA[0][room] > info->a)
	{
		IPAPA[0][room] = info->a;
		return (1);
	}
	if (IPAPA[0][room] < info->a)
	{
		return (0);
	}
	return (0);
}

int		path_finder(t_base *info, int i, int j)
{
	IBOO = 0;
	info->a = 0;
	while (i < IMSZ)
	{
		ISJ = 0;
		if (i == 0 || !save_room(info, i))
		{
			info->a++;
			i = path_finder_sup(info, i, j);
		}
		else
		{
			info->a--;
			i = ILT[i];
		}
		if (info->a > IMSZ)
			return (1);
	}
	return (0);
}

int		path_finder_sup(t_base *info, int i, int j)
{
	while (j < IMSZ)
	{
		if (IMX[i][j] == 1 && save_room(info, j))
			ILT[j] = i;
		if (j == (IMSZ - 1))
		{
			IPAPA[1][i] = 1;
			return (get_short_tube(info));
		}
		j++;
	}
	return (0);
}

int		get_short_tube(t_base *info)
{
	int		i;
	int		temp;
	int		dist;

	i = 0;
	temp = 0;
	dist = 2147483647;
	while (i < IMSZ)
	{
		if (IPAPA[0][i] > 0 && IPAPA[1][i] == 0 && IPAPA[0][i] < dist)
		{
			dist = IPAPA[0][i];
			temp = i;
		}
		i++;
	}
	return (temp);
}
