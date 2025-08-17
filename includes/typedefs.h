/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:03:01 by danielji          #+#    #+#             */
/*   Updated: 2025/08/17 11:04:56 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

/* A structure to represent complex numbers:
- `r` for real part
- `i` for imaginary part */
typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

/* A structure to represent an axis with `min` and `max` values */
typedef struct s_axis
{
	double	min;
	double	max;
}			t_axis;

/* A structure to hold Minilibx configuration and rendering values */
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
}				t_fractol;

#endif