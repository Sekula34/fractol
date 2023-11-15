/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:46:46 by fseles            #+#    #+#             */
/*   Updated: 2023/11/15 11:46:47 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"


int closej(int keycode, void *param)
{
	t_fractol *data;

	data = (t_fractol *)param;
	if(keycode == 65307)
		closing_function(param);
	return (1);
}
void julia(int cx, int cy)
{
	t_fractol data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	data.win_ptr=mlx_new_window(data.mlx_ptr, WIDTHX, HEIGHTY,
			"Julia fractol set");
	data.img.img = mlx_new_image(data.mlx_ptr, WIDTHX, HEIGHTY);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
		&data.img.line_length, &data.img.endian);
	data.coordinate_x_max = 1;
	data.coordinate_x_min = -2;
	data.coordinate_y_max = 1.25;
	data.coordinate_y_min = -1.25;
	data.julia_cx = (double)(cx)/1000;
	data.julia_cy = (double)(cy)/1000;
	//julia_artist
	//putimage
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, closej, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, closing_function, &data);
	//mouse
	mlx_loop(data.mlx_ptr);
	
}