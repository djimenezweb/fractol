/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:39 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 16:27:36 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

/* Checks whether a complex number `c` belongs to the
Mandelbrot set after a certain amount of iterations */
int	is_in_mandelbrot(t_complex c)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z.r = 0.0;
	z.i = 0.0;
	// JULIA:
	// z.r = r;
	// z.i = i;
	// c.r = -0.5125;
	// c.i = 0.5213;
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
	int			x;
	int			y;
	t_complex	pixel;
	uint32_t	color;
	int			iter;

	x = 0;
	color = 0xffffff;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			pixel.r = config->x_min + x * config->scale_x;
			pixel.i = config->y_max + y * config->scale_y;
			iter = is_in_mandelbrot(pixel);
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
