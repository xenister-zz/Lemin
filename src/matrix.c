/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:21:45 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/28 16:19:11 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		tube_cleaner(t_base *info, int i, int j)
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
