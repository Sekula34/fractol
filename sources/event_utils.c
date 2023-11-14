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

	if (option == 1)
	{
		new_x_diff = (data->coordinate_x_max - data->coordinate_x_min) * 0.9;
		new_y_diff = (data->coordinate_y_max - data->coordinate_y_min) * 0.9;
	}
	else
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
