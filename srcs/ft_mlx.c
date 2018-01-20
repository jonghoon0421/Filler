/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:09:18 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 22:39:03 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_mlx_draw_map2(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < env->win_hgt - 40)
		mlx_pixel_put(env->mlx, env->win, env->win_wth - 20, i + 20, 0x666362);
	j = 0;
	while (j++ < env->win_wth - 40)
		mlx_pixel_put(env->mlx, env->win, j + 20, env->win_hgt - 20, 0x666362);
}

void	ft_mlx_draw_map(t_env *env)
{
	int		i;
	int		j;
	int		pi;
	int		pj;

	i = -1;
	while (++i < env->b_row)
	{
		j = -1;
		while (++j < env->b_col)
		{
			pi = 0;
			pj = 0;
			mlx_pixel_put(env->mlx, env->win, env->pt[i][j].x, env->pt[i][j].y,
				0x666362);
			while (pj++ < 10)
				mlx_pixel_put(env->mlx, env->win, env->pt[i][j].x + pj,
					env->pt[i][j].y, 0x666362);
			while (pi++ < 10)
				mlx_pixel_put(env->mlx, env->win, env->pt[i][j].x,
					env->pt[i][j].y + pi, 0x666362);
		}
	}
	ft_mlx_draw_map2(env);
}

void	ft_mlx_fill_myself(t_env *env, int i, int j)
{
	int		pi;
	int		pj;

	pi = 1;
	while (env->pt[i][j].y + pi < env->pt[i][j].y + 10)
	{
		pj = 1;
		while (env->pt[i][j].x + pj < env->pt[i][j].x + 10)
		{
			mlx_pixel_put(env->mlx, env->win, env->pt[i][j].x + pj,
				env->pt[i][j].y + pi, MYCOLOR);
			pj++;
		}
		pi++;
	}
}

void	ft_mlx_fill_enemy(t_env *env, int i, int j)
{
	int		pi;
	int		pj;

	pi = 1;
	while (env->pt[i][j].y + pi < env->pt[i][j].y + 10)
	{
		pj = 1;
		while (env->pt[i][j].x + pj < env->pt[i][j].x + 10)
		{
			mlx_pixel_put(env->mlx, env->win, env->pt[i][j].x + pj,
				env->pt[i][j].y + pi, ENEMYCOLOR);
			pj++;
		}
		pi++;
	}
}

void	ft_mlx_fill_map(t_env *env, t_map *cur)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->b_row)
	{
		j = -1;
		while (++j < env->b_col)
		{
			if (cur->mc[i][j] == env->myself)
				ft_mlx_fill_myself(env, i, j);
			if (cur->mc[i][j] == env->enemy)
				ft_mlx_fill_enemy(env, i, j);
		}
	}
}
