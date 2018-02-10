/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:49:11 by labelec           #+#    #+#             */
/*   Updated: 2018/02/10 16:45:33 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./LibftXen/libft.h"

# define IANT info->fourmi
# define IBE info->base_entry
# define IRM info->room
# define ITB info->tube
# define IMX info->matrix
# define IMSZ info->mxsize

typedef struct	s_base
{
	char	*base_entry;
	char	*room;
	char	*tube;
	int		**matrix;
	int		mxsize;
	int		fourmi;
	int		boo;
}				t_base;

int		main(void);
int		get_base_entry(t_base *info);
int		get_room(t_base *info, char *line);
int		get_tube(t_base *info, char	*line);

#endif
