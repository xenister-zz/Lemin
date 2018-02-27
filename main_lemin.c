/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:06:05 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/27 15:31:11 by susivagn         ###   ########.fr       */
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
		else if (ft_strchr(line, '#') && (IBOO = 3))
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
		ft_printf("END == |%s|\n", info->end);
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
	ft_printf("--- IN Base Entry ---\n");
	while((ret = get_next_line(0, &line)) > 0)
	{
		ft_printf("$$$$$ LINE  = |%s|\n", line);
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
	if (!(get_base_entry(info, NULL)) && ft_printf("ERROR"))
		return (0);
	
	/*if ((!IMX))
	create_matrix(info);
	ft_printf("--- Base Entry ---\n");
	ft_printf(IBE);
	ft_printf("===== ROOM =====\n");
	ft_printf(IRM);
	ft_printf("***** Tube *****\n");
	ft_printf(ITB);
	ft_printf("+++++ Matrix +++++\n");
	ft_printf("@@@@@@ ANT = %d @@@@@@\n", IANT);*/
	while (i < IMSZ)
	{
		j = 0;
		while (j < IMSZ)
		{
			if (IMX[i][j] == 1)
			{
				ft_printf("|");
				ft_printf(RED"%d"C_DEFAULT, IMX[i][j++]);
			}
			else
				ft_printf("|%d", IMX[i][j++]);
		}
		ft_printf("\n");
		i++;
	}
	return(0);
}