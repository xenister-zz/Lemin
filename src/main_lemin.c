/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:06:05 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/30 18:17:26 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		get_command(t_base *info, char *line)
{
	if (IBOO == 0 && line[0] == '#')
	{
		if ((ft_strcmp(line, "##start") == 0) && (IBOO = 1) && (info->a += 1))
			return (1);
		else if ((ft_strcmp(line, "##end") == 0) && (IBOO = 2) &&
			(info->a += 1))
			return (1);
		else if ((IBOO = 3))
			return (1);
		else
			free(line);
		return (0);
	}
	else
	{
		if ((ft_count_char(line, '#') <= 3) && (line[0] == '#'))
			return (1);
		if (IBOO == 1 && (!check_room(info, line)))
			return (0);
		if (IBOO == 2 && (info->end_up = 1))
			info->end = ft_strdup(line, 0);
		IBOO = IBOO > 0 ? 4 : 0;
	}
	return (1);
}

int		antcheck(char *line)
{
	int		i;

	i = 0;
	if (!line)
		return (0);
	if (line[0] == '-' || line[0] == '+')
		i++;
	if (!ft_isalldigit(&line[i]))
		return (0);
	return (1);
}

int		get_base_entry(t_base *info, char *line, int ret)
{
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == '\0')
		{
			free(line);
			return (0);
		}
		if (!get_command(info, line))
			return (0);
		if (IANT > 0 && (IBOO == 0 || IBOO == 4) && (!(get_room(info, line))))
			return (0);
		else if (((IANT == -1) && !antcheck(line)) || ((IANT == -1) &&
			((IANT = ft_atoi(line)) <= 0)))
		{
			free(line);
			return (0);
		}
		IBOO = IBOO == 3 ? 0 : IBOO;
		IBE = ft_append(IBE, line, 3);
		IBE = ft_append(IBE, "\n", 1);
	}
	free(line);
	return (1);
}

void	exiter(t_base *info)
{
	free_lemin(info, 0);
	exit(-1);
}

int		main(void)
{
	t_base	*info;

	info = ft_memalloc(sizeof(t_base), 0);
	init_struct(info);
	if (!(get_base_entry(info, NULL, 0)) && info->nbr_of_tube < 1 &&
		ft_printf("ERROR\n"))
	{
		free_lemin(info, 0);
		get_next_line(-2, NULL);
		return (0);
	}
	IBOO = 0;
	info->a = 1;
	if (!tube_cleaner(info, 0, 0))
		exiter(info);
	if (!path_finder(info, 0, 0) && ft_printf("ERROR\n"))
		exiter(info);
	info->a = 0;
	if (!get_path(info) && ft_printf("ERROR\n"))
		exiter(info);
	free_lemin(info, 0);
	return (0);
}
