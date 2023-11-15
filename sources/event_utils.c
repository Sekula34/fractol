/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:15:47 by fseles            #+#    #+#             */
/*   Updated: 2023/11/14 19:15:48 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

//function that takes fractoldata and option
//zoom in by 10% if option is 1,
//zoom out by 10% if option is else
//zooming is done by rescaling max and min x and y axis 
void zooming(t_fractol *data, int option, int x, int y)
{
	double new_x_diff;
	double new_y_diff;
	double x_center;
	double y_center;

	new_x_diff = (data->coordinate_x_max - data->coordinate_x_min);
	new_y_diff = (data->coordinate_y_max - data->coordinate_y_min);
	if (option == 1)
	{
		new_x_diff = (data->coordinate_x_max - data->coordinate_x_min) * 0.9;
		new_y_diff = (data->coordinate_y_max - data->coordinate_y_min) * 0.9;
	}
	else if(option == 2)
	{
		new_x_diff = (data->coordinate_x_max - data->coordinate_x_min) * 1.1;
		new_y_diff = (data->coordinate_y_max - data->coordinate_y_min) * 1.1;
	}
	x_center = get_x_from_widthx(x, data);
	y_center = get_y_from_heighty(y, data);
	data->coordinate_x_max = x_center + (new_x_diff / 2);
	data->coordinate_x_min = x_center - (new_x_diff / 2);
	data->coordinate_y_max = y_center + (new_y_diff / 2);
	data->coordinate_y_min = y_center - (new_y_diff / 2);
}

//destroy everything aka image,  window, display
//free  mlx_ptr
//call this function when esc or x is pressed
int	closing_function(void *param)
{
	t_fractol	*param1;

	param1 = (t_fractol *)param;
	mlx_destroy_image(param1->mlx_ptr, param1->img.img);
	mlx_destroy_window(param1->mlx_ptr, param1->win_ptr);
	mlx_destroy_display(param1->mlx_ptr);
	free(param1->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

//fucntion that depending od option moves coordinate system
//aka moving picture with arrrows
//1 up 2 down, 3 right 4 left
void moving_arr(t_fractol *data, int option)
{
	if(option == 1)
	{
		data->coordinate_y_max += 0.1;
		data->coordinate_y_min += 0.1;
	}
	else if(option == 2)
	{
		data->coordinate_y_max -= 0.1;
		data->coordinate_y_min -= 0.1;
	}
	else if(option == 3)
	{
		data->coordinate_x_max += 0.1;
		data->coordinate_x_min += 0.1;
	}
	else if(option == 4)
	{
		data->coordinate_x_max -= 0.1;
		data->coordinate_x_min -= 0.1;
	}
}
