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
int	closef(int keycode, void *param)
{
	if (keycode == 65307)
		closing_function(param);
	return (1);
}

int mouse_cather(int button, int x, int y, void *param)
{
	(void) param;
	ft_printf("Stisno sam tikpku %d, pozicija misa je %d, %d\n", button, x, y);
	return (0);
}

void	mandelbrot(void)
{
	t_fractol	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTHX, HEIGHTY,
			"Prozor stare majke");
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
	mlx_loop(data.mlx_ptr);
}
