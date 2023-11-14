/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:11:36 by fseles            #+#    #+#             */
/*   Updated: 2023/11/13 16:11:38 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

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
//if esc is pressed close program and free everything
//handle movememnt arrows and zooming with plus and minus
int	closef(int keycode, void *param)
{
	t_fractol *data;

	data = (t_fractol *)param;
	ft_printf("stisno sam tipku %d\n", keycode);
	if (keycode == 65307)
		closing_function(param);
	else if (keycode == 65451)
		zooming(data, 1, WIDTHX/2, HEIGHTY/2);
	else if (keycode == 65453)
		zooming(data, 2, WIDTHX/2, HEIGHTY/2);
	else if(keycode == 65364)
		moving_arr(data, 1);
	else if(keycode == 65362)
		moving_arr(data, 2);
	else if(keycode == 65363)
		moving_arr(data, 3);
	else if(keycode == 65361)
		moving_arr(data, 4);
	mandel_artist(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0 ,0 );
	return (1);
}

//get position of mouse
//scrolling up zooms and make position of mouse ceneter
// right click moves coordinate system (aka picture)
int mouse_cather(int button, int x, int y, void *param)
{
	t_fractol *data;

	data = (t_fractol *) param;
	if(button == 4)
		zooming(data, 1, x, y);
	if(button == 5)
		zooming(data, 2, x, y);
	if (button == 3)
	{
		zooming(data, 3, x, y);
	}
	mandel_artist(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

void	mandelbrot(void)
{
	t_fractol	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTHX, HEIGHTY,
			"Mandelbrot fractol set");
	data.img.img = mlx_new_image(data.mlx_ptr, WIDTHX, HEIGHTY);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.line_length, &data.img.endian);
	//my_mlx_pixel_put(&data.img, 100, 200, 0x00FF0000);
	data.coordinate_x_max = 1;
	data.coordinate_x_min = -2;
	data.coordinate_y_max = 1.25;
	data.coordinate_y_min = -1.25;
	mandel_artist(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img, 0, 0);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, closef, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, closing_function, &data);
	mlx_mouse_hook(data.win_ptr, mouse_cather, &data);
	//mlx_loop_hook(data.mlx_ptr, mandel_artist, &data);
	mlx_loop(data.mlx_ptr);
}
