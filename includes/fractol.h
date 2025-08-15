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
# define SCROLL_DOWN 5
# define SCROLL_UP 4

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

/* color.c */

uint32_t	set_color(int i);

/* events.c */

void		move(t_axis *axis, int direction);
void		scale(t_fractol *f, double factor);
int			handle_key(int keysym, t_fractol *f);
int			handle_mouse(int e, int x, int y, t_fractol *f);
void		listen_events(t_fractol *f);

/* free.c */

int			close_window(t_fractol *f);
void		free_and_exit(t_fractol *f, int status);

/* initialization.c */

void		initialize(t_fractol *f);

/* parse-args.c */

void		bad_arguments(void);
void		set_mode(t_fractol *f, char *str);
void		parse_args(t_fractol *f, int argc, char *argv[]);

/* render.c */

int			fractal_iterations(t_complex z, t_complex c);
int			cnt_iterations(t_fractol *f, t_complex pixel);
void		put_pixel_to_image(t_fractol *f, int x, int y, int color);
void		render_fractal(t_fractol *f);

/* utils.c */

t_complex	init_complex(double r, double i);
t_axis		init_axis(double min, double max);
double		ft_abs(double n);
t_complex	quadratic_map(t_complex z, t_complex c);


#endif