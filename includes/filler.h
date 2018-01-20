/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:48:11 by jonkim            #+#    #+#             */
/*   Updated: 2018/01/19 22:39:08 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <string.h>
# include <strings.h>

# define UPLEFT 1
# define DOWNRIGHT 2
# define UP 3
# define DOWN 4
# define LEFT 5
# define RIGHT 6
# define GET_RIGHT 7
# define GET_LEFT 8
# define MYCOLOR 0xFFD700
# define ENEMYCOLOR 0xFF0000

# define OUTSIDE(i, j) (i >= env->b_row || j >= env->b_col || i < 0 || j < 0)
# define ENEMY1(i, j) (env->map[i][j] == env->enemy)
# define ENEMY2(i, j) (env->map[i][j] == env->enemy + 32)
# define MYSELF1(i, j) (env->map[i][j] == env->myself)
# define MYSELF2(i, j) (env->map[i][j] == env->myself + 32)

typedef struct		s_map
{
	char			**mc;
	struct s_map	*next;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	t_map			*head;
	t_map			*tail;
	void			*mlx;
	void			*win;
	int				win_wth;
	int				win_hgt;
	t_point			**pt;
	char			**map;
	char			**piece;
	char			myself;
	char			enemy;
	int				b_row;
	int				b_col;
	int				st_pos;
	int				dir;
	int				t_row;
	int				t_col;
	int				t_row_tr;
	int				t_col_tr;
	int				t_row_st;
	int				t_col_st;
	int				t_row_end;
	int				t_col_end;
	int				pos_x;
	int				pos_y;
	t_map			*tmp;
}					t_env;

/*
** ft_read.c
*/
void				ft_read_player(t_env *env);
void				ft_read_board(t_env *env, char *line);
void				ft_read_board2(t_env *env);
void				ft_read_position(t_env *env);
void				ft_read_token(t_env *env);

/*
** ft_stuff.c
*/
void				ft_strsplit_del(char **str);
char				*ft_strdup_nn(t_env *env, int curr_row);
int					ft_check_place(t_env *env, int bi, int bj);
void				ft_recalc_pos(t_env *env);
void				ft_free_all(t_env *env);

/*
** ft_stuff2.c
*/
void				ft_map_add(t_env *env);
void				ft_map_del(t_env *env);
void				ft_init(t_env *env);
void				ft_pt_del(t_env *env);

/*
** ft_token.c
*/
void				ft_token_stx(t_env *env);
void				ft_token_sty(t_env *env);
void				ft_token_endx(t_env *env);
void				ft_token_endy(t_env *env);
void				ft_token_trim(t_env *env);

/*
** ft_check.c
*/
void				ft_check_direction(t_env *env);
int					ft_check_wall_topright(t_env *env);
int					ft_check_wall_botleft(t_env *env);
void				ft_check_ul(t_env *env);
void				ft_check_dr(t_env *env);

/*
** ft_put.c
*/
void				ft_put_token(t_env *env);
void				ft_put_down(t_env *env);
void				ft_put_up(t_env *env);
void				ft_put_left(t_env *env);
void				ft_put_right(t_env *env);

/*
** ft_put2.c
*/
void				ft_put_get_right(t_env *env);
void				ft_put_get_left(t_env *env);

/*
** ft_mlx.c
*/
void				ft_mlx_draw_map(t_env *env);
void				ft_mlx_draw_map2(t_env *env);
void				ft_mlx_fill_map(t_env *env, t_map *cur);
void				ft_mlx_fill_myself(t_env *env, int i, int j);
void				ft_mlx_fill_enemy(t_env *env, int i, int j);

/*
** ft_window.c
*/
int					ft_window_hook(int keycode, t_env *env);

/*
** main.c
*/
void				main_draw(t_env *env);
int					main_loop_hook(t_env *env);

#endif
