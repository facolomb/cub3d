/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:18:03 by mravera           #+#    #+#             */
/*   Updated: 2023/04/07 01:36:48 by mravera          ###   ########.fr       */
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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir;
}	t_player;

typedef struct s_data
{
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
int				p_dirup(t_player *p);
int				p_dirdown(t_player *p);

//player_move.c
int				p_xup(t_player *p);
int				p_yup(t_player *p);
int				p_xdown(t_player *p);
int				p_ydown(t_player *p);

//t_raymain.c
int				t_whatis(double x, double y, t_data *data);
double			wallDistance(t_player *player, int x, int y);

#endif
