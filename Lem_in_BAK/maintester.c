/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:16 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/16 18:56:49 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LibftXen/libft.h"

int		main()
{
    char	*pouet1;
	char	*pouet2;
	char	*pouet3;
	char	*pouet4;
	char	**gropouet;
	int		i = -1;
	int		j;

	pouet1 = "waka";
	pouet2 = "patate";
	pouet3 = "poundai";
	pouet4 = "kolioty";

	ft_printf("TEXT |%s|\n", pouet1);
	ft_printf("TEXT |%s|\n", pouet2);
	ft_printf("TEXT |%s|\n", pouet3);
	ft_printf("TEXT |%s|\n", pouet4);
	ft_printf("BEFORE\n");
	gropouet = ft_addchartable(gropouet, pouet1, 4);
	gropouet = ft_addchartable(gropouet, pouet3, 4);
	gropouet = ft_addchartable(gropouet, pouet2, 4);
	gropouet = ft_addchartable(gropouet, pouet4, 4);
	i = -1;
	ft_printf("AFTER\n");
	while (gropouet[++i])
	{
		ft_printf("|%s|\n", gropouet[i]);
	}
	return (0);
}