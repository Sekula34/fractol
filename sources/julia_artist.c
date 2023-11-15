/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_artist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:20:51 by fseles            #+#    #+#             */
/*   Updated: 2023/11/15 13:20:52 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/fractol.h"


static int is_true_j(t_pixel pixel, double r)
{
	double zx_pow;
	double zy_pow;
	double r_pow;
	int value;

	zx_pow = pixel.coordinate_x * pixel.coordinate_x;
	zy_pow = pixel.coordinate_y * pixel.coordinate_y;
	r_pow = r * r;
	value = 0;
	if(pixel.iteration < pixel.max_iteration)
		value = 1;
	if((zx_pow + zy_pow < r_pow) && value)
		return (1);
	return (0);

}

static void data_initilizatorj(t_pixel *pixel, int x, int y, t_fractol *data)
{
	if(pixel == NULL)
		return ;
	pixel->screen_x = x;
	pixel->screen_y = y;
	pixel->coordinate_x = get_x_from_widthx(x, data);
	pixel->coordinate_y = get_y_from_heighty(y, data);
	pixel->iteration = 0;
	pixel->max_iteration = MAX_ITERATION;
	data->julia_R = 2;
	pixel->xtemp = 0.0;
}

static void every_pixel_julia(int x, int y, t_fractol *data)
{
	t_pixel pixel;
	double x_pow;
	double y_pow;
	double zxzy;
	
	data_initilizatorj(&pixel, x, y, data);
	while (is_true_j(pixel, data->julia_R))
	{
		x_pow = pixel.coordinate_x * pixel.coordinate_x;
		y_pow = pixel.coordinate_y * pixel.coordinate_y;
		zxzy = pixel.coordinate_x * pixel.coordinate_y;
		pixel.xtemp = x_pow - y_pow;
		pixel.coordinate_y= 2*zxzy + data->julia_cy;
		pixel.coordinate_x = pixel.xtemp + data->julia_cx;
		pixel.iteration = pixel.iteration + 1;   
	}
	if(pixel.iteration  == pixel.max_iteration)
		my_mlx_pixel_put(&(data->img), x, y, 0x00000000);
	else
		my_mlx_pixel_put(&(data->img),x, y, (0x00A0A0A0/pixel.max_iteration) * pixel.iteration);
}

void julia_artist(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTHX)
	{
		y = 0;
		while (y < HEIGHTY)
		{
			every_pixel_julia(x, y, fractol);
			y++;
		}
		x++;
	}
}