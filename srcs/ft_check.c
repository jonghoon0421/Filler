/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:51:16 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 15:11:59 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_wall_topright(t_env *env)
{
	int		i;

	i = -1;
	if (ft_strchr(env->map[0], env->myself) != NULL)
		return (1);
	while (env->map[++i] != NULL)
	{
		if (env->map[i][env->b_col - 1] == env->myself)
			return (1);
	}
	return (0);
}

int		ft_check_wall_botleft(t_env *env)
{
	int		i;

	i = -1;
	if (ft_strchr(env->map[env->b_row - 1], env->myself) != NULL)
		return (1);
	while (env->map[++i] != NULL)
	{
		if (env->map[i][0] == env->myself)
			return (1);
	}
	return (0);
}

void	ft_check_ul(t_env *env)
{
	if (ft_strchr(env->map[env->b_row - 1], env->myself) != NULL &&
		ft_check_wall_topright(env) == 1)
		env->dir = GET_RIGHT;
	else if (env->t_row_tr <= env->t_col_tr)
	{
		if (ft_strchr(env->map[env->b_row - 1], env->myself) != NULL)
			env->dir = RIGHT;
		else
			env->dir = DOWN;
	}
	else
	{
		if (ft_check_wall_topright(env) == 1)
			env->dir = DOWN;
		else
			env->dir = RIGHT;
	}
}

void	ft_check_dr(t_env *env)
{
	if (ft_strchr(env->map[0], env->myself) != NULL &&
		ft_check_wall_botleft(env) == 1)
		env->dir = GET_LEFT;
	else if (env->t_row_tr <= env->t_col_tr)
	{
		if (ft_strchr(env->map[0], env->myself) != NULL)
			env->dir = LEFT;
		else
			env->dir = UP;
	}
	else
	{
		if (ft_check_wall_botleft(env) == 1)
			env->dir = UP;
		else
			env->dir = LEFT;
	}
}

void	ft_check_direction(t_env *env)
{
	if (env->st_pos == UPLEFT)
		ft_check_ul(env);
	else if (env->st_pos == DOWNRIGHT)
		ft_check_dr(env);
}
