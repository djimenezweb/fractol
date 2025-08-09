/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:51:40 by danielji          #+#    #+#             */
/*   Updated: 2025/08/09 10:18:16 by danielji         ###   ########.fr       */
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
# define ITERATIONS	30
# define BACKGROUND	0x009966

/* A structure to represent complex numbers:
- `r` for real part
- `i` for imaginary part */
typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

double	ft_abs(double n);
t_complex	quadratic_map(t_complex z, t_complex c);
int		is_in_mandelbrot(double r, double i);
void	print_mandelbrot(t_image *img, int scale);

void	image_pixel_put(t_image *image, int x, int y, int color);

void	print_sq_diagonal(t_image *img);
void	print_diagonal(t_image *img);
void	print_frame(t_image *img);
void	print_rectangle(t_image *img, int x_start, int y_start, int w, int h);
void	print_crosshair(t_image *img);
void	print_fill_rectangle(t_image *img, int x_start, int y_start, int w, int h);
void	print_circle(t_image *img, double x0, double y0, double r);

#endif