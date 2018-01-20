/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:52:06 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 19:27:58 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_player(t_env *env)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
	{
		env->myself = 'O';
		env->enemy = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		env->myself = 'X';
		env->enemy = 'O';
	}
	free(line);
}

void	ft_read_board(t_env *env, char *line)
{
	char	**size;

	size = ft_strsplit(line, ' ');
	env->b_row = ft_atoi(size[1]);
	env->b_col = ft_atoi(size[2]);
	env->map = ft_memalloc(sizeof(char*) * (env->b_row + 1));
	env->tail->mc = ft_memalloc(sizeof(char*) * (env->b_row + 1));
	ft_strsplit_del(size);
	free(line);
	ft_read_board2(env);
}

void	ft_read_board2(t_env *env)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	free(line);
	i = -1;
	while (++i < env->b_row)
	{
		get_next_line(0, &line);
		env->map[i] = ft_strdup(line + 4);
		env->tail->mc[i] = ft_strdup(line + 4);
		free(line);
	}
	ft_map_add(env);
	env->st_pos == 0 ? ft_read_position(env) : 0;
}

void	ft_read_position(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->b_row)
	{
		j = -1;
		while (++j < env->b_col)
		{
			if (env->map[i][j] == env->myself)
			{
				env->st_pos = UPLEFT;
				return ;
			}
			if (env->map[i][j] == env->enemy)
			{
				env->st_pos = DOWNRIGHT;
				return ;
			}
		}
	}
}

void	ft_read_token(t_env *env)
{
	char	*line;
	char	**size;
	int		i;

	get_next_line(0, &line);
	size = ft_strsplit(line, ' ');
	env->t_row = ft_atoi(size[1]);
	env->t_col = ft_atoi(size[2]);
	ft_strsplit_del(size);
	free(line);
	env->piece = ft_memalloc(sizeof(char*) * (env->t_row + 1));
	i = -1;
	while (++i < env->t_row)
	{
		get_next_line(0, &line);
		env->piece[i] = ft_strdup(line);
		free(line);
	}
	ft_token_trim(env);
}
