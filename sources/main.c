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
	int set_value;
	set_value = input_handler(argc, argv);
	if (set_value == 1)
	{
		mandelbrot();
	}
	else if(set_value == 2)
	{
		//julia
	}
	ft_printf("Set is %d\n", set_value);
	return (0);
}
