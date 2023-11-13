/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:59:06 by fseles            #+#    #+#             */
/*   Updated: 2023/11/13 11:59:07 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	main(int argc, char *argv[])
{
	int	set_value;

	set_value = input_handler(argc, argv);
	double valuex;
	valuex = get_x_from_widthx(184);
	printf("koordinata x je %f, a y je %f\n ", valuex, get_y_from_heighty(183));
	if (set_value == 1)
	{
		mandelbrot();
	}
	else if (set_value == 2)
	{
		//julia
	}
	ft_printf("Set is %d\n", set_value);
	return (0);
}
