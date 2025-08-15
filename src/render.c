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

/* Checks whether a complex number `c` belongs to the
Mandelbrot or Julia set after a certain amount of iterations.
Returns number of iterations (escape time) */
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

/* - Initialices `z` to (0, 0) for Mandelbrot only
- Calls `fractal_iterations` according to the fractal mode
- Returns number of iterations or `0` on error */
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

/* - Substitutes `mlx_pixel_put` to put the pixel into an image buffer */
void	put_pixel_to_image(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_crosshair(t_fractol *f)
{
	int	x;
	int	y;
	int	color;

	x = (WIDTH / 2) - 12;
	y = (HEIGHT / 2) - 12;
	color = 0xffff00;
	while (x < (WIDTH / 2) + 12)
	{
		put_pixel_to_image(f, x, (HEIGHT / 2), color);
		x++;
	}
	while (y < (HEIGHT / 2) + 12)
	{
		put_pixel_to_image(f, (WIDTH / 2), y, color);
		y++;
	}
}

/* "Escape time" algorithm: A repeating calculation is performed for
each `x`, `y` point in the plot area and based on the behavior of 
that calculation, a color is chosen for that pixel.
- Calculates scale for current render
- Clears window to start from scratch
- Iterates through every pixel
- Calculates pixel to equilavent fractal set 
- Set the pixel color and puts it into image buffer
- Puts image buffer into window */
void	render_fractal(t_fractol *f)
{
	int			x;
	int			y;
	double		scale;
	t_complex	pixel;
	uint32_t	color;

	scale = (ft_abs(f->x.max) + ft_abs(f->x.min)) / WIDTH;
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			pixel.r = f->x.min + (double)x * scale;
			pixel.i = f->y.max - (double)y * scale;
			color = set_color(cnt_iterations(f, pixel));
			put_pixel_to_image(f, x, y, (int)color);
			y++;
		}
		x++;
	}
	print_crosshair(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, 0, 0);
}
