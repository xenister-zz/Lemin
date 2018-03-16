/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:06:05 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/16 19:40:44 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_command(t_base *info, char *line)
{
	if (IBOO == 0 && !ft_strstr(line, "###"))
	{
		if(ft_strstr(line, "##start") && (IBOO = 1))
			return (1);
		else if (ft_strstr(line, "##end") && (IBOO = 2))
			return (1);
		else if (ft_strstr(line, "#") && (IBOO = 3))
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
		//ft_printf("END == |%s|\n", info->end);
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
	//ft_printf("--- IN Base Entry ---\n");
	while((ret = get_next_line(0, &line)) > 0)
	{
		//ft_printf("$$$$$ LINE  = |%s|\n", line);
		if (!get_command(info, line))
			return (0);
		if (IANT > 0 && (IBOO == 0 || IBOO == 4) && (!(get_room(info, line))))
			return (0);
		else if (IANT == -1 && (IANT = ft_atoi(line)) && IANT <= 0)
			return (0);
		IBOO = IBOO == 3 ? 0 : IBOO;
		IBE = ft_append(IBE, line, 2);
		IBE = ft_append(IBE, "\n", 0);
	}
	return (1);
}

int		main(void)
{
	t_base	*info;
	int		i, j;

	info = ft_memalloc(sizeof(t_base), 0);
	i = 0;
	IBOO = 0;
	IANT = -1;
	ITB = NULL;
	IMX = NULL;
	info->a = 1;
	info->papa = NULL;
	info->last = NULL;
	if (!(get_base_entry(info, NULL)) && ft_printf("ERROR"))
		return (0);
	IBOO = 0;
	ft_printf("%s\n", IBE);
	if (!tube_cleaner(info, 0, 0))
		return (0);
	if (!path_finder(info, 0, 0) && ft_printf("ERROR"))
		return (0);
	if (!get_path(info) && ft_printf("ERROR"))
		return (0);
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