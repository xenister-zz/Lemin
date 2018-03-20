/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:16 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/20 05:14:50 by susivagn         ###   ########.fr       */
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

	pouet1 = "12345";
	pouet2 = "  1245";
	pouet3 = "  12  456";
	pouet4 = "1212145    ";

	ft_printf("TEXT |%s|\n", pouet1);
	ft_printf("TEXT |%s|\n", pouet2);
	ft_printf("TEXT |%s|\n", pouet3);
	ft_printf("TEXT |%s|\n", pouet4);
	ft_printf("BEFORE\n");

	ft_printf("RES == |%d|\n", ft_isalldigit_space(pouet1));
	ft_printf("RES == |%d|\n", ft_isalldigit_space(pouet2));
	ft_printf("RES == |%d|\n", ft_isalldigit_space(pouet3));
	ft_printf("RES == |%d|\n", ft_isalldigit_space(pouet4));
	
	return (0);
}