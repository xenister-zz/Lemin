/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:50:58 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/30 17:27:52 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

void	init_struct(t_base *info)
{
	IBOO = 0;
	IANT = -1;
	ITB = NULL;
	IMX = NULL;
	IBE = NULL;
	IRM = NULL;
	info->a = 0;
	info->papa = NULL;
	info->last = NULL;
	info->bool_start = 0;
	info->nbr_of_tube = 0;
	info->nbr_of_room = 0;
	info->end_up = 0;
	info->index = 1;
	info->end = NULL;
}

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
	while (size++ < (IMSZ - 1))
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

void	free_list(t_base *info)
{
	t_list	*tempo;

	while ((ILC && ILC->name) || ILN != NULL)
	{
		if (ILC && ILC->name)
			free(ILC->name);
		if (ILC)
			free(ILH->content);
		tempo = ILH;
		if (ILN != NULL)
		{
			ILH = ILN;
			free(tempo);
		}
		else
			break ;
	}
	free(tempo);
}

void	free_lemin(t_base *info, int i)
{
	if (IBE)
		free(IBE);
	if (ITB)
		free(ITB);
	if (ILT && info->a == 0)
		free(ILT);
	if (info->end_up == 1)
		free(info->end);
	if (IMX)
	{
		while (i < IMSZ)
			free(IMX[i++]);
		free(IMX);
	}
	i = 0;
	if (IPAPA)
	{
		while (i < 2)
			free(IPAPA[i++]);
		free(IPAPA);
	}
	if (ILH)
		free_list(info);
	free(info);
	return ;
}
