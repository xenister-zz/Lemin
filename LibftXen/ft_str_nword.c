/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_nword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:28:37 by susivagn          #+#    #+#             */
/*   Updated: 2018/02/15 14:23:31 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// c = witch separator to use to define a word
// n = number of the word
// ex: "hello world" (c = space) : (if n = 1 -> we get "world")

char    *ft_str_nword(char *str, int n, char c)
{
    int     i;
    int     savei;
    int     count;

    i = 0;
    savei = 0;
    count = 0;
    if (!str || n < 0 || !c)
        return (NULL);
    if (n == 0)
        return (ft_strsub(str, 0, ft_strclen(str, c)));
    while (str[i])
    {
        if (str[i] == c && str[i + 1] && str[i + 1] == c)
            while (str[i] == c)
                i++;
        if (count == n)
            return(ft_strsub(str, savei + 1, ft_strclen(&str[i], c)));
        if (str[i] == c)
        {
            count++;
            savei = i;
        }
        i++;
    }
    return (NULL);
}