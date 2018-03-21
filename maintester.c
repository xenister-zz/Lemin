/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:16 by susivagn          #+#    #+#             */
/*   Updated: 2018/03/21 08:21:54 by susivagn         ###   ########.fr       */
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

	pouet1 = "1230";
	pouet2 = "  1231111145";
	pouet3 = "  23  456";
	pouet4 = "12123145    ";

	ft_printf("RES == |%d|\n", ft_count_char(pouet1, '1'));
	ft_printf("RES == |%d|\n", ft_count_char(pouet2, '1'));
	ft_printf("RES == |%d|\n", ft_count_char(pouet3, '1'));
	ft_printf("RES == |%d|\n", ft_count_char(pouet4, '1'));
	
	return (0);
}