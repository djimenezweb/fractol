/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:51:40 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 20:47:42 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>

# define WIDTH	1024
# define HEIGHT	1024
# define ITERATIONS	64
# define MANDELBROT	1
# define JULIA	2
# define BACKGROUND	0x000054
# define BLACK 0x000000
# define WHITE 0xffffff

/* A structure to represent complex numbers:
- `r` for real part
- `i` for imaginary part */
typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

typedef struct s_axis
{
	double	min;
	double	max;
}			t_axis;

/* bpp = bits_per_pixel */
typedef struct s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			mode;
	t_complex	c;
	t_axis		x;
	t_axis		y;
}			t_fractol;

double		ft_abs(double n);
t_complex	quadratic_map(t_complex z, t_complex c);
t_complex	init_complex(double r, double i);
t_axis		init_axis(double min, double max);
void		initialize(t_fractol *f);
void		init_configuration(t_fractol *f);
void		set_mode(t_fractol *f, char *argv[]);
void		parse_args(t_fractol *f, int argc, char *argv[]);
void		free_and_exit(t_fractol *f, int status);
int			handle_key(int keysym, t_fractol *f);
int			handle_mouse(int e, int x, int y, t_fractol *f);
void		listen_events(t_fractol *f);
int			cnt_iterations(t_fractol *f, t_complex pixel);
void		render_fractal(t_fractol *f);
void		image_pixel_put(t_fractol *f, int x, int y, int color);
uint32_t	set_color(int i);

#endif