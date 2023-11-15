/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:42:56 by fseles            #+#    #+#             */
/*   Updated: 2023/11/11 16:42:58 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <X11/X.h>
# include "../libft/libft.h"

# define HEIGHTY 1080
# define WIDTHX 1920
# define COORDINATE_X_MAX 0.75
# define COORDINATE_X_MIN -2
# define COORDINATE_Y_MAX 1.25
# define COORDINATE_Y_MIN -1.25
# define MAX_ITERATION 80

typedef struct s_data{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}	t_image;

typedef struct s_color
{
	int	transparency;
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_point
{
	t_color	color;
	double	coordinate_x;
	double	coordinate_y;
	double	iterator_x;
	double	iterator_y;
	double	xtemp;
	int		screen_x;
	int		screen_y;
	int		iteration;
	int		max_iteration;
}	t_pixel;

typedef struct s_all_data{
	t_image	img;
	double	coordinate_x_max;
	double	coordinate_x_min;
	double	coordinate_y_max;
	double	coordinate_y_min;
	double	julia_cx;
	double	julia_cy;
	double	julia_r;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fractol;

int		closing_function(void *param);
double	get_x_from_widthx(int screen_widthx, t_fractol *data);
double	get_y_from_heighty(int screen_heighty, t_fractol *data);
int		input_handler(int argc, char *argv[]);
int		input_handler_julia(int argc, char *argv[]);
void	julia(int cx, int cy);
void	julia_artist(t_fractol *fractol);
int		mandel_artist(t_fractol *fractol);
void	mandelbrot(void);
void	moving_arr(t_fractol *data, int option);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	zooming(t_fractol *data, int option, int x, int y);

#endif
