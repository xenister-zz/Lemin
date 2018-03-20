/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_nword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:28:37 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/26 11:30:11 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** c = witch separator to use to define a word
** n = n'th word
** ex: "hello world" (c = space) : (if n = 1 -> we get "world")
*/

char	*ft_str_nword(char *str, int n, char c)
{
	char	*savei;
	int		count;

	savei = 0;
	count = -1;
	if (!str || n < 0 || !c)
		return (NULL);
	while (*str)
	{
		if (*str == c && savei)
		{
			if (count == n)
				return (ft_strsub(savei, 0, str - (savei)));
			savei = NULL;
		}
		else if (!savei && *str != c)
		{
			++count;
			savei = str;
		}
		str++;
	}
	if (savei && count == n)
		return (ft_strdup(savei, 0));
	return (NULL);
}
