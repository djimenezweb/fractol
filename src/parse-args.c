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

/* Shows help message and exits program */
void	bad_arguments(void)
{
	ft_printf("Run program with the following arguments:\n");
	ft_printf("./fractol M or Mandelbrot for Mandelbrot set\n");
	ft_printf("./fractol J or Julia for Julia set\n");
	ft_printf("  Suggested Julia parameters:\n");
	ft_printf("  -0.835   -0.2321    |    0     -0.8\n");
	ft_printf("  -0.8      0.156     |    0.285  0\n");
	ft_printf("  -0.70176 -0.3842    |    0.285  0.01\n");
	ft_printf("  -0.7269   0.1889    |    0.35\n");
	ft_printf("  -0.5125   0.5213    |    0.4\n");
	ft_printf("  -0.4      0.6       |   \n");
	ft_printf("Press Esc to exit program\n");
	exit(EXIT_FAILURE);
}

/* Sets fractal mode if a single character is passed, exits on error. */
void	check_character(t_fractol *f, char c)
{
	if (c == 'M')
		f->mode = MANDELBROT;
	else if (c == 'J')
		f->mode = JULIA;
	else
		bad_arguments();
}

/* Sets fractal mode if a string is passed, exits on error. */
void	check_string(t_fractol *f, char *str, int len)
{
	if (!ft_strncmp(str, "MANDELBROT", len))
		f->mode = MANDELBROT;
	else if (!ft_strncmp(str, "JULIA", len))
		f->mode = JULIA;
	else
		bad_arguments();
}

/* Converts argument to uppercase and sets fractal mode. */
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
		check_string(f, str, i + 1);
}

/* Validates argument count, sets fractal mode and
converts Julia arguments to `double`. */
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
