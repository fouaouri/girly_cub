/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:13:21 by fouaouri          #+#    #+#             */
/*   Updated: 2023/11/15 19:07:56 by nben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <limits.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include "../libs/libft/libft.h"
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define TURN_DIREC 0
# define MOVE -1
# define UP 119
# define DOWN 115
# define LEFT 65361
# define RIGHT 65363
# define A_LEFT 97
# define D_RIGHT 100
# define ESC 65307
# define PINK_PIXEL 0xFF69B4
# define PINKY_PIXEL 0xFFC0CB
# define WHITE_PIXEL 0xFFFFFF
# define BLUE_PIXEL 0x0000FF
# define UNIT_SIZE 10
# define PI 3.141592653589793

typedef struct s_coordinates
{
	double	i;
	double	j;
	double	b;
	double	wall_len;
	double	wall_len2;
	double	w;
	double	height;
	double	width;
	double	p_x;
	double	p_y;
	double	get_key;
	double	counter;
	double	turn_direc;
	double	walk_direc;
	double	direction;
	int		size_line;
	int		size_line_north;
	int		size_line_s;
	int		size_line_e;
	int		size_line_w;
	char	direc;
	int		offset;
	double	di_player_projection;
	double	proj_wall_height;
	double	wall_height;
	double	top_pixel;
	double	bottom_pixel;
	double	point_x;
	double	point_x1;
	double	point_y;
	double	point_y1;
	double	t;
	double	f;
	double	g;
	double	c;
	double	c1;
	double	r;
	int		flag;
	int		a;
	int		color;
}t_coordinates;

typedef struct s_mystruct{
	char	**map;
	char	**square_map;
	char	**rectang_map;
	char	**clrs_txtrs;
	char	**file;
	char	**content;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		count;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	int		c_value;
	int		f_value;
	int		to_allocate;
	int		len;
	int		l;
	int		count_map;
	int		max_x;
}t_mystruct;

typedef struct s_builders
{
	void			*mlx;
	void			*mlx_win;
	void			*image;
	void			*image_north;
	void			*image_s;
	void			*image_e;
	void			*image_w;
	unsigned int	*data_north;
	unsigned int	*data_s;
	unsigned int	*data_w;
	unsigned int	*data_e;
	void			*wall;
	unsigned int	*data;
	void			*exit;
	char			*line;
	char			**map;
	char			**check;
	t_coordinates	*coors;
	t_mystruct		*pars;
	int				colects;
	int				pcount;
	int				ecount;
	int				moves;
	void			*img;
	char			*addr;
	double			up_down;
	double			view;
}t_builders;

char	*read_file(int fd, char *counter);
char	*put_on_the_line(char *counter);
char	*get_update(char *counter);
char	*get_next_line(int fd);
int		key_hook(t_builders *param);
void	pose_player(t_builders *param);
void	split_map(t_builders *param);
void	get_mlx(t_builders *param);
int		ft_up_down(double t);
int		ft_right_left(double t);
void	return_after_2_pi(t_builders param);
void	data_value(t_builders *param, int y, int x, int color);
void	return_after_2_pi1(t_builders *param);
void	hori_up(t_builders *param);
void	hori_down(t_builders *param);
void	vertical_down(t_builders *param);
void	vertical_up(t_builders *param);
void	draw_rays(t_builders *param);
int		realising(int key, t_builders *param);
int		hooking(int key, t_builders *param);
void	short_ligne(char **str, int len);
char	*ft_strjoin_(char *s1, char *s2);
int		invalide_wall(struct s_mystruct *strct);
void	invalide_char(struct s_mystruct *strct);
void	num_of_player(struct s_mystruct *strct);
void	parsing_of_clrs_txtrs(struct s_mystruct *strct);
void	second_parsing(struct s_mystruct *strct);
void	pars_part(int ac, char **av, struct s_mystruct *strct);
void	rectang_map(t_mystruct *strct);
void	get_floor_ceiling(t_builders *param);
int		check_wall(t_builders *param, int y, int x);
void	color_buffer(t_builders *param, double wall_len, double i, double j);
void	put_img(t_builders *param, int wall_len, int x, int y);
void	loop_mlx(t_builders *param);
void	init_mlx(t_builders *param);
void	init_player(t_builders *param);
void	init_main(t_builders *param);
void	vertical_up(t_builders *param);
void	vertical_down(t_builders *param);
void	hori_down(t_builders *param);
void	hori_up(t_builders *param);
char	**ft_free(char **spliter);
void	rectang_map(struct s_mystruct *strct);
void	parsing_of_colors(struct s_mystruct *strct);
int		check_ligne(char *strct);
int		ft_mystrlen(char **str);
int		ft_len(char **str);
int		ft_strlen_(char *str);
int		square_map2(struct s_mystruct *strct, int len);
void	parse_first_line(struct s_mystruct *strct);
void	check_space(struct s_mystruct *strct, int j, int i);
void	check_space2(struct s_mystruct *strct, int j, int i);
void	square_map3(struct s_mystruct *strct, int *j, int i, int l);
void	check_last_ligne(struct s_mystruct *strct);
void	new_ligne_in_map(struct s_mystruct *strct, int *j, int i);
void	count_to_allocate(int fd1, int i, char *str, struct s_mystruct *strct);
int		close_win(void);
void	we_check(struct s_mystruct *strct, int i, int j);
void	ea_check(struct s_mystruct *strct, int i, int j);
void	check_comma(char *str);
void	no_check(struct s_mystruct *strct, int i, int j);
void	check_space_(char **map);
int		new_ligne(struct s_mystruct *strct);
void	exit_error(char *str);
int		count_map(char **map);

#endif