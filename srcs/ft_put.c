/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:25:08 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 14:53:39 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_put_token(t_env *env)
{
	if (env->dir == DOWN)
		ft_put_down(env);
	if (env->dir == RIGHT)
		ft_put_right(env);
	if (env->dir == UP)
		ft_put_up(env);
	if (env->dir == LEFT)
		ft_put_left(env);
	if (env->dir == GET_RIGHT)
		ft_put_get_right(env);
	if (env->dir == GET_LEFT)
		ft_put_get_left(env);
}

void	ft_put_down(t_env *env)
{
	int		i;
	int		j;

	i = env->b_row;
	while (--i >= 0)
	{
		j = env->b_col;
		while (--j >= 0)
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

void	ft_put_up(t_env *env)
{
	int		i;
	int		j;

	i = -env->t_row_tr;
	while (++i < env->b_row)
	{
		j = -env->t_col_tr;
		while (++j < env->b_col)
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

void	ft_put_left(t_env *env)
{
	int		i;
	int		j;

	i = env->b_row;
	while (--i >= 0)
	{
		j = -env->t_col_tr;
		while (++j < env->b_col)
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

void	ft_put_right(t_env *env)
{
	int		i;
	int		j;

	i = -env->t_row_tr;
	while (++i < env->b_row)
	{
		j = env->b_col;
		while (--j >= 0)
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
