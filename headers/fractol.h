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

# define HEIGHTY 480
# define WIDTHX 640
# define COORDINATE_X_MAX 2
# define COORDINATE_X_MIN -2
# define COORDINATE_Y_MAX 2
# define COORDINATE_Y_MIN -2

typedef struct s_data{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}	t_image;

typedef struct s_all_data{
	t_image	img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fractol;

int		input_handler(int argc, char *argv[]);
double	get_x_from_widthx(int screen_widthx);
double	get_y_from_heighty(int screen_heighty);
void	mandelbrot(void);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	set_coordinate_pos(int screen_widthx, int screen_heighty,
			double *x, double *y);

#endif
