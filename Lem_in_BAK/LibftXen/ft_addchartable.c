/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchartable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:48 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/16 18:55:54 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char		**ft_addchartable(char **table, char *toadd, int size)
{
	int		i;

	i = 0;
	if (!toadd)
		return (table);
	if (!table)
	{
		table = (char**)ft_memalloc((size + 1) * (sizeof(char*)), '\0');
		table[size] = NULL;
	}
	while (table[i] != NULL && table[i][0] != '\0')
		i++;
	table[i] = toadd;
	return (table);
}
