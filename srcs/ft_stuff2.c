/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stuff2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:52:46 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 21:46:20 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_map_add(t_env *env)
{
	env->tail->next = ft_memalloc(sizeof(t_map) + 1);
	env->tail = env->tail->next;
	env->tail->next = NULL;
}

void	ft_map_del(t_env *env)
{
	t_map	*cursor;
	t_map	*tmp;

	cursor = env->head;
	while (cursor->next != NULL)
	{
		tmp = cursor->next;
		ft_strsplit_del(cursor->mc);
		free(cursor);
		cursor = tmp;
	}
	env->head = NULL;
}

void	ft_init(t_env *env)
{
	int		i;
	int		j;

	env->win_hgt = (env->b_row * 10) + 40;
	env->win_wth = (env->b_col * 10) + 40;
	env->pt = ft_memalloc(sizeof(t_point*) * (env->b_row + 1));
	i = -1;
	while (++i < env->b_row)
		env->pt[i] = ft_memalloc(sizeof(t_point) * env->b_col);
	i = -1;
	while (++i < env->b_row)
	{
		j = -1;
		while (++j < env->b_col)
		{
			env->pt[i][j].x = (j * 10) + 20;
			env->pt[i][j].y = (i * 10) + 20;
		}
	}
	env->tmp = env->head;
}

void	ft_pt_del(t_env *env)
{
	int		i;

	i = -1;
	while (env->pt[++i])
		free(env->pt[i]);
	free(env->pt);
}
