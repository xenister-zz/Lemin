/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:21:45 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/16 21:38:30 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_matrix(t_base *info)
{
	int		size;

	size = 0;
	IMSZ = info->index;
	//ft_printf("*******IN CREATE MATRIX*******\n");
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
	//ft_printf("--------IN SET MATRIX---------\n");
	//ft_printf("---------|%d|--|%d|-----------\n", a, b);
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

// int		save_neighbour(t_base *info, int room, int neighboor)
// {
// 	if (ILT)
// 	{
// 		ILT[room] = neighboor;
// 	}
// 	return (0);
// }

int		save_room(t_base *info, int room)
{
	int		c;

	c = 0;
	//ft_printf("++++ IN SAVE ROOM  room == |%d|\n", room);
	if (IPAPA[1][room] == 0 && IPAPA[0][room] == -1)
	{
		//ft_printf("++++ SORTIE SAVE ROOM == -1 ++++\n");
		IPAPA[0][room] = info->a;
		return (1);
	}
	if (IPAPA[1][room] == 1 && IPAPA[0][room] > info->a)
	{
		//ft_printf("++++ ROOM VISITED WITH OVER DISTANCE ++++\n");
		IPAPA[0][room] = info->a;
		return (1);
	}
	if (IPAPA[0][room] < info->a)
	{
		//ft_printf("++++  ++++\n");
		return (0);
	}
	return (0);
}

int		path_finder(t_base *info, int i, int j)
{
	IBOO = 0;
	info->a = 0;
	//ft_printf("**** IN PATH FINDER ****\n");
	while (i < IMSZ)
	{
		ISJ = 0;
		//ft_printf("		I ==== %d  | A ====  %d	\n", i, info->a);
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
	// ft_printf("**** IN PATH FINDER SUPPPPP ****\n");
	// ft_printf("--------------IPAPA-------------\n");
	// ft_print_int_tab(IPAPA, 2, IMSZ, "");
	// ft_printf("---------------LAST-------------\n");
	// ft_print_int_tab(&ILT, 1, IMSZ, "");
	while (j < IMSZ)
	{
		// ft_printf("	  J ==== %d	\n", j);
		if (IMX[i][j] == 1 && save_room(info, j))
		{
			// ft_printf("--------------IPAPA-------------\n");
			// ft_print_int_tab(IPAPA, 2, IMSZ, "");
			// ft_printf("---------------LAST-------------\n");
			ILT[j] = i;
			//ft_print_int_tab(&ILT, 1, IMSZ, "");

		}
		if (j == (IMSZ - 1))
		{
			// ft_printf("-------- SORTIE FINDER SUP --|%d|--\n", ILT[i]);
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
	//ft_printf("---------IN GET SHORT TUBE--------\n");
	while (i < IMSZ)
	{
		if (IPAPA[0][i] > 0 && IPAPA[1][i] == 0 && IPAPA[0][i] < dist)
		{
			dist = IPAPA[0][i];
			temp = i;
		}
		i++;
	}
	//ft_printf("---------EXIT GST == |%d|---------\n", temp);
	return (temp);
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