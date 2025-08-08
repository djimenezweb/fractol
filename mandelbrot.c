/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:39 by danielji          #+#    #+#             */
/*   Updated: 2025/08/08 09:36:59 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"
#include <stdio.h>

/* Returns the absolute value of a double floating number */
double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/* Solves `f(z) = z² + c` and returns the result as a complex number */
t_complex	quadratic_map(t_complex z, t_complex c)
{
	t_complex	result;

	result.r = ((z.r * z.r) - (z.i * z.i)) + c.r;
	result.i = (2 * (z.r * z.i)) + c.i;
	return (result);
}

/* Checks whether a complex number `c` belongs to the
Mandelbrot set after a certain amount of iterations */
/* TO DO: Should return a value */
int	is_mandelbrot_set(double r, double i)
{
	int			iter;
	t_complex	z;
	t_complex	c;

	iter = 0;
	z.r = 0;
	z.i = 0;
	c.r = r;
	c.i = i;
	while (iter < ITERATIONS)
	{
		z = quadratic_map(z, c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			printf("%f,%f escapes at %d\n", c.r, c.i, iter);
			//break ;
			return (0);
		}
		printf("%d: (%fr, %fi)\n", iter, z.r, z.i);
		iter++;
	}
	return (iter);
}

void	print_mandelbrot(t_data *img)
{
	double	x;
	double	y;
	int		color;

	x = 0;
	color = 0x009966;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			if (is_mandelbrot_set(x, y) > 0)
				my_mlx_pixel_put(img, (int)x, (int)y, color);
			y++;
		}
		x++;
	}
}
