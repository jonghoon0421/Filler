/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:28:52 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 23:02:48 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main_loop_hook(t_env *env)
{
	if (env->tmp->next != NULL)
	{
		ft_mlx_fill_map(env, env->tmp);
		mlx_do_sync(env->mlx);
		env->tmp = env->tmp->next;
	}
	return (0);
}

void	main_draw(t_env *env)
{
	ft_init(env);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_wth, env->win_hgt,
		"jonkim's Filler");
	ft_mlx_draw_map(env);
	mlx_hook(env->win, 2, 0, ft_window_hook, env);
	mlx_loop_hook(env->mlx, main_loop_hook, env);
	mlx_loop(env->mlx);
}

int		main(void)
{
	t_env	env;
	char	*line;

	ft_bzero(&env, sizeof(env));
	ft_read_player(&env);
	env.head = ft_memalloc(sizeof(t_map) + 1);
	env.tail = env.head;
	env.head->next = NULL;
	while (get_next_line(0, &line) > 0)
	{
		env.pos_x = 0;
		env.pos_y = 0;
		ft_read_board(&env, line);
		ft_read_token(&env);
		ft_check_direction(&env);
		ft_put_token(&env);
		ft_recalc_pos(&env);
		ft_free_all(&env);
	}
	main_draw(&env);
	return (0);
}
