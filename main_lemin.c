/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:06:05 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/21 11:03:17 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_command(t_base *info, char *line)
{
	ft_printf("IN GET COMMAND\n");
	if (IBOO == 0 && ft_strstr(line, "#"))
	{
		if((ft_strcmp(line, "##start") == 0) && (IBOO = 1))
			return (1);
		else if ((ft_strcmp(line, "##end") == 0) && (IBOO = 2))
			return (1);
		else if ((ft_count_char(line, '#') == 1) &&
			(line[0] == '#') && (IBOO = 3))
			return (1);
	}
	else
	{
		if (IBOO == 1)
			if (!(check_room(info, line)))
				return (0);
		if (IBOO == 2)
			info->end = ft_strdup(line, 0);
		IBOO = IBOO > 0 ? 4 : 0;
	}
	return (1);
}

int		get_base_entry(t_base *info, char *line)
{
	int		ret;

	ret = 0;
	IBE = NULL;
	info->end = NULL;
	info->index = 1;
	ft_printf("IN GET BASE ENTRY\n");
	while((ret = get_next_line(0, &line)) > 0)
	{
		if (!get_command(info, line))
			return (0);
		if (IANT > 0 && (IBOO == 0 || IBOO == 4) && (!(get_room(info, line))))
			return (0);
		else if (IANT == -1 && ft_isalldigit(line) &&
			(IANT = ft_atoi(line)) && IANT <= 0)
			return (0);
		IBOO = IBOO == 3 ? 0 : IBOO;
		IBE = ft_append(IBE, line, 3);
		IBE = ft_append(IBE, "\n", 1);
	}
	return (1);
}

void	init_struct(t_base *info)
{
	IBOO = 0;
	IANT = -1;
	ITB = NULL;
	IMX = NULL;
	info->a = 1;
	info->papa = NULL;
	info->last = NULL;
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

void	free_lemin(t_base *info)
{
	int		i;

	i = 0;
	if (IBE)
		free(IBE);
	if (ITB)
		free(ITB);
	if (info->end)
		free(info->end);
	if (IMX && IPAPA)
	{
		while (i < IMSZ)
			free(IMX[i++]);
		i = 0;
		while (i < 2)
			free(IPAPA[i++]);
		free(IMX);
		free(IPAPA);
	}
	if (ILH)
		free_list(info);
	free(info);
	return ;
}

int		main(void)
{
	t_base	*info;

	info = ft_memalloc(sizeof(t_base), 0);
	init_struct(info);
	if (!(get_base_entry(info, NULL)) && ft_printf("ENTRY ERROR\n"))
	{
		//sleep(3);
		return (0);
	}
	IBOO = 0;
	ft_printf("%s\n", IBE);
	if (!tube_cleaner(info, 0, 0))
	{
		//sleep(3);
		return (0);
	}
	if (!path_finder(info, 0, 0) && ft_printf("PATH FINDER ERROR\n"))
	{
		//sleep(3);
		return (0);
	}
	if (!get_path(info) && ft_printf("GET PATH ERROR\n"))
	{
		//sleep(3);
		return (0);
	}
	free_lemin(info);
	// ft_printf("ILT ++++++++\n");
	// while (i < IMSZ)
	// 	ft_printf("|%d", ILT[i++]);
	// ft_printf("\n");
	// ft_printf("ILT ++++++++\n");
	// i = 0;
	// while (i < 2)
	// {
	// 	j = 0;
	// 	while (j < IMSZ)
	// 	{
	// 		ft_printf("|");
	// 		ft_printf(RED"%d"C_DEFAULT, IPAPA[i][j++]);
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }
	// i = 0;
	// while (i < IMSZ)
	// {
	// 	j = 0;
	// 	while (j < IMSZ)
	// 	{
	// 		if (IMX[i][j] != 0)
	// 		{
	// 			ft_printf("|");
	// 			ft_printf(RED"%d"C_DEFAULT, IMX[i][j++]);
	// 		}
	// 		else
	// 			ft_printf("|%d", IMX[i][j++]);
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }
	return(0);
}