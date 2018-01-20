/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:55:47 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 20:49:15 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_window_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		ft_map_del(env);
		ft_pt_del(env);
		exit(0);
	}
	return (0);
}
