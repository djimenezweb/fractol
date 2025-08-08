/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:51:40 by danielji          #+#    #+#             */
/*   Updated: 2025/08/08 09:41:17 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>

# define WIDTH	1920
# define HEIGHT	1080
# define ITERATIONS	10
# define BACKGROUND	0x009966

/* A structure to represent complex numbers:
- `r` for real part
- `i` for imaginary part */
typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_data;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

double	ft_abs(double n);
t_complex	quadratic_map(t_complex z, t_complex c);
int		is_mandelbrot_set(double r, double i);
void	print_mandelbrot(t_data *img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	print_sq_diagonal(t_data *img);
void	print_diagonal(t_data *img);
void	print_frame(t_data *img);
void	print_rectangle(t_data *img, int x_start, int y_start, int w, int h);
void	print_crosshair(t_data *img);
void	print_fill_rectangle(t_data *img, int x_start, int y_start, int w, int h);
void	print_circle(t_data *img, double x0, double y0, double r);

#endif