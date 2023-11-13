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


// closing_function()
// {

// }

int closef(int keycode, void *param)
{
	(void) *param;
	if (keycode == 65307)
	{
		//closing_function();
	}
	ft_printf("Stisnuta tipka : %d\n", keycode);
	return (1);
}

void	mandelbrot()
{
	t_conwin conn;
	t_image img;

	ft_printf("Uso sam ");
	conn.mlx_connection = mlx_init();
	conn.window_ptr = mlx_new_window(conn.mlx_connection, WIDTHX, HEIGHTY, "Prozor stare majke");
	img.img = mlx_new_image(conn.mlx_connection, WIDTHX, HEIGHTY);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(conn.mlx_connection, conn.window_ptr, img.img, 0, 0);
	mlx_hook(conn.window_ptr, KeyPress, KeyPressMask, closef, NULL);
	mlx_loop(conn.mlx_connection);

}