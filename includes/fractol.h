/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:51:40 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 16:26:04 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>

# define WIDTH	1920
# define HEIGHT	1920
# define ITERATIONS	100
# define BACKGROUND	0x009966

/* A structure to represent complex numbers:
- `r` for real part
- `i` for imaginary part */
typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

typedef struct s_config
{
	void	*mlx_ptr;
	void	*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		ratio;
	double		scale;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		scale_x;
	double		scale_y;
}	t_config;

double	ft_abs(double n);
t_complex	quadratic_map(t_complex z, t_complex c);

void	initialize(t_config *c);
void	init_configuration(t_config *c);

void	free_and_exit(t_config *c, int status);
int		handle_input(int keysym, t_config *c);

int		is_in_mandelbrot(t_complex c);
void	print_mandelbrot(t_config *config);

void	image_pixel_put(t_config *image, int x, int y, int color);
void	print_crosshair(t_config *config);

#endif