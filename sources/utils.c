/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:20:52 by fseles            #+#    #+#             */
/*   Updated: 2023/11/13 16:20:53 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
//set both x and y to be between coordinate max and min defined in header
//for example x will be between -2 and 2
//y fill be between -2 and 2;
void set_coordinate_pos(int screen_widthx, int screen_heighty, double *x, double *y)
{
	*x = (double)(screen_widthx/WIDTHX) * (COORDINATE_X_MAX - COORDINATE_X_MIN) + COORDINATE_X_MIN;
	*y = (double)(screen_heighty/HEIGHTY) *(COORDINATE_Y_MAX - COORDINATE_Y_MIN) + COORDINATE_Y_MIN;
}

//return x from screen pixel to be between coordinate max and coordinate min
//for example between -2 and 2 (if so defined in header) (depending od width)
double get_x_from_widthx(int screen_widthx)
{
	double x;

	x = (double)(screen_widthx/WIDTHX) * (COORDINATE_X_MAX - COORDINATE_X_MIN) + COORDINATE_X_MIN;
	return (x);
}

//return y from screen pixel to be between coordinate max and coordinate min
//for example between -2 and 2 (if so defined in header) (depending on height)
//480 becomes 2, 0 becomes -2, 240 is 1; 
double get_y_from_heighty(int screen_heighty)
{
	double y;
	y = (double)(screen_heighty/HEIGHTY) *(COORDINATE_Y_MAX - COORDINATE_Y_MIN) + COORDINATE_Y_MIN;
}
