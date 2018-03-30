/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:12:03 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/30 16:51:31 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_tab(int **tab, int sizey, int sizex, char *str)
{
	int		i;
	int		j;

	i = 0;
	if (!tab || !*tab)
		return ;
	while (i < sizey)
	{
		j = 0;
		while (j < sizex)
		{
			ft_printf(YELLOW"%s|%d"C_DEFAULT, str, tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return ;
}
