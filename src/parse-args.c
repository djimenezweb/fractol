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

void	check_character(t_fractol *f, char c)
{
	if (c == 'M')
		f->mode = MANDELBROT;
	else if (c == 'J')
		f->mode = JULIA;
	else
		bad_arguments();
}

void	set_mode(t_fractol *f, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	if (i == 1)
		check_character(f, str[0]);
	else
	{
		if (!ft_strncmp(str, "MANDELBROT", i + 1))
			f->mode = MANDELBROT;
		else if (!ft_strncmp(str, "JULIA", i + 1))
			f->mode = JULIA;
		else
			bad_arguments();
	}
}

void	parse_args(t_fractol *f, int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
		bad_arguments();
	set_mode(f, argv[1]);
	if (f->mode == MANDELBROT)
	{
		if (argc > 2)
			bad_arguments();
	}
	else if (f->mode == JULIA)
	{
		if (!argv[2])
			f->c = init_complex(-0.5125, 0.5213);
		else if (argv[2] && !argv[3])
			f->c = init_complex(ft_atod(argv[2]), ft_atod(argv[2]));
		else
			f->c = init_complex(ft_atod(argv[2]), ft_atod(argv[3]));
	}
	else
		bad_arguments();
}
