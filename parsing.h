/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:18:03 by mravera           #+#    #+#             */
/*   Updated: 2023/02/23 14:36:21 by mravera          ###   ########.fr       */
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

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
}	t_data;

size_t			gnl_strlen(char *str);
char			*gnl_strchr(char *s, int x);
char			*gnl_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*ft_get_line(char *frigo);
char			*ft_save(char *frigo);
char			*ft_read_and_save(int fd, char *frigo);

//parsing.c
int				parsing(int argc, char **argv);
int				parse(int fd, t_data *data);
int				is_nsewcf(char *str);
int				is_map(char *str);
int				is_key(char *str);

//videur.c
int				videur(char **buf, t_data *data);
int				sort_nsew(char **str, t_data *data);
int				check_xpm(char *path);

//check_args.c
int				check_cub(int argc, char **argv);
int				check_open(char *file);
int				check_close(int fd);
int				is_cub(char *str);

//cub_utils.c
void			freetab(char **tab);

//get_clean_buf.c
char			**get_clean_buf(int fd);
char			*rm_lastbsn(char *str);

#endif
