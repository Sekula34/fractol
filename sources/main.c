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
	input_handler(argc, argv);
	ft_printf("Set is %d\n", input_handler(argc, argv));
	return (0);
}
