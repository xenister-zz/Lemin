/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:06:05 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/09 07:33:27 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		the_matrix(t_base *info)
{
	return (0);
}

int		create_matrix(t_base *info)
{
	int		size;

	if ((!IMX) && (IMSZ = ft_count_char(IRM, '\n')))
		IMX = ft_inttable(IMX, IMSZ, IMSZ);
	return (1);
}

int		get_tube(t_base *info, char	*line)
{
	if ((!IMX))
		create_matrix(info);
	if (!ITB)
		ITB = ft_strdup(line, 0);
	else
		ITB = ft_append(ITB, line, 0);
	ITB = ft_append(ITB, "\n", 0);
	return (1);
}

int		get_room(t_base *info, char *line)
{ 
	if (ft_strchr(line, '-'))
		return (get_tube(info, line));
	if (ft_strchr(line, '#'))
		return (1);
	if (ft_count_char(line, ' ') != 2)
		return (0);
	if (!IRM)
		IRM = ft_strdup(line, 0);
	else
		IRM = ft_append(IRM, line, 0);
	IRM = ft_append(IRM, "\n", 0);
	return (1);
}

int		get_base_entry(t_base *info)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	info->base_entry = NULL;
	while((ret = get_next_line(0, &line)) > 0)
	{
		if (IANT == -1)
			IANT = ft_atoi(line);
		if (IANT <= 0)
			return (0);
		if (IBE == NULL)
			IBE = ft_strdup(line, 1);
		else
		{
			if(!(get_room(info, line)))
				return (0);
			IBE = ft_append(IBE, line, 2);
		}
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
	IANT = -1; 
	IRM = NULL;
	ITB = NULL;
	IMX = NULL;
	if (!(get_base_entry(info)))
	{
		ft_printf("ERROR");
		return (0);
	}
	ft_printf("--- Base Entry ---\n");
	ft_printf(IBE);
	ft_printf("===== ROOM =====\n");
	ft_printf(IRM);
	ft_printf("***** Tube *****\n");
	ft_printf(ITB);
	ft_printf("+++++ Matrix +++++\n");
	while (i < IMSZ)
	{
		j = 0;
		while (j < IMSZ)
		{
			ft_printf("|%d", IMX[i][j++]);
		}
		ft_printf("\n");
		i++;
	}
	return(0);
}