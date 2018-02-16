/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:06:05 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/16 19:18:45 by susivagn         ###   ########.fr       */
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
	if (!ft_check_tube(info, line))
		return (2);
	ITB = ft_append(ITB, line, 0);
	ITB = ft_append(ITB, "\n", 0);
	return (1);
}

int		ft_check_tube(t_base *info, char *line)
{
	char	*tmp;

	if (info->start)
	tmp = ft_strsub(line, 0, ft_strclen(line, ' '));
	if (ft_strchr(tmp, 'L') || ft_strchr(tmp, '#'))
		return (0);
	return(1);
}

int		ft_check_room(t_base *info, char *line)
{
	char	*tmp;
	t_house *thouse;

	tmp = ft_strsub(line, 0, ft_strclen(line, ' '));
	if (!tmp || tmp[0] == 'L' || tmp[0] == '#')
		return (0);
	else
	{
		thouse = ft_memalloc(sizeof(*thouse), 0);
		thouse->index = info->index;
		if (info->start && (thouse->name = info->start))
			thouse->index = 0;
		else 
			info->index++;
		thouse->name = tmp;
		ft_lstadd(&info->list_house, ft_lstnew(thouse, sizeof(*thouse)));
		free(thouse);

	}
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
	else if (ft_check_room(info, line))
		
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
			info->start = ft_append(ft_strdup(line, 0), "\n", 1);
		if (IBOO == 2)
			info->end = ft_append(ft_strdup(line, 0), "\n", 1);
		IBOO = IBOO > 0 ? 4 : 0;
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
	info->start = NULL;
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
	IRM = NULL;
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