/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:25:20 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/26 14:46:19 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     get_path(t_base *info)
{
	int		i;
	int		c;

	i = IMSZ - 1;
	c = 0;
	if (ILT[i] == -1)
		return (0);
	ft_memset(IPAPA[0], -1, (sizeof(int) * IMSZ));
	IPAPA[0][0] = IMSZ - 1;
	while (i != 0)
	{
		if (++c < IMSZ && IPAPA[0][c] == -1 && ILT[i] != 0)
			IPAPA[0][c] = ILT[i];
		i = ILT[i];
	}
	i = IMSZ;
	while (--i >= 0)
	{
		if (IPAPA[0][i] != -1)
		{
			if (!get_name_room(info, IPAPA[0][i]))
				return (0);
			IRM = ft_addchartable(IRM, info->end, c);
		}
	}
	i = -1;
	info->a = c;
	if(!print_path(info, c))
		return (0);
	return (1);
}

int		get_name_room(t_base *info, int index)
{
	t_list	*tempo;

	tempo = ILH;
	while (ILC->name || ILN != NULL)
	{
		if (ILC->index == index)
		{
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

int		print_path(t_base *info, int c)
{
	int		i;

	c = c + 1;
	IBOO = 0;
	IPAPA[0][0] = IANT;
	free(ILT);
	ILT = ft_memalloc(sizeof(int) * c, 0);
	ILT[0] = IANT;
	ft_printf("%s\n", IBE);
	while (IANT != ILT[c - 1])
	{
		move_ant(info, c);
		i = c - 1;
		while (i > 0)
		{
			if (ILT[i] != 0)
				ft_printf("L%d-%s ", ILT[i], IRM[i - 1]);
			i--;
		}
		ft_printf("\n");
	}
	i = 0;
	while (IRM[i])
		free(IRM[i++]);
	free(IRM);
	free(ILT);
	info->a = 1;
	return (1);
}

int		move_ant(t_base *info, int c)
{
	int		i;

	i = 1;
	while (i < c && ILT[0] > 0)
	{
		if (ILT[i - 1] > 1)
			ILT[i]++;
		i++;
	}
	i = c - 1;
	while (ILT[0] == 0 && i > 0)
	{
		ILT[i] = ILT[i - 1];
		i--;
	}
	if (ILT[0] == 1)
		ILT[1]++;
	if (ILT[0] != 0)
		ILT[0]--;
	return (1);
}
