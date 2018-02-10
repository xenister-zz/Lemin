/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:23:56 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/10 16:57:30 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append(char *source, char *toadd, int b)
{
	int		c;
	char	*str;

	str = NULL;
	if (!source && !toadd)
		return (str);
	if (!source && toadd)
		return(ft_strdup(toadd, 0));
	c = (ft_strlen(source) + ft_strlen(toadd));
	str = ft_strnew(c, '\0');
	if (!str)
		return (NULL);
	c = 0;
	str = ft_strcpy(str, source);
	str = ft_strncat(str, toadd, ft_strlen(toadd));
	if (b == 1)
		free(source);
	if (b == 2)
		free(toadd);
	if (b == 3)
	{
		free(source);
		free(toadd);
	}
	return (str);
}
