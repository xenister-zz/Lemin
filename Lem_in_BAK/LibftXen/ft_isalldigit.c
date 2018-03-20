/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalldigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:47:55 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/26 12:40:34 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalldigit(char *src)
{
	int		i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		if ((src[i] < '0' || src[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
