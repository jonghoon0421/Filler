/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:16:15 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/11 00:25:08 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_token_stx(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->t_row)
	{
		j = -1;
		while (++j < env->t_col)
		{
			if (env->piece[i][j] == '*')
			{
				env->t_row_st = i;
				return ;
			}
		}
	}
}

void	ft_token_sty(t_env *env)
{
	int		i;
	int		j;

	j = -1;
	while (++j < env->t_col)
	{
		i = -1;
		while (++i < env->t_row)
		{
			if (env->piece[i][j] == '*')
			{
				env->t_col_st = j;
				return ;
			}
		}
	}
}

void	ft_token_endx(t_env *env)
{
	int		i;
	int		j;

	i = env->t_row;
	while (--i >= 0)
	{
		j = env->t_col;
		while (--j >= 0)
		{
			if (env->piece[i][j] == '*')
			{
				env->t_row_end = i;
				return ;
			}
		}
	}
}

void	ft_token_endy(t_env *env)
{
	int		i;
	int		j;

	j = env->t_col;
	while (--j >= 0)
	{
		i = env->t_row;
		while (--i >= 0)
		{
			if (env->piece[i][j] == '*')
			{
				env->t_col_end = j;
				return ;
			}
		}
	}
}

void	ft_token_trim(t_env *env)
{
	int		i;
	char	**tmp;

	ft_token_stx(env);
	ft_token_sty(env);
	ft_token_endx(env);
	ft_token_endy(env);
	env->t_row_tr = env->t_row_end - env->t_row_st + 1;
	env->t_col_tr = env->t_col_end - env->t_col_st + 1;
	tmp = (char**)malloc(sizeof(char*) * (env->t_row + 1));
	i = -1;
	while (++i < env->t_row_tr)
		tmp[i] = ft_strdup_nn(env, i + env->t_row_st);
	tmp[env->t_row_tr] = NULL;
	ft_strsplit_del(env->piece);
	env->piece = tmp;
}
