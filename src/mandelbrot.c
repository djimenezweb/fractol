/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:39 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 10:26:36 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"
#include <stdio.h>

/* Returns the absolute value of a double floating number `n` */
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
int	is_in_mandelbrot(double r, double i)
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
			//printf("%f,%f escapes at %d\n", c.r, c.i, iter);
			//break ;
			return (iter);
		}
		//printf("%d: (%fr, %fi)\n", iter, z.r, z.i);
		iter++;
	}
	return (iter);
}

/* Checks whether a complex number `c` belongs to the
Julia set after a certain amount of iterations */
int	is_in_julia(t_complex z, double r, double i)
{
	int			iter;
	t_complex	c;

	iter = 0;
	c.r = r;
	c.i = i;
	while (iter < ITERATIONS)
	{
		z = quadratic_map(z, c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			//printf("%f,%f escapes at %d\n", c.r, c.i, iter);
			//break ;
			return (iter);
		}
		//printf("%d: (%fr, %fi)\n", iter, z.r, z.i);
		iter++;
	}
	return (iter);
}

void	print_mandelbrot(t_image *img)
{
	int		x;
	int		y;
	double	px;
	double	py;
	uint32_t	color;
	int		iter;

	x = 0;
	color = 0xffffff;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			px = img->x_min + (double)x * (img->x_max - img->x_min) / WIDTH;
			py = img->y_max + (double)y * (img->y_min - img->y_max) / HEIGHT;
			iter = is_in_mandelbrot(px, py);
			if (iter == 0 || iter == ITERATIONS)
				color = 0x000000;
			else
				color = ((uint8_t)(255 * (double)((double)iter / ITERATIONS)) * 0x010101);
			image_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

void	print_julia(t_image *img, double cr, double ci)
{
	int		x;
	int		y;
	double	px;
	double	py;
	uint32_t	color;
	int		iter;
	t_complex	initial;

	x = 0;
	color = 0xffffff;
	initial.r = cr;
	initial.i = ci;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			px = img->x_min + (double)x * (img->x_max - img->x_min) / WIDTH;
			py = img->y_max + (double)y * (img->y_min - img->y_max) / HEIGHT;
			iter = is_in_julia(initial, px, py);
			if (iter == 0 || iter == ITERATIONS)
				color = 0x000000;
			else
				color = ((uint8_t)(255 * (double)((double)iter / ITERATIONS)) * 0x010101);
			image_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}
