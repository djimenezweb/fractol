/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:01:21 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 20:04:00 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bad_arguments(void)
{
	ft_printf("TO DO: Bad arguments\n");
	exit(EXIT_FAILURE);
}

void	set_mode(t_fractol *f, char *argv[])
{
	if (argv[1][0] == 'M')
		f->mode = MANDELBROT;
	if (argv[1][0] == 'J')
	{
		f->mode = JULIA;
		f->c.r = ft_atod(argv[2]);
		if (!argv[3])
			f->c.i = ft_atod(argv[2]);
		else
			f->c.i = ft_atod(argv[3]);
	}
}

void	parse_args(t_fractol *f, int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
		bad_arguments();
	if (argv[1][0] != 'M' && argv[1][0] != 'J')
		bad_arguments();
	set_mode(f, argv);
}
