/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:35:46 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 15:11:50 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_strsplit_del(char **str)
{
	int i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}

char	*ft_strdup_nn(t_env *env, int curr_row)
{
	char	*res;
	int		i;

	res = (char*)malloc(sizeof(char) * (env->t_col + 1));
	i = -1;
	while (++i < env->t_col_tr)
		res[i] = env->piece[curr_row][i + env->t_col_st];
	res[env->t_col_tr] = '\0';
	return (res);
}

int		ft_check_place(t_env *env, int bi, int bj)
{
	int		i;
	int		j;
	int		overlap;

	i = -1;
	overlap = 0;
	while (++i < env->t_row_tr)
	{
		j = -1;
		while (++j < env->t_col_tr)
		{
			if (env->piece[i][j] == '*' &&
				(OUTSIDE(i + bi, j + bj) || ENEMY1(i + bi, j + bj) ||
				ENEMY2(i + bi, j + bj)))
				return (0);
			if (env->piece[i][j] == '*' &&
				(MYSELF1(i + bi, j + bj) || MYSELF2(i + bi, j + bj)))
				overlap++;
		}
	}
	return (overlap == 1 ? 1 : 0);
}

void	ft_recalc_pos(t_env *env)
{
	env->pos_x -= env->t_col_st;
	env->pos_y -= env->t_row_st;
	ft_printf("%d %d\n", env->pos_y, env->pos_x);
}

void	ft_free_all(t_env *env)
{
	ft_strsplit_del(env->map);
	ft_strsplit_del(env->piece);
}
