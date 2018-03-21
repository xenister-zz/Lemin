/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:06:05 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/21 20:26:09 by susivagn         ###   ########.fr       */
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
			{
				free(line);
				return (0);
			}
		if (IBOO == 2)
			info->end = ft_strdup(line, 0);
		IBOO = IBOO > 0 ? 4 : 0;
	}
	ft_printf("EXIT GET COMMAND\n");
	return (1);
}

int		get_base_entry(t_base *info, char *line)
{
	int		ret;

	ret = 0;
	IBE = NULL;
	info->end = NULL;
	info->index = 1;
	line = NULL;
	//dprintf(2, "IN GET BASE ENTRY\n");
	while((ret = get_next_line(0, &line)) > 0)
	{
		//ft_printf(RED"|%s|"C_DEFAULT, line);
		if (!get_command(info, line))
			return (0);
		if (IANT > 0 && (IBOO == 0 || IBOO == 4) && (!(get_room(info, line))))
		{
			free(line);
			return (0);
		}
		else if (IANT == -1 && ft_isalldigit(line) &&
			(IANT = ft_atoi(line)) && IANT <= 0)
		{
			free(line);
			return (0);
		}
		IBOO = IBOO == 3 ? 0 : IBOO;
		IBE = ft_append(IBE, line, 3);
		//ft_printf("|************************************%s|\n", line);
		IBE = ft_append(IBE, "\n", 1);
	}
	free(line);
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
	IRM = NULL;
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
	if (ILT)
		free(ILT);
	if (ILH)
		free_list(info);
	free(info);
	return ;
}

void	exiter(t_base *info)
{
	free_lemin(info);
	exit(-1);
}

int		main(void)
{
	t_base	*info;

	info = ft_memalloc(sizeof(t_base), 0);
	init_struct(info);
	if (!(get_base_entry(info, NULL)) && ft_printf("ENTRY ERROR\n"))
	{
		free_lemin(info);
		get_next_line(-2, NULL);
		return (0);
	}
	IBOO = 0;
	ft_printf("%s\n", IBE);
	if (!tube_cleaner(info, 0, 0))
		exiter(info);
	if (!path_finder(info, 0, 0) && ft_printf("PATH FINDER ERROR\n"))
		exiter(info);
	if (!get_path(info) && ft_printf("GET PATH ERROR\n"))
		exiter(info);
	free_lemin(info);
	return(0);
}