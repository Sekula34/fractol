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

//function that allocates!! 
//returning null if fails or lowercase version of input
static char	*get_lower_case(char *input)
{
	char	*lower_case;
	int		length;
	int		i;

	if (input == NULL)
		return (NULL);
	length = ft_strlen(input);
	lower_case = ft_calloc(length + 1, sizeof(char));
	if (lower_case == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		lower_case[i] = ft_tolower(input[i]);
		i++;
	}
	return (lower_case);
}

//check if input is == to Mandelbrot or Julia
//return 0 if neither
//return 1 if Mandelbrot;
//return 2 if Julia;
static int	is_name_correct(char *input)
{
	int		cmp_value;
	char	*lower_case_input;

	if (input == NULL)
		return (0);
	lower_case_input = get_lower_case(input);
	if (lower_case_input == NULL)
		return (0);
	cmp_value = ft_strncmp(lower_case_input, "mandelbrot", 10);
	if (cmp_value == 0)
		return (free(lower_case_input), 1);
	cmp_value = ft_strncmp(lower_case_input, "julia", 5);
	if (cmp_value == 0)
		return (free(lower_case_input), 2);
	return (free(lower_case_input), 0);
}

//check the number of arguments, if the input is not
//something like ./fractol Mandelbrot or ./fractol Julia
//exit program and print what are available parameters
//return 1 if set is Mandelbrot
//return 2 if set is Julia
int	input_handler(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr_fd("Program need the type of fractal to display"
			"\nAvailable options are:\n\tMandelbrot \n\tJulia ", 2);
		exit(EXIT_FAILURE);
	}
	if (is_name_correct(argv[1]) == 0)
	{
		ft_putstr_fd("Fractol set is not correct"
			"\nAvailable options are:\n\tMandelbrot \n\tJulia ", 2);
		exit(EXIT_FAILURE);
	}
	return (is_name_correct(argv[1]));
}

int	input_handler_julia(int argc, char *argv[])
{
	(void) argv;
	if (argc != 4)
	{
		ft_putstr_fd("If you want Julia set you need to specify constant cx"
			" and cy, example julia -800  156\n", 2);
		exit(EXIT_FAILURE);
	}
	return (1);
}
