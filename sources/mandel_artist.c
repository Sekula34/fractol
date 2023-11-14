/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_artist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:10:33 by fseles            #+#    #+#             */
/*   Updated: 2023/11/14 11:10:35 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"


static void data_initializator(t_pixel *pixel, int x, int y)
{
	if (pixel == NULL)
		return ;
	pixel->screen_x = x;
	pixel->screen_y = y;
	pixel->coordinate_x = get_x_from_widthx(x);
	pixel->coordinate_y = get_y_from_heighty(y);
	pixel->iteration = 0;
	pixel->max_iteration = MAX_ITERATION;
	pixel->xtemp = 0.0;
	pixel->iterator_x = 0.0;
	pixel->iterator_y = 0.0;
	pixel->color.blue = 256;
	pixel->color.transparency = 00;
	pixel->color.red = 0;
	pixel->color.green = 0; 
}

static int is_true(t_pixel pixel)
{
	double x_pow;
	double y_pow;

	x_pow = pixel.iterator_x * pixel.iterator_x;
	y_pow = pixel.iterator_y * pixel.iterator_y;
	if((x_pow + y_pow <= 4) && (pixel.iteration < pixel.max_iteration))
		return (1);
	return(0);
}
static void every_pixel_function(int x, int y, t_fractol *data)
{
	t_pixel pixel;
	double	x_pow;
	double	y_pow;

	int color = 0x00FF0000;

	data_initializator(&pixel, x, y);
	while(is_true(pixel))
	{
		x_pow = pixel.iterator_x * pixel.iterator_x;
		y_pow = pixel.iterator_y * pixel.iterator_y;
		pixel.xtemp = x_pow - y_pow + pixel.coordinate_x;
		pixel.iterator_y = 2* pixel.iterator_x * pixel.iterator_y
				+ pixel.coordinate_y;
		pixel.iterator_x = pixel.xtemp;
		pixel.iteration++;
	}
	//pixel.color.transparency = pixel.iteration % 256;
	color = pixel.iteration;
	printf("data is %p\n", data);
	//my_mlx_pixel_put(data->img.img ,x, y, color);

}
//function that iterates throught every pixel on window screen and 
//call function on every pixel
void	mandel_artist(t_fractol *fractol)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(x <= WIDTHX)
	{
		y = 0;
		while (y <= HEIGHTY)
		{
			every_pixel_function(x, y, fractol);
			y++;
		}
		x++;
	}

}
