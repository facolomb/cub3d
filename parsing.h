/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:18:03 by mravera           #+#    #+#             */
/*   Updated: 2023/04/13 14:14:20 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "test.h"
# include "mlx/mlx.h"
# include "libft/libft.h"

//game
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WALL_RATIO 0.7
# define FOV 60
# define P_SIZE 0.1
# define SCREEN_DIST 0.1
# define DIR_STEP 2
# define MOUSE_SENS 0.3
# define X_STEP 0.1
# define Y_STEP 0.1

//keycode for MAC
# define ESC 53
# define ARROWUP 126
# define ARROWDOWN 125
# define ARROWLEFT 123
# define ARROWRIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}	t_imgdata;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	t_player	p;
	double		player_x;
	double		player_y;
	double		p_dir;
	int			check_map;
	char		**map;
	int			mapmx;
	int			mapmy;
	int			mouse_h;
	double		ray[2];
}	t_data;

//gnl
size_t			gnl_strlen(char *str);
char			*gnl_strchr(char *s, int x);
char			*gnl_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*ft_get_line(char *frigo);
char			*ft_save(char *frigo);
char			*ft_read_and_save(int fd, char *frigo);

//parsing.c
int				parsing(int argc, char **argv, t_data *data);
int				parse(int fd, t_data *data);
int				is_line(char *line);
int				cub_printmap(char *str);

//videur.c
int				videur(char **buf, t_data *data);
int				sort_nsew(char **str, t_data *data);
int				sort_fc(char **str, t_data *data);
int				check_xpm(char **path);
int				check_rgb(char **path);

//get_map.c
int				get_map(char *buf, int fd, t_data *data);
char			**add_line(char **old, char *newline);

//check_args.c
int				check_cub(int argc, char **argv);
int				check_open(char *file);
int				check_close(int fd);
int				is_cub(char *str);

//parsing_utils.c
int				is_nsewkey(char *str);
int				is_fckey(char *str);
int				is_map(char *str);
int				str_isdigit(char *str);
int				alrdy_set(char **str, t_data *data);

//cub_utils.c
void			freetab(char **tab);
int				free_data(t_data *data);
void			printab(char **tab);

//get_clean_buf.c
char			**get_clean_buf(char *buf);
char			*rm_lastbsn(char *str);

//map_utils.c
int				is_map(char *str);
int				is_mapkey(char c);
int				check_strmap(char *str);
int				print_maperr(void);
int				print_nsew(int x);

//check_map.c
int				check_map(t_data *data);

//is_map_closed.c
int				is_map_closed(t_data *data);
int				square_map(t_data *data);
int				ft_tabmaxlen(char **tab, t_data *data);
char			*stradd(char *old, int size, char x);

//cub_flood.c
int				cb_check_path(t_data *data);
char			**cb_dup_map(t_data *data);
int				cb_player_pos(t_data *data);
int				cb_set_player_pos(int x, int y, char dir, t_data *data);
int				cb_flood(char **grid, int i, int j, t_data *data);

//player_dir.c
int				p_dirup(t_data *data);
int				p_dirdown(t_data *data);
int				cb_mouse(int x, int y, t_data *data);

//player_move.c
int				p_up(t_data *data);
int				p_dw(t_data *data);

//t_raymain.c
double			t_get_dist(double dir, t_data *data);
int				t_whatis(double x, double y, t_data *data);
int				t_cekoi(double x, double y, t_data *data);

//wall_distance.c
double			walldistance(t_data *data, double x, double y);

//get_nsew_dist.c
double			get_dist_ne(double dir, t_data *data);
double			get_dist_nw(double dir, t_data *data);
double			get_dist_sw(double dir, t_data *data);
double			get_dist_se(double dir, t_data *data);
double			fisheye_d(double rel_dir);

//get_nsew_border.c
int				get_border_ne(double dir, t_data *data);
int				get_border_nw(double dir, t_data *data);
int				get_border_sw(double dir, t_data *data);
int				get_border_se(double dir, t_data *data);

//get_nsew_next.c
int				get_next_ne(double dir, t_data *data);
int				get_next_nw(double dir, t_data *data);
int				get_next_sw(double dir, t_data *data);
int				get_next_se(double dir, t_data *data);

//mlx_draw.c
void			my_pixel_put(t_imgdata *data, int x, int y, int color);

//mlx_hooks.c
int				cb_keypress(int keycode, t_data *data);
int				cb_mousepress(int button, int x, int y, t_data *data);

//cb_close.c
int				cb_close(t_data *data);

//next_frame.c
int				next_frame(t_data *data);
int				draw_col(int x, t_imgdata *img, t_data *data);
double			get_rel_dir(int x);

//ray_utils.c
double			dblmod(double a);
int				posmod(int a, int b);

#endif
