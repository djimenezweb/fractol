/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:39 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 20:47:17 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_complex c)
{
	int	i;

	i = 0;
	while (i < ITERATIONS)
	{
		z = quadratic_map(z, c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
			return (i);
		i++;
	}
	return (i);
}

/* Checks whether a complex number `c` belongs to the
Mandelbrot set after a certain amount of iterations */
int	mandelbrot(t_complex c)
{
	int			i;
	t_complex	z;

	i = 0;
	z = init_complex(0.0, 0.0);
	while (i < ITERATIONS)
	{
		z = quadratic_map(z, c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
			return (i);
		i++;
	}
	return (i);
}

int	cnt_iterations(t_fractol *f, t_complex pixel)
{
	int	i;

	if (f->mode == 1)
		i = mandelbrot(pixel);
	if (f->mode == 2)
		i = julia(pixel, f->c);
	return (i);
}

void	render_fractal(t_fractol *f)
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
			pixel.r = f->x_min + x * f->scale_x;
			pixel.i = f->y_max + y * f->scale_y;
			iter = cnt_iterations(f, pixel);
			if (iter == 0 || iter == ITERATIONS)
				color = 0x000000;
			else
				color = ((uint8_t)(255 * (double)((double)iter / ITERATIONS)) * 0x010101);
			image_pixel_put(f, x, y, color);
			y++;
		}
		x++;
	}
}
