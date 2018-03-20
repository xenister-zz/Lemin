/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:25:20 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/20 02:19:00 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     get_path(t_base *info)
{
	int		i;
	int		c;
	char	**room;

	room = NULL;
	i = IMSZ - 1;
	c = 0;
	if (ILT[i] == -1)
		return (0);
	//ft_printf(GREEN"****  EXIT PATH  ****\n"C_DEFAULT);
	ft_memset(IPAPA[0], -1, (sizeof(int) * IMSZ));
	//ft_print_int_tab(IPAPA, 2, IMSZ, "");
	//ft_print_int_tab(&ILT, 1, IMSZ, "");
	IPAPA[0][0] = IMSZ - 1;
	while (i != 0)
	{
		if (++c < IMSZ && IPAPA[0][c] == -1 && ILT[i] != 0)
			IPAPA[0][c] = ILT[i];
		i = ILT[i];
	}
	i = IMSZ;
	//ft_print_int_tab(IPAPA, 2, IMSZ, "*");
	while (--i >= 0)
	{
		if (IPAPA[0][i] != -1)
		{
			if (!get_name_room(info, IPAPA[0][i]))
				return (0);
			room  = ft_addchartable(room, info->end, c);
		}
	}
	i = -1;
	//while (room[++i])
		//ft_printf("ROOM + + + |%s|\n", room[i]);
	//ft_printf("C +++++++ ======= %d\n", c);
	if(!print_path(info, room, c))
		return (0);
	// ft_printf(GREEN"****  ** AFTER **  ****\n"C_DEFAULT);
	// ft_print_int_tab(IPAPA, 2, IMSZ, "");
	// ft_printf(RED"-------> IZI LEMIN <-------\n"C_DEFAULT);
	return (1);
}

int		get_name_room(t_base *info, int index)
{
	t_list	*tempo;

	tempo = ILH;
	//ft_printf("--- GET ROOM NAME ---\n");
	while (ILC->name || ILN != NULL)
	{
		if (ILC->index == index)
		{
			//ft_printf("+++++++++++++++++++++++  ILC = %d | index = %d\n", ILC->index, index);
			info->end = ft_strdup(ILC->name, 0);
			ILH = tempo;
			return (1);
		}
		if (ILN != NULL)
			ILH = ILN;
		else
			break ;
	}
	ILH = tempo;
	return (0);
}

int		print_path(t_base *info, char **room, int c)
{
	int		i;

	c = c + 1;
	IBOO = 0;
	IPAPA[0][0] = IANT;
	//ft_printf("FOURMI === |%d|\n", IANT);
	free(ILT);
	ILT = ft_memalloc(sizeof(int) * c, 0);
	ILT[0] = IANT;
	//ft_print_int_tab(&ILT, 1, c, "");
	while (IANT != ILT[c - 1])
	{
		move_ant(info, c);
		i = c - 1;
		//ft_print_int_tab(&ILT, 1, c, "|");
		while (i > 0)
		{
			if (ILT[i] != 0)
				ft_printf("L%d-%s ", ILT[i], room[i - 1]);
			i--;
		}
		ft_printf("\n");
		//usleep(50000);
	}
	return (1);
}

int		move_ant(t_base *info, int c)
{
	int		i;

	i = 1;
	//ft_print_int_tab(&ILT, 1, c, "");
	while (i < c && ILT[0] > 0)
	{
		if (ILT[i - 1] > 1)
			ILT[i]++;
		i++;
		//usleep(50000);
	}
	i = c - 1;
	while (ILT[0] == 0 && i > 0)
	{
		ILT[i] = ILT[i - 1];
		i--;
		//ft_printf("ILT i = |%d|\n", ILT[i]);
		// if (ILT[i] != 0 && i > 1 && (ILT[i - 1]))
		// 	ILT[i] = ILT[i - 1];
		// i--;
		// if (ILT[i] == 0 && (ILT[i + 1]))
		// 	ILT[i + 1] = 0;
	}
	if (ILT[0] == 1)
		ILT[1]++;
	if (ILT[0] != 0)
		ILT[0]--;
	
	//ft_print_int_tab(&ILT, 1, c, "");
	return (1);
}

// int		move_ant(t_base *info, int c)
// {
// 	int		i;

// 	i = 1;
// 	ft_print_int_tab(&ILT, 1, c, "");
// 	while (i < c && ILT[c - 1] != IANT)
// 	{
// 		if (i < (c - 1) && ILT[i] == IANT)
// 			ILT[i] = 0;
// 		ft_printf("--%d--\n", i);
// 		if ((ILT[i - 1] > 1 || (i == 1 && ILT[i - 1] == 1)))
// 		{
// 			ft_printf("lalalalala");
// 			(ILT[i])++;
// 			if (i == 1)
// 				ILT[0]--;
// 		}
// 		i++;
// 		usleep(50000);
// 	}
// 	ft_print_int_tab(&ILT, 1, c, "");
// 	return (1);
// }