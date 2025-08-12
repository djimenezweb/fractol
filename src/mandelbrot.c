/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:39 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 12:51:24 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

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

void	print_mandelbrot(t_config *config)
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
			px = config->x_min + (double)x * (config->x_max - config->x_min) / WIDTH;
			py = config->y_max + (double)y * (config->y_min - config->y_max) / HEIGHT;
			iter = is_in_mandelbrot(px, py);
			if (iter == 0 || iter == ITERATIONS)
				color = 0x000000;
			else
				color = ((uint8_t)(255 * (double)((double)iter / ITERATIONS)) * 0x010101);
			image_pixel_put(config, x, y, color);
			y++;
		}
		x++;
	}
}
