/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:23:40 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/13 23:14:13 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_put_get_right(t_env *env)
{
	int		i;
	int		j;

	j = env->b_col;
	while (--j >= 0)
	{
		i = env->b_row;
		while (--i >= 0)
		{
			if (ft_check_place(env, i, j) == 1)
			{
				env->pos_x = j;
				env->pos_y = i;
				return ;
			}
		}
	}
}

void	ft_put_get_left(t_env *env)
{
	int		i;
	int		j;

	j = -env->t_col_tr;
	while (++j < env->b_col)
	{
		i = -env->t_row_tr;
		while (++i < env->b_row)
		{
			if (ft_check_place(env, i, j) == 1)
			{
				env->pos_x = j;
				env->pos_y = i;
				return ;
			}
		}
	}
}
