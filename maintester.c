/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:16 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/26 11:33:43 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LibftXen/libft.h"

int		main()
{
    char	*pouet;

	pouet = "7  48";
	pouet = ft_str_nword(pouet, 3, ' ');
	ft_printf("|%s|\n", pouet);
	/*pouet = "pattedepain-*+ p++9554oire   petit mais cousteau";
	pouet = ft_str_nword(pouet, 1, ' ');
	ft_printf("|%s|\n", pouet);
	pouet = "pattedepain-*+ p++9554oire   petit mais cousteau";
	pouet = ft_str_nword(pouet, 2, ' ');
	ft_printf("|%s|\n", pouet);
	pouet = "pattedepain-*+ p++9554oire   petit mais cousteau";
	pouet = ft_str_nword(pouet, 3, ' ');
	ft_printf("|%s|\n", pouet);
	pouet = "pattedepain-*+ p++9554oire   petit mais cousteau";
	pouet = ft_str_nword(pouet, 4, ' ');
	ft_printf("|%s|\n", pouet);*/
	return (0);
}