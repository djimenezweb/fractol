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

int	fractal_iterations(t_complex z, t_complex c)
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
int	cnt_iterations(t_fractol *f, t_complex pixel)
{
	t_complex	z;

	if (f->mode == MANDELBROT)
	{
		z = init_complex(0.0, 0.0);
		return (fractal_iterations(z, pixel));
	}
	if (f->mode == JULIA)
		return (fractal_iterations(pixel, f->c));
	return (0);
}

void	image_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render_fractal(t_fractol *f)
{
	int			i;
	int			x;
	int			y;
	t_complex	pixel;
	uint32_t	color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			pixel.r = f->x_min + x * f->scale_x;
			pixel.i = f->y_max + y * f->scale_y;
			i = cnt_iterations(f, pixel);
			color = set_color(i);
			image_pixel_put(f, x, y, (int)color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, 0, 0);
}
