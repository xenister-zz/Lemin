/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:17:07 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/10 15:44:06 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checkentry_atoi(const char *str, int neg)
{
	int		i;
	char	*max;
	char	*min;

	i = 0;
	max = "2147483647";
	min = "2147483648";
	while (str[i] && str[i] > 47 && str[i] < 58)
		i++;
	if (i > 10)
		return (0);
	if (i == 10)
	{
		if ((neg == -1) && (ft_strncmp(min, str, i) < 0))
			return (0);
		if ((neg == 1) && (ft_strncmp(max, str, i) < 0))
			return (0);
	}
	return (1);
}

int		ft_atoi(const char *str)
{
	int		c;
	int		tmp;
	int		neg;

	c = 0;
	neg = 1;
	tmp = 0;
	while ((str[c] > 8 && str[c] < 14) || str[c] == 32 || str[c] == 48)
		c++;
	if (str[c] == '-')
		neg = -1;
	if (str[c] == '+' || str[c] == '-')
		c++;
	if (!(checkentry_atoi(&str[c], neg)))
		return (0);
	while (str[c] && str[c] > 47 && str[c] < 58)
	{
		tmp = (tmp * 10) + (str[c] - 48);
		c++;
	}
	if (neg < 0)
		return (neg * tmp);
	return (tmp);
}
