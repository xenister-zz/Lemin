/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:21:45 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/07 21:52:00 by susivagn         ###   ########.fr       */
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
	while (size < IMSZ)
		IPAPA[0][size++] = -1;
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

int		save_room(t_base *info, int room, int rm)
{
	int		c;

	c = 0;
	//info->a
	ft_printf("**** IN SAVE ROOM ****\n");
	if (IPAPA && rm == 0)
	{
		if (IPAPA[1][room] == 0)
			IPAPA[1][room] = 1;
		while (c < IMSZ)
		{
			if (IPAPA[0][c] == room)
				return (0);
			if (IPAPA[0][c] == -1)
			{
				IPAPA[0][c] = room;
				return (1);
			}
			c++;
		}
	}
	return (0);
}

int		tube_cleaner(t_base *info, int	i, int j)
{
	int		c;

	c = 0;
	while (++i < (IMSZ - 1))
	{
		j = 0;
		while (++j < (IMSZ - 1))
		{
			if (IMX[i][j] = 1)
				c++;
		}
	}
}

int		rm_room(t_base *info, int room)
{
	int		c;

	if (room > 0 && (c = IMSZ))
		while (--c > -1)
		{
			if (IPAPA[0][c] == room)
			{
				IPAPA[0][c] = -1;
				return (1);
			}
		}
	return (0);
}

int		path_finder(t_base *info, int i, int j)
{
	IBOO = 0;
	ft_printf("**** IN PATH FINDER ****\n");
	while (!IBOO && i < IMSZ)
	{
		if (IMX[i][j] == 1 && save_room(info, i, 0))
			j = path_finder_sup(info, i, j);
		i++;
	}
	return (0);
}

int		path_finder_sup(t_base *info, int i, int j)
{
	ft_printf("**** IN PATH FINDER SUPPPPP ****\n");
	while (!IBOO && j < IMSZ)
	{
		if (IMX[i][j] == 1 && save_room(info, j, 0))
			return (j);
		j++;
	}
	return (0);
}

/*
int		path_finder(t_base *info, int	i, int j)
{
	IBOO = 0;
	ft_printf("**** IN PATH FINDER ****\n");
	while (!IBOO && i < IMSZ)
	{
		if (ISI == i)
			i++;
		if (IMX[i][j] > 0 && save_room(info, i, 0))
		{
			ISJ = j;
			j = 0;
			while (!IBOO && j < IMSZ)
			{
				if (ISJ == j)
					j++;
				if ((j == (IMSZ - 1)) && IMX[i][j] == 0)
				{

				}
				if (IMX[i][j] > 0 && save_room(info, j, 0))
				{
					ISI = i;
					i = -1;
					break ;
				}
				j++;
			}
		}
		if ((i == (IMSZ - 1)) && IMX[i][j] == 0)
		{
			i = ISI - 1;
			j++;
		}
		i++;
	}
	return (0);
}

int		path_finder(t_base *info, int i, int j)
{
	int		patate = 0;
	ISI = -1;
	ISJ = -1;
	ft_printf("----------IN PATH FINDER--- %d ---- %d -------\n", ISI, ISJ);
	while (!IBOO)
	{
		j = 0;
		while (j < IMSZ)
		{
			ft_printf("*** %d **** %d *** | *** %d *** %d *** |%d| **\n", i, j, ISI, ISJ, IMX[i][j]);
			if (IMX[i][j] > 0  && (ISI != i && ISJ != j) &&
			save_tube(info, IMX[i][j]))
			{
				ft_printf("=========\n");
				patate = 0;
				while (patate < IMSZ)
					ft_printf("|%d|\n", ILT[patate++]);
				ISI = i;
				ISJ = j;
				i++;
				break ;

			}
			if ((j == (IMSZ - 1)) && IMX[i][j] == 0)
			{
				ft_printf("++++++++++\n");
				IMX[ISI][ISJ] = 0;
				IMX[ISJ][ISI] = 0;
				i++;
				break ;
			}
			if (j == (IMSZ - 1) && IMX[i][j] > 0 && (IBOO = 1))
				break ;
			j++;
		}
	}
	return (1);
}

int		get_tube_matrice(t_base *info, int	room, int  *a, int *b)
{
	int		i;
	int		j;

	i = 0;
	if (IMX && room)
	{
		while (i < IMSZ)
		{
			j = 0;
			while (j < IMSZ)
			{
				if (IMX[i][j] == room)
				{
					*a = i;
					*b = j;
					return (1);
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}

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