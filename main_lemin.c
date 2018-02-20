/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:06:05 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/20 23:20:16 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_matrix(t_base *info)
{
	int		size;

	if ((!IMX) && (IMSZ = info->index))
		IMX = ft_inttable(IMX, IMSZ, IMSZ);
	return (1);
}

int		get_tube(t_base *info, char	*line)
{
	ft_printf("--- IN TUBE ---\n");
	if (info->end && !(check_room(info, info->end)) && (info->end = NULL))
		return (0);
	return (1);
}

int		check_tube(t_base *info, char *line)
{
	ft_printf("--- IN CHECK TUBE ---\n");
	
	return(1);
}

int		list_room(t_base *info, int index, char *name)
{
	t_house		*thouse;
	t_list		*tempo;
 

	if (!(thouse = ft_memalloc(sizeof(*thouse), 0)))
		return (0);
	thouse->index = index;
	thouse->name = name;
	ft_lstadd(&info->list_house, ft_lstnew(thouse, sizeof(*thouse)));
	free(thouse);
	tempo = info->list_house;
	ft_printf("--------------PRINTING LIST----------------\n");
	while (ILC->name || ILN != NULL)
	{
		ft_printf("Index = |%d| - Name = |%s|\n", ILC->index, ILC->name);
		if (ILN != NULL)
			ILH = ILN;
		else
			break ;
	}
	ILH = tempo;
	return (1);
}

int		check_room(t_base *info, char *line)
{
	char	*tmp;
	
	ft_printf("ENTRY CHECK ROOM\n");
	ft_printf("LINE  ==  %s|\n", line);
	tmp = ft_strsub(line, 0, ft_strclen(line, ' '));
	if (!tmp || tmp[0] == 'L' || tmp[0] == '#')
		return (0);
	else if (IBOO == 1)
		return (list_room(info, 0, line));
	else if (!(list_room(info, info->index, tmp)))
			return (0);
	info->index++;
	return(1);
}

int		get_room(t_base *info, char *line)
{
	ft_printf("--- IN ROOM ---%d-\n", IBOO);
	if (IBOO == 4)
	{
		IBOO = 0;
		return(1);
	}
	if (ft_strchr(line, '-'))
		return (get_tube(info, line));
	if (line[0] == ' ' || ft_count_char(line, ' ') != 2)
		return (0);
	else
		return (check_room(info, line));
	return (1);
}

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
	return (0);
}

int		get_base_entry(t_base *info)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	IBE = NULL;
	info->end = NULL;
	info->index = 1;
	ft_printf("--- IN Base Entry ---\n");
	while((ret = get_next_line(0, &line)) > 0)
	{
		//ft_printf("$$$$$ LINE  = |%s|\n", line);
		get_command(info, line);
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
	if (!(get_base_entry(info)) && ft_printf("ERROR"))
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
	ft_printf("@@@@@@ ANT = %d @@@@@@\n", IANT);
	while (i < IMSZ)
	{
		j = 0;
		while (j < IMSZ)
		{
			ft_printf("|%d", IMX[i][j++]);
		}
		ft_printf("\n");
		i++;
	}*/
	return(0);
}