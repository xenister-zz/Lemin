/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:48 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/09 06:17:33 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int			**ft_inttable(int **table, int sizex, int sizey)
{
	int		i;

	i = 0;
	if (!table)
		table = (int**)ft_memalloc((sizey * (sizeof(int*))), 0);
	while (i < sizex)
	{
		table[i] = (int*)ft_memalloc((sizex * (sizeof(int))), 0);
		i++;
	}
	return (table);
}