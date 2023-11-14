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

//return x from screen pixel to be between coordinate max and coordinate min
//for example between -2 and 2 (if so defined in header) (depending od width)
double	get_x_from_widthx(int screen_widthx, t_fractol *data)
{
	double	x;
	double	x_factor;
	double	range;

	x_factor = ((double)(screen_widthx) / (double)(WIDTHX));
	range = data->coordinate_x_max - data->coordinate_x_min;
	x = x_factor * range + data->coordinate_x_min;
	return (x);
}

//return y from screen pixel to be between coordinate max and coordinate min
//for example between -2 and 2 (if so defined in header) (depending on height)
//480 becomes 2, 0 becomes -2, 240 is 1; 
double	get_y_from_heighty(int screen_heighty, t_fractol *data)
{
	double	y;
	double	y_factor;
	double range;

	y_factor = ((double)(screen_heighty) / (double)(HEIGHTY));
	range = data->coordinate_y_max - data->coordinate_y_min;
	y = y_factor * range + data->coordinate_y_min;
	return (y);
}
