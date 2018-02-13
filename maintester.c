/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:16 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/12 23:40:20 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LibftXen/libft.h"

int		main()
{
    char	*pouet;

	pouet = "patate";
	pouet = ft_add_newline(pouet, 0);
	ft_printf("|%s|", pouet);
	return (0);
}