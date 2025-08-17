/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:51:40 by danielji          #+#    #+#             */
/*   Updated: 2025/08/17 11:05:30 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "macros.h"
# include "typedefs.h"
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>

/* events.c */

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
void		parse_character(t_fractol *f, char c);
void		parse_string(t_fractol *f, char *str, int len);
void		set_mode(t_fractol *f, char *str);
void		parse_args(t_fractol *f, int argc, char *argv[]);

/* render.c */

int			set_color(int i);
int			fractal_iterations(t_complex z, t_complex c);
int			cnt_iterations(t_fractol *f, t_complex pixel);
void		put_pixel_to_image(t_fractol *f, int x, int y, int color);
void		render_fractal(t_fractol *f);

/* transforms.c */

double		find_center(t_axis a);
void		scale(t_fractol *f, double magnification);
void		move(t_axis *axis, int direction);

/* utils.c */

t_complex	init_complex(double r, double i);
t_axis		init_axis(double min, double max);
t_complex	quadratic_map(t_complex z, t_complex c);

#endif