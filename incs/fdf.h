/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:50:30 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/27 07:39:47 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>

# define HEIGHT 1920
# define WIDTH 1080

typedef struct s_delta
{
	float	delta_x;
	float	delta_y;
	float	delta_r;
	float	delta_g;
	float	delta_b;
}		t_delta;

typedef struct s_colors
{
	float	a;
	float	r;
	float	g;
	float	b;
}			t_colors;

typedef struct s_map
{
	float			x;
	float			y;
	int				z;
	char			*color;
	int				real;
	struct s_map	*next;
}		t_map;

typedef struct s_coord
{
	float		x0;
	float		y0;
	long int	z0;
	float		x1;
	float		y1;
}				t_coord;

typedef struct s_img_vars
{
	void		*img;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	char		*buffer;
}			t_img_vars;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*start;
	t_img_vars	*img;
}				t_mlx;

/*		list_func			*/
int			ft_linelen(t_map *li);
int			ft_listlen(t_map *li);
void		ft_lstrm_front(t_map **li);
int			ft_lstadd_front(t_map **li, int x, char *color, int real);
void		ft_lst_reverse(t_map **map);

/*			Utils			*/
char		*ft_strndup(const char *s, unsigned int n);
t_map		*calculate_coord(t_map *map);
t_colors	*hex_to_rgb(char *hex);
char		*char_to_string(char c, char d);

/*			Draw			*/
void		draw_pixel(char *buffer, int pixel, t_colors color, int endian);
void		pix_draw(t_img_vars *img, int x, int y, t_colors col);
void		drawto(t_img_vars *img, t_coord *co, t_colors colnew,
				t_colors before);
void		draw_all(t_img_vars *img, t_map *map, t_mlx *mlx);

/*		Image Gestion		*/
void		init_img(t_img_vars *img, t_mlx mlx);

/*			Hook			*/
int			key_hook(int keycode, t_mlx *mlx);

/*		File Check			*/
void		check_file(char *argv);
int			open_file(char *argv);

/*			Parsing			*/
void		fill_list(char **result, t_map **map);
char		**parsing(int fd);

/*			Free			*/
void		free_char(char **result, int limit);
void		free_all(t_mlx *mlx, void *start, int i);
void		*ft_lst_clear(t_map *li);
int			ft_close(t_mlx *mlx);
void		*ft_free(char *str);

#endif