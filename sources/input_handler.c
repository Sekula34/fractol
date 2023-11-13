/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:06:19 by fseles            #+#    #+#             */
/*   Updated: 2023/11/13 12:06:20 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

//check if input is == to Mandelbrot or Julia
//return 0 if neither
//return 1 if Mandelbrot;
//return 2 if Julia;
static int is_name_correct(char *input)
{
	int cmp_value;
	
	cmp_value = ft_strncmp(input, "Mandelbrot", 10);
	if(cmp_value == 0)
		return (1);
	cmp_value = ft_strncmp(input, "Julia", 5);
	if(cmp_value == 0)
		return (2);
	return (0);
}

//check the number of arguments, if the input is not
//something like ./fractol Mandelbrot or ./fractol Julia
//exit program and print what are available parameters
void	input_handler(int argc, char *argv[])
{
	(void)(argv);
	if(argc < 2)
	{
		ft_putstr_fd("Program need the type of fractal to display" 
		"\nAvailable options are:\n\tMandelbrot \n\tJulia ",2);
		exit(EXIT_FAILURE);
	}
	if (is_name_correct(argv[1]) == 0)
	{
		ft_putstr_fd("Fractol set is not correct ", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd("name is correct", 1);
	}
}

